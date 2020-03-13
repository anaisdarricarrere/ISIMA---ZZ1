/*------------------------------------------------------------------------------------------------------*/
/*									TP4 - Gestion de table												*/
/* 									Fichier d'entête Table.h											*/
/*																										*/
/* Déclaration des structures et des fonctions de gestion d'une table									*/
/*------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Lch.h"

/*------------------------------------------------------------------------------------------------------*/
/* Définition de constante pour la fontion de hachage   												*/
/*------------------------------------------------------------------------------------------------------*/

#define HASH_MAX 29

/*------------------------------------------------------------------------------------------------------*/
/* Prototypes des fonctions		    																	*/
/*------------------------------------------------------------------------------------------------------*/

unsigned int hash(const char * str);

cellule_t ** RECHERCHE(cellule_t ** maj, char * word);

void INSERT_CELL(cellule_t * nouv, cellule_t ** maj);

int DICTIONNAIRE (char * nom_fichier, cellule_t ** maj);
