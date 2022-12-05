# Makefile -- for coin changing

CC	= clang
CFLAGS	= -O2 -Wall -g

TEXT	= cambio-monedas.tex canonico.tex
PGM	= tst

all: $(TEXT:.tex=.pdf) $(PGM)

cambio-monedas.pdf: dp.c dp-2.c

canonico.pdf: canonico.c

tst: tst.o dp.o dp-2.o greedy.o
	$(CC) $(CFLAGS) -o $@ $^

tst.o: dp.h greedy.h
dp.o: dp.h
dp-2.o: dp.h
greedy.o: greedy.h

%.pdf: %.tex
	BIBINPUTS=../../Clases latexmk -pdf $<

clean:
	rm -f cambio-monedas.aux cambio-monedas.log cambio-monedas.out \
              cambio-monedas.fdb_latexmk cambio-monedas.fls
	rm -f canonico.aux canonico.log canonico.out \
              canonico.fdb_latexmk canonico.fls
	rm -f tst.o dp.o dp-2.o greedy.o
	rm -f *~
