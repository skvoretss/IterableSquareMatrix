CFLAGS = -g -c -O2 -ftrapv -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wmissing-field-initializers -Wcast-qual -Wwrite-strings

all: p02

p02: main.o IterableSquareMatrix.o IterableSparseMatrix.o IterableDenseMatrix.o IteratorColumn.o IteratorRow.o Diameter.o BestNodes.o
	g++ main.o IterableSquareMatrix.o IterableSparseMatrix.o IterableDenseMatrix.o IteratorColumn.o IteratorRow.o Diameter.o BestNodes.o -o test_p02

main.o: main.cpp
	g++ $(CFLAGS) main.cpp

IterableSquareMatrix.o:
	g++ $(CFLAGS) IterableSquareMatrix.cpp

IterableSparseMatrix.o:
	g++ $(CFLAGS) IterableSparseMatrix.cpp -lm

IterableDenseMatrix.o:
	g++ $(CFLAGS) IterableDenseMatrix.cpp -lm

IteratorColumn.o:
	g++ $(CFLAGS) IteratorColumn.cpp -lm

IteratorRow.o:
	g++ $(CFLAGS) IteratorRow.cpp -lm

Diameter.o:
	g++ $(CFLAGS) Diameter.cpp -lm

BestNodes.o:
	g++ $(CFLAGS) BestNodes.cpp -lm

clean:
	rm -rf *.o p02
