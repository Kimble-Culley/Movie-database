CC = g++
CFLAGS = -g -Wall -Wextra

default: Movie

Movie: library.o main.o
	$(CC) $(CFLAGS) -o Movie library.o main.o

library.o: library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp

main.o: main.cpp library.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) library *.o *~
