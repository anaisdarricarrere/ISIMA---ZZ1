# compilateur
CC = gcc
# options
CFLAGS = -Wall -Wextra -g
LDFLAGS = 
# liste des fichiers objets
OBJ = TP1.o Lch.o Main.o
# règle de production finale tp :

TP1 : $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o TP1  
	@echo "Lancer le programme avec ./TP1"

# règle de production pour chaque fichier
TP1.o : TP1.h Lch.h TP1.c
	$(CC) -c TP1.c $(CFLAGS)
Lch.o : Lch.h Lch.c
	$(CC) -c Lch.c $(CFLAGS)
Main.o : TP1.h Lch.h TP1.c Lch.c
	$(CC) -c Main.c $(CFLAGS)

# règle de supression des fichier de travail
clean :
	rm -f $(OBJ)	
