CC = gcc
OBJS = Main.o Arbre.o Pile.o
ARGS = -Wextra -Wall -g
EXE = TP3

all : $(EXE)

$(EXE) : $(OBJS)
	$(CC) -o $(EXE) $(OBJS)
	@echo "Lancer le programme avec ./TP3"

%.o : %.c
	$(CC) -c $< $(ARGS)

clean :
	rm *.o
	rm TP3
