# Simple Makefile for the lcc frontend.

ifndef SDCCLIB
SDCCLIB = /home/michaelh/projects/gbdk-current/
endif

CC = $(TNP)gcc
CFLAGS = -ggdb -O -Wall -DGBDKLIBDIR=\"$(SDCCLIB)\"
OBJ = lcc.o gb.o
BIN = lcc

all: $(BIN)

$(BIN): $(OBJ)

clean:
	rm -f *.o $(BIN) *~
