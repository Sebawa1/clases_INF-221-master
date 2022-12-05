##
# @file Makefile
# @brief Tests for max-sum, max-min; Pike's match

CC	= clang
CXX	= clang++
CFLAGS	= -O2 -Wall -g
CXXFLAGS= -std=c++20 -O2 -Wall -g

MAXSUM	= $(foreach I,1 2 3 4 5,tst-max-sum-$I)
MAXMIN  = tst-maxmin tst-maxmin-dc tst-maxmin-opt
HDRS	= max-sum.h max-min.h match.h
SRCMS	= $(foreach I,1 2 3 4 5,max-sum-$I.c)
SRCMM   = max-min.c max-min-dc.c max-min-opt.c
OBJMS	= $(SRCMS:.c=.o)
OBJMM	= $(SRCMM:.c=.o)

all: $(MAXSUM) $(MAXMIN) sgrep Roessle Warnsdorf

tst-max-sum-%: drive-max-sum.o max-sum-%.o
	$(CC) $(CFLAGS) -o $@ $^

drive-max-sum.o: max-sum.h
$(OBJMS): max-sum.h

tst-maxmin.o: max-min.h
$(OBJMM): max-min.h

tst-maxmin: tst-maxmin.o max-min.o
	$(CC) $(CFLAGS) -o $@ $^

tst-maxmin-dc: tst-maxmin.o max-min-dc.o
	$(CC) $(CFLAGS) -o $@ $^

tst-maxmin-opt: tst-maxmin.o max-min-opt.o
	$(CC) $(CFLAGS) -o $@ $^

sgrep: sgrep.o match.o
	$(CC) $(LDFLAGS) -o $@ $^

Roessle: Roessle.o
	$(CXX) $(LDFLAGS) -o $@ $^

Warnsdorf: Warnsdorf.o
	$(CXX) $(LDFLAGS) -o $@ $^


sgrep.o: match.h

match.o: match.h

Roessle.o:

Warnsdorf.o:

reformat:
	clang-format -i $(SRCS) $(HDRS) snapl.cc

clean:
	rm -f drive-max-sum.o $(OBJMS) $(OBJMM)
	rm -f sgrep.o match.o

clobber: clean
	rm -f $(MAXSUM) $(MAXMIN) sgrep

.PHONY: all reformat clean clobber
