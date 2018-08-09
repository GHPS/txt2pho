CC=/usr/bin/g++
CCC=/usr/bin/gcc
CFLAGS=-g -ansi
SRCPATH=src
HADIPATH=/home/tpo/hadifix
INCLUDE=-I$(SRCPATH) -I$(HADIPATH)/src
LDFLAGS=-g -L$(HADIPATH) 
LOADLIBS=-lm -lhadi
OBJPATH=obj
DEFINES=-DSTATISTICS -DBORDERPROS -DNEWTREE -DNO_FILES -DNOWINMOD -DUNIX -DPHONDURNET -DLOWBORDERTONE -DIPHONDURNET -DLINUX -DGCC28 

PPOBJECTS=$(OBJPATH)/PPAbblst.o \
$(OBJPATH)/PPCConte.o \
$(OBJPATH)/PPCStrin.o \
$(OBJPATH)/PPCtglst.o \
$(OBJPATH)/PPCtgstr.o \
$(OBJPATH)/PPFnclst.o \
$(OBJPATH)/PPFuncts.o \
$(OBJPATH)/PPInput.o \
$(OBJPATH)/PPMain.o \
$(OBJPATH)/PPRlchls.o \
$(OBJPATH)/PPRulchr.o \
$(OBJPATH)/PPRule.o \
$(OBJPATH)/PPRullst.o 

OBJECTS=$(OBJPATH)/cns.o \
$(PPOBJECTS) \
$(OBJPATH)/conc.o \
$(OBJPATH)/dac2.o \
$(OBJPATH)/durint.o \
$(OBJPATH)/environ.o \
$(OBJPATH)/filetool.o \
$(OBJPATH)/hannwin.o \
$(OBJPATH)/invent.o \
$(OBJPATH)/prosody.o \
$(OBJPATH)/prostree.o \
$(OBJPATH)/relp.o \
$(OBJPATH)/sound.o \
$(OBJPATH)/syllable.o \
$(OBJPATH)/syndata.o \
$(OBJPATH)/uli.o \
$(OBJPATH)/dialect.o \
$(OBJPATH)/unit.o \
$(OBJPATH)/nn.o \
$(OBJPATH)/ascii.o \
$(OBJPATH)/file.o \
$(OBJPATH)/flexion.o \
$(OBJPATH)/hposttra.o \
$(OBJPATH)/ipa.o \
$(OBJPATH)/lexem.o \
$(OBJPATH)/lexemnod.o \
$(OBJPATH)/lexicon.o \
$(OBJPATH)/ptrax.o \
$(OBJPATH)/vv.o \
$(OBJPATH)/newtable.o \
$(OBJPATH)/impwords.o \
$(OBJPATH)/phdurnn.o \
$(OBJPATH)/tsr.o \
$(OBJPATH)/vokale.o \
$(OBJPATH)/konsonanten.o \
$(OBJPATH)/a.o \
$(OBJPATH)/oe.o \
$(OBJPATH)/oo.o \
$(OBJPATH)/aa.o \
$(OBJPATH)/i.o \
$(OBJPATH)/oeh.o \
$(OBJPATH)/oy.o \
$(OBJPATH)/y.o \
$(OBJPATH)/schwa.o \
$(OBJPATH)/f.o \
$(OBJPATH)/h.o \
$(OBJPATH)/j.o \
$(OBJPATH)/n.o \
$(OBJPATH)/r.o \
$(OBJPATH)/vokr.o \
$(OBJPATH)/z.o \
$(OBJPATH)/promguess.o \
$(OBJPATH)/wrdclass.o \
$(OBJPATH)/sdb.o \
$(OBJPATH)/hadidll.o 


$(OBJPATH)/%.o		:  $(SRCPATH)/%.cc
	 $(CC) $(INCLUDE) $(CFLAGS) $(DEFINES) -o $@ -c $<


$(OBJPATH)/%.o		:  $(SRCPATH)/%.c
	 $(CCC) $(INCLUDE) $(CFLAGS) $(DEFINES) -o $@ -c $<


all		:	hadifix syswatch txt2pho twhadi preproc
hadifix		:	$(OBJPATH)/hadimain.o libhadi
	$(CC) $(LDFLAGS) -static -o hadifix $(OBJPATH)/hadimain.o $(LOADLIBS)

txt2pho		:	$(OBJPATH)/txt2pho.o libhadi
	$(CC) $(LDFLAGS) -static -o txt2pho $(OBJPATH)/txt2pho.o $(LOADLIBS)

syswatch		:	$(OBJPATH)/syswatch.o libhadi
	$(CC) $(LDFLAGS) -o syswatch $(OBJPATH)/syswatch.o $(LOADLIBS)

twhadi			:	$(OBJPATH)/twhadi.o $(OBJPATH)/tags.o libhadi
	$(CC) $(LDFLAGS) -static -o twhadi $(OBJPATH)/twhadi.o $(OBJPATH)/tags.o $(LOADLIBS)
	strip twhadi




preproc		:	$(PPOBJECTS) $(OBJPATH)/preproc.o
	$(CC) $(LDFLAGS) -o preproc $(PPOBJECTS) $(OBJPATH)/preproc.o $(LOADLIBS)
	mv preproc /apps/bin




libhadi			:       $(OBJECTS) $(OBJPATH)/libhadi.o
	ar -r libhadi.a $(OBJECTS) $(OBJPATH)/libhadi.o

clean	 	:
	rm -f $(OBJPATH)/*.o $(OBJPATH)/*.a







