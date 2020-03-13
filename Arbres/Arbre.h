/*------------------------------------------------------------------------------------------------------*/
/*									TP2 - Gestion d'un dictionnaire arborescent							*/
/* 										Fichier d'entête Arbre.h										*/
/*																										*/
/* Déclaration des structures et des fonctions															*/
/*------------------------------------------------------------------------------------------------------*/

#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Pile.h"

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration de la structure cellule_t : cellule de l'arbre contenant :								*/
/*		lettre			caractère d'un mot																*/
/*		lv				lien vertical																	*/
/*		lh				lien horizontal																	*/
/*------------------------------------------------------------------------------------------------------*/

typedef struct cellule
{
	char lettre;
	struct cellule * lv, * lh;
}cellule_t;

/*------------------------------------------------------------------------------------------------------*/
/* Prototypes des fonctions		    																	*/
/*------------------------------------------------------------------------------------------------------*/

cellule_t ** RECH_PREC(cellule_t ** t, char * mot, int * prof);

cellule_t * CREER_CELL(char car);

void ADJ_CELL(cellule_t ** prec, cellule_t * nouv);

void INSERT(cellule_t ** t, char * mot);

int LECTURE(char * nom_fichier, cellule_t ** t);

void AFFICHAGE(cellule_t ** t, char * deb);

int RECH_MOTIF(cellule_t ** t, char * motif);

void SUPP_CELL (cellule_t ** prec);

void SUPP_ARBRE(cellule_t ** t);

#endif