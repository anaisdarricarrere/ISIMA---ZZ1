/*----------------------------------------------------------------------------------------------*/
/*									TP1 - Gestion de messages									*/
/*										    Moduce Lch.c										*/
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
/*	En entrée : deb, fin 	Deux entiers représentant respectivement les dates de 				*/
/*							début et fin de validité du message									*/
/*				texte		Chaîne de caractères contenant le message							*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				lg_texte	Longueur du message													*/
/*																								*/
/*	En sortie : nouv		Pointeur sur la cellule créée										*/
/*----------------------------------------------------------------------------------------------*/

cellule_t * CREER_CELL(int deb, int fin, char * texte)
{
	cellule_t * nouv = NULL;
	int lg_texte;
	nouv = (cellule_t*)malloc(sizeof(cellule_t));
	if (nouv != NULL)
	{
		nouv->deb_valid = deb;
		nouv->fin_valid = fin;
		lg_texte = strlen(texte);
		nouv->texte = (char*)malloc(lg_texte*sizeof(char));
		strcpy(nouv->texte, texte);
	}
	return nouv;
}

/*----------------------------------------------------------------------------------------------*/
/* RECH_PREC				Recherche du précédent dans une liste chaînée triée					*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Si la liste est non vide et la date de début de 					*/
/*							validité du message est inférieure à la date recherchée :			*/
/*								- Avancer le pointeur du précedent et le pointeur				*/ 
/*								  courant au bloc suivant dans la liste chaînée					*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : date_deb 	Entier représentant la date de début de la cellule à insérer		*/
/*				t			Pointeur sur le pointeur de tête de la liste						*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour		Pointeur sur la cellule courante									*/
/*																								*/
/*	En sortie : prec		Pointeur sur le précédent de la cellule recherchée					*/
/*----------------------------------------------------------------------------------------------*/

cellule_t ** RECH_PREC(int date_deb, cellule_t ** t)
{
	cellule_t * cour = *t;
	cellule_t ** prec = t;
	while ((cour != NULL) && (cour->deb_valid < date_deb))
	{
		prec = &(cour->suivant);
		cour = cour->suivant;
	}
	return prec;
}

/*----------------------------------------------------------------------------------------------*/
/* ADJ-CELL				Adjonction d'une cellule dans une liste chaînée							*/
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
/* INSERT_CELL			Insertion d'une cellule dans une liste chaînée triée		 			*/
/*						(selon la date de début de validité)									*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Rechercher l'adresse à laquelle il faut insérer la nouvelle		*/
/*							  cellule afin de garder la liste chaînée triée						*/
/*							  (sous-programme RECH_PREC)										*/
/*							- Insérer la nouvelle cellule à cette adresse						*/
/*							  (sous-programme ADJ_CEL)											*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : nouv		Pointeur sur la cellule à insérer									*/
/*				t 			Pointeur sur le pointeur de tête de la liste chaînée				*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				prec		Pointeur sur le précédent											*/
/*----------------------------------------------------------------------------------------------*/

void INSERT_CELL(cellule_t * nouv, cellule_t ** t)
{
	cellule_t ** prec;
	prec = RECH_PREC(nouv->deb_valid, t);
	ADJ_CELL(prec, nouv);
}

/*----------------------------------------------------------------------------------------------*/
/* SUPP_CELL					Supprime une cellule dans une liste chaînée						*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Faire pointer la cellule précédente vers la cellule suivante		*/
/*							- Libérer la cellule courante										*/
/*							FIN																	*/
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