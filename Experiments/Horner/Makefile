CC	= gcc
CFLAGS	= -O2 -Wall -g

all: tst-horner tst-newton

tst-horner: main-horner.o polynomials.o horner.o menu.o
	$(CC) $(CFLAGS) -o $@ $^

tst-newton: main-newton.o polynomials.o horner.o newton.o menu.o
	$(CC) $(CFLAGS) -o $@ $^

main-horner.o: polynomials.h horner.h menu.h

main-newton.o: polynomials.h horner.h newton.h menu.h

polynomials.o: polynomials.h

horner.o: horner.h

newton.o: newton.h

menu.o: menu.h

clean:
	rm -f main-horner.o main-newton.h \
             polynomials.o horner.o newton.o \
             menu.o
	rm -f *~

