CXX =		clang++
CXXFLAGS =	-std=c++17 -g -O2 -Wall
LD =		$(CXX)
LDFLAGS =	-g

all: tst-r tst-i tstdata

tst-r: tst.o grid.o blob-recursive.o
	$(LD) $(LDFLAGS) -o $@ $^

tst-i: tst.o grid.o blob-iterative.o
	$(LD) $(LDFLAGS) -o $@ $^

tst.o: grid.hh
grid.o: grid.hh
blob-recursive.o: grid.hh
blob-iterative.o: grid.hh

tstdata: 5.dat 10.dat 25.dat

%.dat: gen-grid.p6
	./gen-grid.p6 $*

clean:
	rm -f tst.o grid.o blob-recursive.o blob-iterative.o \
	      tst-r tst-i
	rm -f *.dat

.PHONY: all tstdata clean
