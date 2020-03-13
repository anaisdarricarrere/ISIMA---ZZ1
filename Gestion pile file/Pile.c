/*--------------------------------------------------------------------------------------*/
/*						TP2 - Gestion d'une pile et d'une file							*/
/*											Pile.c										*/
/*--------------------------------------------------------------------------------------*/


#include "Pile.h"


/*--------------------------------------------------------------------------------------*/
/* INIT_PILE 				Initialisation d'une pile									*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Allouer le bloc de tête de la pile						*/
/*							- Si l'allocation est réussie: 								*/
/*									- on initialise les éléments du bloc de tête		*/
/* 									- on alloue le bloc pile							*/
/*									- Si l'allocation n'est pas réussie, on libère le 	*/
/* 									bloc de tête										*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : N 			Taille de la pile									 		*/
/*																						*/
/*	En sortie : p			Pointeur sur le bloc de tête de la pile						*/
/*--------------------------------------------------------------------------------------*/

pile_t * INIT_PILE (int N)
{
		pile_t * p;
		p = (pile_t*)malloc(sizeof(pile_t));
		if (p != NULL)
		{
			p->taille_max = N;
			p->rg_sommet = -1;
			p->ad_pile = (element_pile *)malloc(sizeof(element_pile)*N);
			if (p->ad_pile == NULL)
				{
					free(p);
					p = NULL;
				}
		}
		return p;
}



/*--------------------------------------------------------------------------------------*/
/* LIBERER_PILE 			Libération d'une pile										*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Libérer la pile											*/
/*							- Libérer le bloc de tête de la pile						*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : p 			Pointeur sur le bloc de tête de la pile				 		*/
/*--------------------------------------------------------------------------------------*/

void LIBERER_PILE(pile_t * p)
{
	free(p->ad_pile);
	free(p);
}

/*--------------------------------------------------------------------------------------*/
/* PILE_VIDE 				Détermine si la pile est vide								*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : p 			Pointeur sur le bloc de tête de la pile				 		*/
/*																						*/
/*	En sortie : 			Retourne 1 si la pile est vide et 0 sinon					*/
/*--------------------------------------------------------------------------------------*/

int PILE_VIDE(pile_t * p)
{
	return (p->rg_sommet == -1);
}

/*--------------------------------------------------------------------------------------*/
/* PILE_PLEINE 				Détermine si la pile est pleine								*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : p 			Pointeur sur le bloc de tête de la pile				 		*/
/*																						*/
/*	En sortie : 			Retourne 1 si la pile est pleine et 0 sinon					*/
/*--------------------------------------------------------------------------------------*/

int PILE_PLEINE(pile_t * p)
{
	return (p->rg_sommet == p->taille_max -1);
}

/*--------------------------------------------------------------------------------------*/
/* EMPILER 					Ajoute un élément en tête de la pile						*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si la pile n'est pas pleine : 							*/
/*									- on incrémente le rang du premier élément			*/
/* 									- on insère l'élément								*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : p 			Pointeur sur le bloc de tête de la pile				 		*/
/*				element		Elément à empiler											*/
/*																						*/
/*	En sortie : ok			Retourne 1 si l'élément est empilé							*/
/*--------------------------------------------------------------------------------------*/

int EMPILER(pile_t* p, element_pile element)
{
	int ok;
	ok = !(PILE_PLEINE(p));
	if (ok)
	{
		p->rg_sommet = (p->rg_sommet)+1;
		*(p->ad_pile + p->rg_sommet) = element;
	}
	else
		printf("Erreur : pile pleine\n");
	return ok;
}

/*--------------------------------------------------------------------------------------*/
/* DEPILER 					Enleve l'élément au sommet de la pile						*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si la pile n'est pas vide: 								*/
/*									- on récupère l'élément à dépiler					*/
/* 									- on décrémente le rang du premier élément			*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : p 			Pointeur sur le bloc de tête de la pile				 		*/
/*																						*/
/*  Variables intermédiaires :															*/
/* 				ok			Entier valant 0 si la pile est vide et 1 sinon				*/
/*																						*/
/*	En sortie : res			Retourne l'élément à enlever de la pile						*/
/*--------------------------------------------------------------------------------------*/

element_pile DEPILER(pile_t *p)
{
	int ok;
	element_pile res;
	ok = !(PILE_VIDE(p));
	if (ok)
	{
		res = *(p->ad_pile + p->rg_sommet);
		p->rg_sommet = (p->rg_sommet)-1;
	}
	else
		printf("Erreur : pile vide\n");
	return res;
}

/*--------------------------------------------------------------------------------------*/
/* SOMMET 					Retourne l'élément au sommet de la pile						*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si la pile n'est pas vide: 								*/
/*									- on récupère l'élément au sommet					*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : p 			Pointeur sur le bloc de tête de la pile				 		*/
/*																						*/
/*  Variables intermédiaires :															*/
/* 				ok			Entier valant 0 si la pile est vide et 1 sinon				*/
/*																						*/
/*	En sortie : res			Retourne l'élément à enlever de la pile						*/
/*--------------------------------------------------------------------------------------*/

element_pile SOMMET(pile_t *p)
{
	int ok;
	element_pile res = -1;
	ok = !(PILE_VIDE(p));
	if (ok)
	{
		res = *(p->ad_pile + p->rg_sommet);
	}
	return res;
}


/*--------------------------------------------------------------------------------------*/
/* AFF_PILE 				Affiche la liste des éléments contenus dans la pile			*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si la pile n'est pas vide: 								*/
/*									- On parcourt la pile de l'élément en tête à celui	*/
/*									  en fin en affichant chacun de ces éléments		*/
/*							- Sinon : afficher un message d'erreur						*/
/*							FIN															*/
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : p 			Pointeur sur le bloc de tête de la pile				 		*/
/*																						*/
/*  Variables intermédiaires :															*/
/*				nb_elem		entier indiquant le nombre d'éléments contenus dans la pile	*/
/*																						*/
/*--------------------------------------------------------------------------------------*/

void AFF_PILE(pile_t * p)
{
	int nb_elem = p->rg_sommet +1;
	int i;
	if (nb_elem != 0)
	{
		element_pile * deb = (p->ad_pile) + (p->rg_sommet);
		printf("[ ");
		for(i=0; i<nb_elem; i++)
		{
			printf(format,*(deb-i));
			printf(" ");
		}
		printf("]\n");
	}
	else
		printf("Pile vide\n");
}