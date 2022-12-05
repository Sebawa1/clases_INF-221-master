# Makefile -- for polynomial precision experiment

CC	= gcc
CFLAGS  = -g

all: poly-zero.pdf

poly-zero.pdf: poly-zero.tex plot.pdf
	pdflatex $<
	pdflatex $<

poly: poly.c
	$(CC) $(CFLAGS) -o $@ $<

values: poly
	./poly > $@

plot.pdf: plot.gp values
	gnuplot $< > $@

clean:
	rm -f poly values plot.pdf poly-zero.pdf
