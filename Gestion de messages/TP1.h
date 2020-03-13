/*------------------------------------------------------------------------------*/
/*								TP1 - Gestion de messages						*/
/* 								Fichier d'entête TP1.h							*/
/*																				*/
/* Déclaration des fonctions de gestion de messages								*/
/*------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Lch.h"

/*------------------------------------------------------------------------------*/
/* Prototypes des fonctions		    											*/
/*------------------------------------------------------------------------------*/

int LECTURE(char * nom_fichier, cellule_t ** t);

int SAUVEGARDE(cellule_t * t, char * nom_fichier);

int DATE_DU_JOUR();

void AFF_NON_EXP(cellule_t ** t);

void SUPP_MESS_EXP(cellule_t ** t);

void MODIF_DATE_DEB(cellule_t * t, int deb_init, int deb_nouv);









