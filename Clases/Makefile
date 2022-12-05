# Makefile
#
# Copyright (c) 2020 Horst H. von Brand
# Bajo licencia MIT. Vea LICENSE-MIT para detalles

MAINS	:= INF-221_notas.tex bibliografia.tex

SOURCES := $(wildcard */*.tex)
CODE	:= $(wildcard code/*.c) code/8queens
BIBLIOGRAPHIES := $(wildcard *.bib)

ALL	+= $(MAINS:.tex=.pdf)
INPUTS	+= $(SOURCES) $(BIBLIOGRAPHIES)
IMAGES	+=
CLEAN	+= $(SOURCES:.tex=.aux) $(SOURCES:.tex=.bbl) $(SOURCES:.tex=.blg) \
   $(MAINS:.tex=.aux) $(MAINS:.tex=.log) $(MAINS:.tex=.out) \
   $(MAINS:.tex=.bbl) $(MAINS:.tex=.blg) $(MAINS:.tex=.idx) \
   $(MAINS:.tex=.ilg) $(MAINS:.tex=.ind) $(MAINS:.tex=.gls) \
   $(MAINS:.tex=.glo) $(MAINS:.tex=.loa) $(MAINS:.tex=.lof) \
   $(MAINS:.tex=.lol) $(MAINS:.tex=.lot) $(MAINS:.tex=.toc) \
   CREDITS.xml README.xml
CLOBBER += $(MAINS:.tex=.pdf) \
   bibliografia.pdf \
   CREDITS.pdf CREDITS.html README.pdf README.html \
   CLASS-VERSION-FILE class-version.tex
   
class-version-tex:
	./CLASS-VERSION-GEN

all: $(ALL)

credits: CREDITS.pdf CREDITS.html

CREDITS.pdf: CREDITS
	asciidoc -b docbook CREDITS
	xmlto pdf CREDITS.xml

CREDITS.html: CREDITS
	asciidoc CREDITS

include images/images.mk

INF-221_notas.pdf: INF-221_notas.tex class-version.tex \
                     $(INPUTS) $(CODE) $(IMAGES)
	pdflatex $<
	-for c in *; do \
	   if [ -d $c]; then \
	     (cd $$c; grep -s '\\bibliographystyle' $$c.tex && \
		    BIBINPUTS=.. bibtex $$c); \
	   fi; \
	done
	pdflatex $<
	pdflatex $<

%-2x1.pdf: %.pdf
	pdfjam --nup 2x1 --suffix 2x1 \
               --landscape --frame true --delta "5pt 5pt" \
               --scale 0.95 $< -o $@

bibliografia.pdf: bibliografia.tex class-version.tex $(BIBLIOGRAPHIES)
	pdflatex $<
	BIBINPUTS=. bibtex $(basename $<)
	pdflatex $<
	pdflatex $<

indent:
	indent code/*.c code/*.h code/*.cc

clean:
	rm -f $(CLEAN)

clobber: clean
	rm -f $(CLOBBER)

.PHONY: all credits indent clean clobber
