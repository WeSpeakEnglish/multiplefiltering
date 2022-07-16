# Wedit Makefile for project The_filter
SRCDIR=j:\lcc_advance\lcc\projects\filter3
CFLAGS=-I"J:\LCC_ADVANCE\lcc\include"  -A  -z  -p6
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	multiple.obj \
	main.obj \

LIBS=
EXE=the_filter.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\the_filter.exe $(OBJS) $(LIBS)

# Build multiple.c
MULTIPLE_C=\
	J:\LCC_ADVANCE\lcc\include\stdio.h\
	J:\LCC_ADVANCE\lcc\include\safelib.h\
	J:\LCC_ADVANCE\lcc\include\_syslist.h\
	$(SRCDIR)\filter1.h\
	$(SRCDIR)\filter2.h\
	$(SRCDIR)\filter3.h\
	$(SRCDIR)\filter4.h\
	$(SRCDIR)\filter5.h\
	$(SRCDIR)\filter6.h\
	$(SRCDIR)\filter7.h\
	$(SRCDIR)\filter8.h\
	$(SRCDIR)\filter9.h\
	$(SRCDIR)\filter10.h\
	$(SRCDIR)\filter11.h\
	$(SRCDIR)\filter12.h\
	$(SRCDIR)\filter13.h\
	$(SRCDIR)\filter14.h\
	$(SRCDIR)\filter15.h\
	$(SRCDIR)\multiple.h\

multiple.obj: $(MULTIPLE_C) $(SRCDIR)\multiple.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\multiple.c

# Build main.c
MAIN_C=\
	J:\LCC_ADVANCE\lcc\include\stdio.h\
	J:\LCC_ADVANCE\lcc\include\safelib.h\
	J:\LCC_ADVANCE\lcc\include\_syslist.h\
	J:\LCC_ADVANCE\lcc\include\string.h\
	J:\LCC_ADVANCE\lcc\include\safelib.h\
	J:\LCC_ADVANCE\lcc\include\stdlib.h\
	J:\LCC_ADVANCE\lcc\include\stddef.h\
	J:\LCC_ADVANCE\lcc\include\_syslist.h\
	J:\LCC_ADVANCE\lcc\include\safelib.h\
	$(SRCDIR)\multiple.h\
	J:\LCC_ADVANCE\lcc\include\math.h\
	J:\LCC_ADVANCE\lcc\include\tgmath.h\

main.obj: $(MAIN_C) $(SRCDIR)\main.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\main.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\the_filter.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) the_filter.exe
