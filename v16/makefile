CC = gcc
CFLAGS = -g -lncurses -lmenu -I$(IDIR) -D_LARGEFILE64_SOURCE -lSDL2 -lSDL2_mixer

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: rogue run clean

rogue:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rogue

clean:
	rm -f rogue

