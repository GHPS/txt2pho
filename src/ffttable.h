#ifndef __FFTTABLEH__
#define __FFTTABLEH

#ifndef M_PI
#define M_PI 3.14257
#endif


#ifndef MAX2
 #define MAX2(a,b) ((a>b)?a:b)
#endif

class t_FFTTable
{
private:
  float *Sinus[32];
  float *Cosinus[32];
  int   *Spieg[32];
  void create(short);
  int mtabbr2 (short, int *, float *, float *, short);
  unsigned long mbitrev (unsigned short ldn, unsigned long inval);
public:
  t_FFTTable();
  ~t_FFTTable();
  float *si(short i) { if (Sinus[i]==0)   create(i); return Sinus[i];   }
  float *co(short i) { if (Cosinus[i]==0) create(i); return Cosinus[i]; }
  int   *sp(short i) { if (Spieg[i]==0)   create(i); return Spieg[i];   }
};

void t_FFTTable::create(short i)
{
  Sinus[i] = new float [1<<i];
  Cosinus[i] = new float [1<<i];
  Spieg[i] = new int   [1<<i];
  mtabbr2 (i, Spieg[i], Cosinus[i], Sinus[i], 0);
}

t_FFTTable::t_FFTTable()
{
  for(int i=0; i<32; i++) {
    Sinus[i] = 0;
    Cosinus[i] = 0;
    Spieg[i] = 0;
  }
}

t_FFTTable::~t_FFTTable()
{
  for(int i=0; i<32; i++) {
    if(Sinus[i] != 0)
      delete [] Sinus[i];
    if(Cosinus[i] != 0)
      delete [] Cosinus[i];
    if(Spieg[i] != 0)
      delete [] Spieg[i];
  }
}
  
int t_FFTTable::mtabbr2 (short ldn, int *ispieg, float *co, float *si, short mode)
{
    register int    i, j, k, n, ldn2;
    register double x, y;

    ldn2 = MAX2((ldn-2), 1);
    n = 1 << ldn;

    if (mode <= 1) {
	x = (-2.0 * M_PI) / (t_Double) n;
	for (i=0, n>>=2; i<n; i++) {
	    j     = mbitrev (ldn2, i);
	    y     = x * (t_Double) i ;
	    si[j] = sin(y);
	    co[j] = cos(y);
	}
	n<<=1;
    }

    ldn--;
    ispieg[0] = 0;
    for (i=0, k=1; i<n; i++) {
	j = mbitrev (ldn, i);
	if (j>i) {
	    ispieg[k]   = i << 1;
	    ispieg[k+1] = j << 1;
	    ispieg[0]   = ++k;
	    k++;
	}
    }
    return (n<<1);
}

unsigned long t_FFTTable::mbitrev (unsigned short ldn, unsigned long inval)
{
    register unsigned long iu  = 0;
    register unsigned long iii = 1;
    register unsigned long i   = ldn;

    static unsigned long br [] = { // Powers of two
	0x0,       0x1,        0x2,        0x4,
	0x8,       0x10,       0x20,       0x40,
	0x80,      0x100,      0x200,      0x400,
	0x800,     0x1000,     0x2000,     0x4000,
	0x8000,    0x10000,    0x20000,    0x40000,
	0x80000,   0x100000,   0x200000,   0x400000,
	0x800000,  0x1000000,  0x2000000,  0x4000000,
	0x8000000, 0x10000000, 0x20000000, 0x40000000
    };

    while (i>0) {
	if ((inval&iii)>0)
	    iu = iu + br[i]; // Tabelliert ca. 30 % schneller als (1<<i) !!!
	iii += iii;
	i--;
    }

    return iu;
}

#endif






