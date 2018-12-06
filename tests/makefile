CC = gcc
CFLAGS = -g

SRC = ../src
SRCS = ../src/$(wildcard *.o)

$(warning $(SRCS))

TESTS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(TESTS))
PROGS = $(patsubst %.c, %, $(TESTS))

all: $(PROGS)

$(PROGS): $(OBJS) 
