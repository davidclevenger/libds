CC = gcc
CFLAGS = -g

SRC = ../src
SRCS = ../src/$(wildcard *.o)

TESTS = $(wildcard *.c)
PROGS = $(patsubst %.c, %, $(TESTS))

all: test_list

test_list: test_list.c
	$(CC) $(CFLAGS) -c test_list.c -I$(SRC)
	$(CC) $(CFLAGS) -o test_list test_list.o $(SRC)/list.o


.PHONY:
clean:
	rm -f *.o $(PROGS)
