CC = gcc
CFLAGS = -ansi -Wall -Wpedantic
DEBUG = off

ifneq ($(DEBUG), off)
	CFLAGS += -g
else
	CFLAGS += -O2
endif

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DROP = $(patsubst %.c, %, $(SRCS))

all: $(DROP) 

$(DROP): %: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY:
clean:
	rm -f $(OBJS) 
