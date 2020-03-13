/*----------------------------------------------------------------------------------------------*/
/*									TP4 - Gestion de table										*/
/*										    Lch.c												*/
/*                                                                                              */
/*                                                                                              */
/* Fichier contenant le code des fonctions de gestions de listes chaînées                       */
/*----------------------------------------------------------------------------------------------*/

#include "Lch.h"

/*----------------------------------------------------------------------------------------------*/
/* CREER_CELL				Création d'une cellule de type cellule_t							*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Allouer un bloc de type cellule_t									*/
/*							- Si l'allocation est réussie :										*/
/*								- Copier les valeurs entrées en paramètre dans la				*/
/*							  	  nouvelle cellule 												*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : mot			Chaîne de caractère désignant le mot à traduire						*/
/*				trad		Chaîne de caractère désignant le mot traduit						*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				lg_mot		Longueur du mot à traduire											*/
/* 				lg_trad		Longueur du mot traduit												*/
/*																								*/
/*	En sortie : nouv		Pointeur sur la cellule créée										*/
/*----------------------------------------------------------------------------------------------*/

cellule_t * CREER_CELL(char * mot, char * trad)
{
	cellule_t * nouv = NULL;
	int lg_mot, lg_trad;
	nouv = (cellule_t*)malloc(sizeof(cellule_t));
	if (nouv != NULL)
	{
		lg_mot = strlen(mot);
		nouv->mot = (char*)malloc(lg_mot*sizeof(char));
		strcpy(nouv->mot, mot);
		lg_trad = strlen(trad);
		nouv->trad = (char*)malloc(lg_trad*sizeof(char));
		strcpy(nouv->trad, trad);
		nouv->suivant = NULL;
	}
	return nouv;
}


/*----------------------------------------------------------------------------------------------*/
/* ADJ-CELL					Adjonction d'une cellule dans une liste chaînée						*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Si la cellule à insérer existe :									*/
/*								- Faire pointer la nouvelle cellule sur la cellule suivante		*/
/*								- Faire pointer la cellule précédente sur la nouvelle cellule	*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : prec 		Pointeur sur le précédent 											*/
/*				nouv		Pointeur sur la cellule à insérer									*/
/*----------------------------------------------------------------------------------------------*/

void ADJ_CELL(cellule_t ** prec, cellule_t * nouv)
{
	if (nouv != NULL)
	{
		nouv->suivant = *prec;
		*prec = nouv;
	}
}

/*----------------------------------------------------------------------------------------------*/
/* SUPP_CELL					Supprime une cellule dans une liste chaînée						*/
/*																								*/
/*	Algorithme de principe:																		*/
/*								- Faire pointer la cellule précédente vers la cellule suivante	*/
/*								- Libérer la cellule courante									*/
/*								FIN																*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : prec			Pointeur sur le précédent de la cellule à supprimer				*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour			Pointeur sur la cellule à supprimer								*/
/*----------------------------------------------------------------------------------------------*/

void SUPP_CELL(cellule_t ** prec)
{
	cellule_t * cour = *prec;
	*prec = cour->suivant;
	free(cour);
}

/*----------------------------------------------------------------------------------------------*/
/* SUPP_LCH					Libère une liste chaînée											*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Tant que le pointeur de tête n'est pas NULL : 					*/
/*								- Libérer la première cellule									*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : t				Pointeur de tête de la liste chaînée							*/
/*----------------------------------------------------------------------------------------------*/

void SUPP_LCH(cellule_t **t)
{
	cellule_t **prec = t;
	while(*prec != NULL)
	{
		SUPP_CELL(prec);
	} 
}
