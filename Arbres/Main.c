/*----------------------------------------------------------------------------------------------*/
/*							TP2 - Gestion d'un dictionnaire arborescent							*/
/*												Main.c  										*/
/*----------------------------------------------------------------------------------------------*/

#include "Pile.h"
#include "Arbre.h"

int main()
{
    cellule_t * t = NULL;
    cellule_t * t_vide = NULL;
    cellule_t * t_inex = NULL;

    // Création d'un arbre à partir d'un fichier vide :
    LECTURE("vide.txt", &t_vide);
    //Création d'un arbre à partir d'un fichier inexistant :
    LECTURE("inexistant.txt", &t_inex);
    // Création d'un arbre à partir d'un fichier non vide :
    LECTURE("dico.txt", &t);

    // Affichage des mots d'un dictionnaire vide :
    printf("Mots d'un dictionnaire vide : \n");
    AFFICHAGE(&t_vide, "");
    printf("\n");
    // Affichage des mots d'un dictionnaire non vide :
    printf("Mots du dictionnaire non vide : \n");
    AFFICHAGE(&t, "");
    printf("\n");

    // Recherche de mots commençant par un motif présent dans l'arbre :
    printf("Mots commençant par 'ca' : \n");
    RECH_MOTIF(&t, "ca");
    printf("\n");
    // Recherche de mots commençant par un motif inexistant dans l'arbre :
    printf("Mots commençant par 'mo' : \n");
    RECH_MOTIF(&t, "mo");
    printf("\n");
    // Recherche de mots commençant par le motif vide :
    printf("Mots commençant par le motif vide : \n");
    RECH_MOTIF(&t, "");
    printf("\n");
    
    // Libération de l'arbre :
    SUPP_ARBRE(&t);

    return 0;
}


