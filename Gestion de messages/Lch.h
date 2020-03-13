/*------------------------------------------------------------------------------------------------------*/
/*							        	TP1 - Gestion de messages										*/
/*                                                                                                      */
/* 								       	Fichier d'entête Lch.h											*/
/*																										*/
/* Déclaration des structures et prototypes des fonctions de gestion de listes chaînées	   				*/
/*------------------------------------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------------------------------------------*/
/* Déclaration de la structure cellule_t : bloc de la liste chaînée contenant :							*/
/*		deb_valid		date de début de validité du message (entier aaaammjj)							*/
/*		fin_valid		date de fin de validité du message (entier aaaammjj)							*/
/*		texte			texte du message (chaîne de caractères)											*/
/*		suivant			pointeur vers le bloc suivant													*/
/*------------------------------------------------------------------------------------------------------*/

typedef struct cellule
{
	int deb_valid, fin_valid;
	char * texte;
	struct cellule * suivant;
}cellule_t;

/*------------------------------------------------------------------------------------------------------*/
/* Prototypes des fonctions		    																	*/
/*------------------------------------------------------------------------------------------------------*/

cellule_t * CREER_CELL(int deb, int fin, char * texte);

cellule_t ** RECH_PREC(int date_deb, cellule_t ** t);

void ADJ_CELL(cellule_t ** prec, cellule_t * nouv);

void INSERT_CELL(cellule_t * nouv, cellule_t ** t);

void SUPP_CELL(cellule_t ** prec);

void SUPP_LCH(cellule_t **t);