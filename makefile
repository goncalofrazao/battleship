PROJECT_NAME = wargame #target file name

CC = gcc #compiler
CFLAGS = -Wall -std=c11 -g  #-O3

OBJECTS = main.o restricoes.o pieces.o board.o help.o input_check.o modo_p.o modo_d.o #objects

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROJECT_NAME)

main.o: main.c

help.o: help.c help.h

restricoes.o: restricoes.c restricoes.h

pieces.o: pieces.c pieces.h

board.o: board.c board.h

input_check.o: input_check.c input_check.h

modo_p.o: modo_p.c modo_p.h

modo_d.o: modo_d.c modo_d.h

clean:
	rm -f $(PROJECT_NAME) *.o