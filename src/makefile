CC = gcc
CFLAGS = -ansi -Wall -Wpedantic -O2

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DROP = $(patsubst %.c, %, $(SRCS))

all: $(DROP) 

$(DROP): %: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY:
clean:
	rm -f $(OBJS) 
