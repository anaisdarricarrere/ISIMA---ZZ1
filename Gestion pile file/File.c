/*--------------------------------------------------------------------------------------*/
/*						TP1 - Gestion d'une pile et d'une file							*/
/*									Module File.c										*/
/*--------------------------------------------------------------------------------------*/

#include "File.h"


/*--------------------------------------------------------------------------------------*/
/* INIT_FILE 				Initialisation d'une file									*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Allouer le bloc de tête de la file						*/
/*							- Si l'allocation est réussie :								*/
/*									- Allouer le bloc file								*/
/*									- Si l'allocation est réussie :						*/
/*										- Initialiser les éléments du bloc de tête		*/
/*									- Sinon : Libérer le bloc de tête de la file		*/
/*                          - Sinon : Afficher un message d'erreur                      */
/*                          FIN                                                         */
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : N 			Taille de la pile									 		*/
/*																						*/
/*	En sortie : f			Pointeur sur le bloc de tête de la file						*/
/*--------------------------------------------------------------------------------------*/

file_t * INIT_FILE (int N)
{
	file_t * f;
	f = (file_t*)malloc(sizeof(file_t));
	if (f != NULL)
	{
    	f->ad_file = (element_file *)malloc(N*sizeof(element_file));
        if (f->ad_file != NULL)
        {
            f->taille_max = N;
            f->compteur = 0;
		    f->rg_premier = 0;
			f->rg_dernier = N-1;
        }
        else
        {
            free(f);
            f = NULL;
        }
	}
    else
	{	
        printf("Erreur : probleme d'allocation\n");
	}
	return f;
}

/*--------------------------------------------------------------------------------------*/
/* LIBERER_FILE 			Libération d'une file										*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : f 			Pointeur sur le bloc de tête de la pile				 		*/
/*--------------------------------------------------------------------------------------*/

void LIBERER_FILE(file_t * f)
{
	free(f->ad_file);
	free(f);
}

/*--------------------------------------------------------------------------------------*/
/* FILE_VIDE 				Détermine si la file est vide								*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : f			Pointeur sur le bloc de tête de la file				 		*/
/*																						*/
/*	En sortie : 			Retourne 1 si la file est vide et 0 sinon					*/
/*--------------------------------------------------------------------------------------*/

int FILE_VIDE(file_t * f)
{
	return (f->compteur == 0);
}

/*--------------------------------------------------------------------------------------*/
/* FILE_PLEINE 				Détermine si la file est pleine								*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : f 			Pointeur sur le bloc de tête de la file				 		*/
/*																						*/
/*	En sortie : 			Retourne 1 si la file est pleine et 0 sinon					*/
/*--------------------------------------------------------------------------------------*/

int FILE_PLEINE(file_t * f)
{
	return (f->compteur == f->taille_max);
}

/*--------------------------------------------------------------------------------------*/
/* ENTREE 					Ajoute un élément en fin de la file							*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si la file n'est pas pleine : 							*/
/*									- on incrémente le rang du dernier élément 			*/
/*									  de la file (modulo la taille max de la file)		*/
/* 									- on copie l'élément à insérer en fin de file		*/
/*									- on incrémente le compteur d'éléments de la file	*/
/*							- Sinon : afficher un message d'erreur						*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : f 			Pointeur sur le bloc de tête de la file				 		*/
/*				element		Elément à insérer dans la file								*/
/*																						*/
/*	Variables intermédiaires :															*/
/*				taille		taille maximale de la file									*/
/*																						*/
/*	En sortie : ok			Retourne 1 si l'élément est inséré, 0 si la file est 		*/
/*							pleine et l'élément n'a pas pu être inséré					*/
/*--------------------------------------------------------------------------------------*/

int ENTREE(file_t* f, element_file element)
{
	int taille = f->taille_max;
	int ok;
	ok = !(FILE_PLEINE(f));
	if (ok)
	{
		f->rg_dernier = (f->rg_dernier+1)%taille;
		*(f->ad_file + f->rg_dernier) = element;
		f->compteur++;
	}
	else
		printf("Erreur : File pleine\n");
	return ok;
}

/*--------------------------------------------------------------------------------------*/
/* SORTIE 					Retourne et supprime l'élément en tête de file 				*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si la file n'est pas vide: 								*/
/*									- on récupère l'élément à servir en tête de file	*/
/* 									- on incrémente le rang du premier élément			*/
/*									  (modulo la taille max de la file)					*/
/*									- on décrémente le compteur d'éléments de la file	*/
/*							- Sinon : afficher un message d'erreur						*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : f 			Pointeur sur le bloc de tête de la file				 		*/
/*																						*/
/*  Variables intermédiaires :															*/
/*				taille		entier indiquant la taille maximale de la file				*/
/* 				ok			Entier valant 0 si la file est vide et 1 sinon				*/
/*																						*/
/*	En sortie : res			Retourne l'élément à sortir de la file						*/
/*--------------------------------------------------------------------------------------*/

element_file SORTIE(file_t *f)
{
	int taille = f->taille_max;
	element_file res;
	int ok;
	ok = !(FILE_VIDE(f));
	if (ok)
	{
		res = *(f->ad_file + f->rg_premier);
		f->rg_premier = (f->rg_premier+1)%taille;
		f->compteur--;
	}
	else
		printf("Erreur : File vide\n");
	return res;
}

/*--------------------------------------------------------------------------------------*/
/* AFF_FILE 				Affiche la liste des éléments contenus dans la file			*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si la file n'est pas vide: 								*/
/*									- On parcourt la file de l'élément en tête à celui	*/
/*									  en fin en affichant chacun de ces éléments		*/
/*							- Sinon : afficher un message d'erreur						*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : f 			Pointeur sur le bloc de tête de la file				 		*/
/*																						*/
/*  Variables intermédiaires :															*/
/*				nb_elem		entier indiquant le nombre d'éléments contenus dans la file	*/
/*																						*/
/*--------------------------------------------------------------------------------------*/

void AFF_FILE(file_t * f)
{
	int nb_elem = f->compteur;
	int i;
	if (nb_elem != 0)
	{
		element_file * deb = (f->ad_file) + (f->rg_premier);
		printf("[ ");
		for(i=0; i<nb_elem; i++)
		{
			printf(format,*(deb+i));
			printf(" ");
		}
		printf("]\n");
	}
	else
		printf("File vide\n");
}