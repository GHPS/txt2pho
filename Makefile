CC=/usr/bin/gcc
CPP=/usr/bin/g++

DEFINES=-DSTATISTICS -DBORDERPROS -DNEWTREE -DNO_FILES -DUNIX -DPHONDURNET -DLOWBORDERTONE -DIPHONDURNET
CFLAGS=-g -ansi -fsigned-char $(COPTIONS)
SRCPATH=src
PPSRCPATH=$(SRCPATH)/preproc
PPFLTSRCPATH=$(SRCPATH)/pipefilt
HADIPATH=.
INCLUDE=-I$(SRCPATH) -I$(HADIPATH)/src
LDFLAGS=-g -L$(HADIPATH) $(LDOPTIONS)
LOADLIBS=-lm lib/libhadi.a
OBJPATH=obj

PPOBJECTS=$(OBJPATH)/PPAbblst.o \
$(OBJPATH)/PPCConte.o \
$(OBJPATH)/PPCStrin.o \
$(OBJPATH)/PPCtglst.o \
$(OBJPATH)/PPCtgstr.o \
$(OBJPATH)/PPFnclst.o \
$(OBJPATH)/PPFuncts.o \
$(OBJPATH)/PPNumbers.o \
$(OBJPATH)/PPInput.o \
$(OBJPATH)/PPRlchls.o \
$(OBJPATH)/PPRulchr.o \
$(OBJPATH)/PPRule.o \
$(OBJPATH)/PPRullst.o 

OBJECTS=  $(OBJPATH)/environ.o \
$(OBJPATH)/filetool.o \
$(OBJPATH)/prosody.o \
$(OBJPATH)/prostree.o \
$(OBJPATH)/sound.o \
$(OBJPATH)/syllable.o \
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
$(OBJPATH)/synthese.o 



$(OBJPATH)/%.o		:  $(SRCPATH)/%.cc
	 $(CPP) $(INCLUDE) $(CFLAGS) $(DEFINES) -o $@ -c $<

$(OBJPATH)/%.o		:  $(SRCPATH)/%.c
	 $(CC) $(INCLUDE) $(CFLAGS) $(DEFINES) -o $@ -c $<

$(OBJPATH)/%.o		:  $(PPSRCPATH)/%.cc
	 $(CPP) $(INCLUDE) $(CFLAGS) $(DEFINES) -o $@ -c $<


all		:	txt2pho pipefilt preproc

txt2pho		:	$(OBJPATH)/txt2pho.o libhadi
	$(CPP) $(LDFLAGS) -o txt2pho $(OBJPATH)/txt2pho.o $(LOADLIBS)

libhadi			:       $(OBJECTS) #$(OBJPATH)/libhadi.o
	ar -c -r lib/libhadi.a $(OBJECTS) #$(OBJPATH)/libhadi.o 

preproc		:	$(PPOBJECTS) $(OBJPATH)/preproc.o
	$(CPP) $(LDFLAGS) -o preproc $(PPOBJECTS) $(OBJPATH)/preproc.o $(LOADLIBS)

pipefilt	:
	$(CPP) -o pipefilt $(CFLAGS) $(DEFINES) $(PPFLTSRCPATH)/*.cc 


clean	 	:
	rm -f $(OBJPATH)/*.o lib/*.a







