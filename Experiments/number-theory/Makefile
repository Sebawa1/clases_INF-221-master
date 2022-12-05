# Makefile
#
# Copyright (c) 2020 Horst H. von Brand
# Bajo licencia MIT. Vea LICENSE-MIT para detalles

MAINS	:= raiz.tex tonelli-shanks.tex miller-rabin.tex

BIBLIOGRAPHIES := $(wildcard *.bib)

PDF	+= $(MAINS:.tex=.pdf)
NUP	+= $(MAINS:.tex=-2x1.pdf)
INPUTS	+= $(CLASSES) $(APXS) $(BIBLIOGRAPHIES)
IMAGES	+=
CLEAN	+= \
   $(MAINS:.tex=.aux) $(MAINS:.tex=.log) $(MAINS:.tex=.out) \
   $(MAINS:.tex=.bbl) $(MAINS:.tex=.blg) $(MAINS:.tex=.idx) \
   $(MAINS:.tex=.ilg) $(MAINS:.tex=.ind) $(MAINS:.tex=.gls) \
   $(MAINS:.tex=.glo) $(MAINS:.tex=.loa) $(MAINS:.tex=.lof) \
   $(MAINS:.tex=.lol) $(MAINS:.tex=.lot) $(MAINS:.tex=.toc)
CLEAN   += *~ *.bak _region_.*
CLOBBER += $(PDF) $(NUP)

all: $(PDF) $(NUP)

raiz.pdf: raiz.tex
	pdflatex $<
	pdflatex $<

%.pdf: %.tex ../../Clases/referencias.bib
	pdflatex $<
	BIBINPUTS=../../Clases bibtex $(basename $<)
	pdflatex $<
	pdflatex $<

%-2x1.pdf: %.pdf
	pdfjam --nup 2x1 --suffix 2x1 \
               --landscape --frame true --delta "5pt 5pt" \
               --scale 0.95 $< -o $@

clean:
	rm -f $(CLEAN)

clobber: clean
	rm -f $(CLOBBER)

.PHONY: all clean clobber
