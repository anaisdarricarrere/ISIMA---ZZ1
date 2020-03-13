/*------------------------------------------------------------------------------------------------------*/
/*									TP2 - Gestion d'une pile et d'une file								*/
/* 										Fichier d'entête Pile.h											*/
/*																										*/
/* Déclaration des structures et des fonctions															*/
/*------------------------------------------------------------------------------------------------------*/
#ifndef PILE_H
#define PILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbre.h"
#define NP 30				/* taille de la pile */

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration du type d'element contenu dans la pile													*/
/*------------------------------------------------------------------------------------------------------*/

struct cellule;
typedef struct cellule * element_pile;


/*------------------------------------------------------------------------------------------------------*/
/* Déclaration de la structure pile avec bloc de tête													*/
/*		taille_max		taille de la pile																*/
/*		rg_sommet		rang du sommet de la pile														*/
/*		ad_pile			pointeur sur la pile															*/
/*------------------------------------------------------------------------------------------------------*/

typedef struct pile
{
	int taille_max, rg_sommet;
	element_pile * ad_pile;
}pile_t;

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration des fonctions																			*/
/*------------------------------------------------------------------------------------------------------*/

pile_t * INIT_PILE (int N);

void LIBERER_PILE(pile_t * p);

int PILE_VIDE(pile_t * p);

int PILE_PLEINE(pile_t * p);

int EMPILER(pile_t* p, element_pile element);

element_pile DEPILER(pile_t *p);

element_pile SOMMET(pile_t *p);

void AFF_PILE(pile_t * p, char * deb);

#endif