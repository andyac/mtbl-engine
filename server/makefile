CC = g++
EX = mtbl 
CFLAGS = -O3 -ggdb -c -Wall
SRC = main.cpp Labyrinth.cpp
OBJ = $(SRC:.c=.o) 

$(EX): $(OBJ) 
	$(CC) -o $(EX) $(OBJ)
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f *.o $(EX)
