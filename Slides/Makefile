# Makefile - para presentaciones

CC	= clang
CFLAGS	= -std=c17 -D_DEFAULT_SOURCE -O2 -Wall
LDFLAGS =

SLIDES = 00-presentacion \
	 01-asintoticas \
	 02-propagacion-errores \
	 03-aproximar-ceros \
	 04-analisis-convergencia \
	 05-interpolacion \
	 06-cuadratura \
	 07-cuadratura-gauss \
	 08-resumen \
	 09-algoritmos-combinatorios \
	 10-adversario \
	 11-recorrer-grafos \
	 12-backtracking \
	 13-branch-and-bound \
	 14-Astar \
	 15-algoritmos-voraces \
	 16-voraces-clasicos \
	 17-dp \
	 18-dividir-y-conquistar \
	 19-quicksort \
	 20-probabilidades \
	 21-hashing \
	 22-hashing-open \
	 23-randomized \
	 24-load-balance \
	 25-sqrt-mod-p \
	 26-rsync \
	 27-Ramsey \
	 28-approximate \
	 29-resumen

EXTS	= aux bbl blg dvi log nav out snm toc vrb \
	  fls fdb_latexmk


all: README.pdf $(SLIDES)

README.pdf: README.md
	pandoc --variable=colorlinks:TRUE README.md -o README.pdf

02-propagacion-errores.pdf 02-propagacion-errores-hnd.pdf: \
    poly.c plot.pdf

03-aproximar-ceros.pdf 03-aproximar-ceros-hnd.pdf: \
    bisection.c newton.c secant.c fpi.c

05-interpolacion.pdf 05-interpolacion-hnd.pdf: \
    runge.dat omega.dat chebyshev.dat chebyshev-s.dat

06-cuadratura.pdf 06-cuadratura-hnd.pdf: \
    rectangles.pdf midpoints.pdf trapezoids.pdf quadratic.pdf

09-algoritmos-combinatorios.pdf 09-algoritmos-combinatorios-hnd.pdf: \
    maximum.c

11-backtracking.pdf 11-backtracking-hnd.pdf: \
    permutations-library.py permutations.py \
    graceful-generate-filter.py graceful.py \
    8queens

13-branch-and-bound.pdf 13-branch-and-bound-hnd.pdf: \
    knapsack.cc

17-dp.pdf 17-dp-hnd.pdf: \
    fibonacci-recursive.c \
    fibonacci-memoized.c \
    fibonacci-dp.c \
    fibonacci-dp-frugal.c \
    beer-driver.c \
    beer-recursive.c \
    beer-dp.c \
    beer-select.c

run-bisection: bisection.o testcases.o
	$(CC) $(LDFLAGS) -o $@ $^ -lm

run-fpi: fpi.o
	$(CC) $(LDFLAGS) -o $@ $^ -lm

run-newton: newton.o testcases.o
	$(CC) $(LDFLAGS) -o $@ $^ -lm

run-secant: secant.o testcases.o
	$(CC) $(LDFLAGS) -o $@ $^ -lm

bisection.o newton.o secant.o testcases.o: testcases.h

fibonacci: fibonacci-recursive \
	   fibonacci-memoized \
	   fibonacci-dp \
	   fibonacci-dp-frugal

beer: beer-recursive beer-dp beer-select


plot.pdf: plot.gp values
	gnuplot -e 'set terminal pdfcairo; set output'	$< > $@

rectangles.pdf midpoints.pdf trapezoids.pdf quadratic.pdf: plot.py
	./plot.py

values: poly
	./poly > $@

poly: poly.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

%.dat: %.py
	./$< > $@

fibonacci-%: fibonacci-driver.o fibonacci-%.o
	$(CC) $(LDFLAGS) -o $@ $^

fibonacci-driver.o: fibonacci.h
fibonacci-recursive.o: fibonacci.h
fibonacci-memoized.o: fibonacci.h
fibonacci-dp.o: fibonacci.h
fibonacci-dp-frugal.o: fibonacci.h

beer-%: beer-driver.o beer-%.o
	$(CC) $(LDFLAGS) -o $@ $^

beer-driver.o: beer.h
beer-recursive.o: beer.h
beer-dp.o: beer.h

beer-select: beer-select.c
	$(CC) $(LDFLAGS) -o $@ $^

run-hash: run-hash.o hashing.o ElfHash.o
	$(CC) $(LDFLAGS) -o $@ $^

run-hash.o: hashing.h
hashing.o: hashing.h ElfHash.h
ElfHash.o: ElfHash.h

reformat:
	clang-format -i *.c *.h

clean:
	rm -f *~ *.bak _region_.*
	rm -f README.pdf
	rm -f $(foreach EXT,$(EXTS),\
		   $(SLIDES:=.$(EXT)) $(SLIDES:=-hnd.$(EXT)))
	rm -f rectangles.pdf midpoints.pdf trapezoids.pdf quadratic.pdf
	rm -f poly values plot.png
	rm -f testcases.o \
	      bisection.o newton.o secant.o fpi.o \
              run-bisection run-newton run-secant run-fpí
	rm -f run-hash.o hashing.o ElfHash.o \
	      run-hash
	rm -f *.dat
	rm -f $(foreach S,recursive memoized dp dp-frugal,\
		  fibonacci-$(S) fibonacci-$(S).o)
	rm -f fibonacci-driver.o
	rm -f $(foreach S,recursive dp,\
		  beer-$(S) beer-$(S).o)
	rm -f beer-driver.o
	rm -f beer-select.o beer-select

clobber: clean
	rm -f $(SLIDES:=.pdf) $(SLIDES:=-hnd.pdf) $(SLIDES:=-2x3.pdf)

.PHONY: all reformat clean clobber $(SLIDES)

$(SLIDES): %: %.pdf %-hnd.pdf %-2x3.pdf

%.pdf: %.tex
	latexmk -pdf $<

%-hnd.tex: %.tex
	@rm -f $@
	sed -e 's;^%, handout%$$;, handout%;' $< > $@

%-2x3.pdf: %-hnd.pdf
	pdfjam --nup 2x3 --suffix 2x3 \
	       --no-landscape --frame true --delta "5pt 5pt" \
	       --scale 0.95 $< -o $@
