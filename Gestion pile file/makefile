# compilateur
CC = gcc
# options
CFLAGS = -Wall -Wextra -g
LDFLAGS = 
# liste des fichiers objets
OBJ = File.o Pile.o Truc.o main.o
# règle de production finale tp :

TP2 : $(OBJ)
	$(CC) -o TP2 $(OBJ) $(LDFLAGS) -o TP2
	@echo "Lancer le programme avec ./TP2"

# règle de production pour chaque fichier
File.o : File.h File.c
	$(CC) -c File.c $(CFLAGS)
Pile.o : Pile.h Pile.c
	$(CC) -c Pile.c $(CFLAGS)
Truc.o : Truc.h Pile.h Truc.c
	$(CC) -c Truc.c $(CFLAGS)
