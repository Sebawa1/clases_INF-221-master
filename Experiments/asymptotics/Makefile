# Makefile - para presentaciones

CC	= clang
CFLAGS	= -O2 -Wall

SLIDES = asymptotics

EXTS	= aux bbl blg dvi log nav out snm toc vrb \
	  fls fdb_latexmk


all: $(SLIDES)

clean:
	rm -f *~ *.bak
	rm -f README.pdf
	rm -f $(foreach EXT,$(EXTS),\
		   $(SLIDES:=.$(EXT)) $(SLIDES:=-hnd.$(EXT)))
	rm -f poly values plot.png
	rm -f testcases.o \
	      bisection newton secant fpi
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

.PHONY: all clean clobber $(SLIDES)

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
