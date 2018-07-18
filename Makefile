CC = g++
CFLAGS = -g -Wall
SRCS = main.cpp
PROG = program

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

program: main.o
		$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

main.o: main.cpp
		$(CC) $(CFLAGS) -o main.o -c main.cpp $(LIBS)

clean:
		rm -f *.o
.PHONY: clean
