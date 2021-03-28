PROJECT_NAME = bin/wargame #target file name

CC = gcc #compiler
CFLAGS = -Wall -std=c11 -g  #-O3

OBJECTS = main.o restricoes.o pieces.o board.o help.o input_check.o #objects

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROJECT_NAME)

main.o: main.c headers.h restricoes.h pieces.h board.h help.h

help.o: help.c help.h headers.h

restricoes.o: restricoes.c restricoes.h headers.h

pieces.o: pieces.c pieces.h headers.h

board.o: board.c board.h headers.h

input_check.o: input_check.c input_check.h headers.h help.h

clean:
	rm -f $(PROJECT_NAME) *.o