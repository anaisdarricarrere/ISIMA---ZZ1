/*------------------------------------------------------------------------------------------------------*/
/*							        	TP4 - Gestion de table											*/
/* 								       	Fichier d'entête Lch.h											*/
/*																										*/
/* Déclaration des structures et prototypes des fonctions de gestion de listes chaînées	   				*/
/*------------------------------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration de la structure cellule_t : bloc de la liste chaînée contenant :							*/
/*		mot				Chaîne de caractère désignant le mot à traduire									*/
/*		trad			Chaîne de caractère désignant le mot traduit									*/
/*		suivant			Pointeur vers la cellule suivante												*/
/*------------------------------------------------------------------------------------------------------*/

typedef struct cellule
{
	char * mot, * trad;
	struct cellule * suivant;
}cellule_t;

/*------------------------------------------------------------------------------------------------------*/
/* Prototypes des fonctions		    																	*/
/*------------------------------------------------------------------------------------------------------*/

cellule_t * CREER_CELL(char * mot, char * trad);

void ADJ_CELL(cellule_t ** prec, cellule_t * nouv);

void INSERT_CELL(cellule_t * nouv, cellule_t ** t);

void SUPP_CELL(cellule_t ** prec);

void SUPP_LCH(cellule_t **t);
