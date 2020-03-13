/*------------------------------------------------------------------------------------------------------*/
/*									TP2 - Gestion d'une pile et d'une file								*/
/* 										Fichier d'entête File.h											*/
/*																										*/
/* Déclaration des structures et des fonctions															*/
/*------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NF 3

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration du type d'element contenu dans la file													*/
/*------------------------------------------------------------------------------------------------------*/

#define format "%d"
typedef int element_file ;

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration de la structure pile avec bloc de tête													*/
/*		taille_max		taille de la pile																*/
/*		rg_sommet		rang du sommet de la pile														*/
/*		ad_pile			pointeur sur  la pile															*/
/*------------------------------------------------------------------------------------------------------*/

typedef struct file
{
	int taille_max, compteur, rg_premier, rg_dernier;
	element_file * ad_file;
}file_t;

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration des fonctions de gestion de la file														*/
/*------------------------------------------------------------------------------------------------------*/

file_t * INIT_FILE (int N);

void LIBERER_FILE(file_t * f);

int FILE_VIDE(file_t * f);

int FILE_PLEINE(file_t * f);

int ENTREE(file_t * f, element_file element);

int SORTIE(file_t * f);
