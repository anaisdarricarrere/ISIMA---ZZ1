/*------------------------------------------------------------------------------------------------------*/
/*									TP2 - Gestion d'une pile et d'une file								*/
/* 									            	main.c						        				*/
/*------------------------------------------------------------------------------------------------------*/

#include "File.h"  
#include "Truc.h"

int main()
{
    int i;
    int T[3] = {3,9,2};

    // Test de la gestion de la pile
    printf("-Test de la gestion de la pile\n");
    printf("Creation d'une pile vide de taille 3 :\n");
    pile_t * p;
    p = INIT_PILE(NP);
    AFF_PILE(p);

    printf("Empilement de 3 éléments dans la pile :\n");
    EMPILER(p,6);
    AFF_PILE(p);
    EMPILER(p,7);
    AFF_PILE(p);
    EMPILER(p,8);
    AFF_PILE(p);

    printf("Empilement d'un element dans la pile pleine :\n");
    EMPILER(p,9);

    printf("Depilement des 3 elements dans la pile :\n");
    for (i=0; i<NP; i++)
    {
        printf("Element depile : "format" Pile :", DEPILER(p));
        AFF_PILE(p);
    }
    printf("Depilement dans la pile vide :\n");
    DEPILER(p);

    printf("\n");

    // Test de la gestion de la file
    printf("-Test de la gestion de la file\n");
    printf("Creation d'une pile vide de taille 3 : ");
    file_t * f;
	f = INIT_FILE(NF);
	AFF_FILE(f);

    printf("Entree de 3 elements en fin de la file :\n");
	ENTREE(f,5);
	AFF_FILE(f);
	ENTREE(f,3);
	AFF_FILE(f);
	ENTREE(f,7);
	AFF_FILE(f);

    printf("Entree d'un elements dans la file pleine : \n");
    ENTREE(f,1);

    printf("Services successifs des 3 elements dans la file : \n");
    for(i=0; i<NF; i++)
    {
        printf("Element servi : "format" File :", SORTIE(f));
        AFF_FILE(f);
    }
    printf("Service dans la file vide :\n");
    SORTIE(f);

    printf("\n");

    // Test de la fonction TRUC récursive
    printf("-Test de la fonction TRUC récursive :\n");
     TRUC_REC(0,3,T);

    printf("\n");

    // Test de la fonction TRUC itérative
    printf("-Test de la fonction TRUC itérative :\n");
    TRUC_ITER(0,3,T);

        
}