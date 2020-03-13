/*----------------------------------------------------------------------------------------------*/
/*									TP1 - Gestion de messages									*/
/*												TP1.c											*/
/*----------------------------------------------------------------------------------------------*/
 
#include "TP1.h"

/*----------------------------------------------------------------------------------------------*/
/* LECTURE						Création d'une liste chaînée à partir du 						*/
/*		 						fichier d'entrée												*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Allouer un bloc de 100 mots										*/
/*							  (bloc temporaire pour stocker une chaîne de caractères)			*/
/*							- Si l'allocation est réussie :										*/
/*								- Ouvrir le fichier en lecture									*/
/*								- Si le fichier est ouvert :									*/
/*									- Tant que l'on n'a pas atteint la fin du fichier :			*/
/*										- Créer une nouvelle cellule							*/
/*										  (sous-programme CREER_CELL)							*/
/*										- Copier les valeurs lues dans le fichier dans			*/
/*										  cette cellule											*/
/*										- Insérer cette cellule dans la liste chaînée			*/
/*										  (sous-programme INSERT_CELL)							*/
/*									- Fermer le fichier											*/
/*									- Libérer le bloc de caractères	temporaire					*/
/*								- Sinon : Afficher un message d'erreur							*/
/*							- Sinon : Afficher un message d'erreur								*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : nom_fichier		Nom du fichier d'entrée (chaîne de caractères) 					*/
/*				t				Pointeur sur le pointeur de tête de la liste chaînée			*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				fichier			Pointeur sur le fichier d'entrée								*/
/*				deb, fin		Deux entiers représentant respectivement les dates de 			*/
/*								début et fin de validité du message								*/
/*				nouv			Pointeur sur la cellule à insérer dans la liste chaînée			*/
/*				txt				Chaîne de caractères intermédiaire contenant le message			*/
/*				texte			Chaîne de caractères contenant le message						*/
/*																								*/
/*  En sortie : erreur 			Entier valant 0 si le fichier est lu et 1 sinon					*/
/*----------------------------------------------------------------------------------------------*/

int LECTURE(char * nom_fichier, cellule_t ** t)
{
		FILE * fichier;
		int deb, fin, erreur = 1;
		cellule_t * nouv;
		char * txt, * texte;
		txt = (char *)malloc(100*sizeof(char));
		if (txt != NULL)
		{
			fichier = fopen(nom_fichier, "r");
			if (fichier != NULL)
			{
				erreur = 0;
				while (fscanf(fichier, "%d %d", &deb, &fin) != EOF)
				{
					fgets(txt, 100, fichier);
					texte = (char *)malloc(strlen(txt)*sizeof(char));
					strcpy(texte, txt);
					texte[strlen(txt)-1] = '\0';
					nouv = CREER_CELL(deb, fin, texte);
					INSERT_CELL(nouv, t);
				}
				fclose(fichier);
				free(txt);
			}
			else
				printf("Erreur lors de l'ouverture du fichier\n");
		}
		else
			printf("Erreur : problème d'allocation\n");
		
		return erreur;
}

/*----------------------------------------------------------------------------------------------*/
/* SAUVEGARDE					Sauvegarde de la liste chaînée d'entrée dans un fichier			*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Lire le nom du fichier de sauvegarde choisi par l'utilisateur		*/
/*							- Allouer un bloc de la taille de ce nom de fichier					*/
/*							- Si l'allocation est réussie :										*/
/*								- Ouvrir un fichier en écriture portant ce nom					*/
/*								- Si le fichier est ouvert :									*/
/*									- Tant que l'on n'a pas atteint la fin du fichier :			*/
/*										- Copier dans le fichier (sur une ligne) les valeurs	*/
/*										  contenues dans la cellule courante					*/
/*										- Avancer le pointeur courant dans la liste chaînée		*/
/*									- Fermer le fichier											*/
/*								- Sinon : Afficher un message d'erreur							*/
/*							- Sinon : Afficher un message d'erreur								*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : t				Pointeur sur le pointeur de tête de la liste					*/
/*				nom_fichier		Pointeur sur une chaïne de caractère désignant 					*/
/*								le nom du fichier à créer										*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				fichier			Pointeur sur le fichier d'entrée								*/
/* 				cour			Pointeur sur la cellule courante								*/
/*																								*/
/*  En sortie : erreur 			Entier valant 0 si le fichier est créé et 1 sinon				*/
/*----------------------------------------------------------------------------------------------*/

int SAUVEGARDE(cellule_t * t, char * nom_fichier)
{
	FILE * fichier;
	cellule_t * cour = t;
	int erreur = 1;
	char buffer [20];
	printf("Nom du fichier de sauvegarde :\n");
	scanf("%s", buffer);
	nom_fichier = (char *)malloc(sizeof(char)*strlen(buffer));
	if (nom_fichier != NULL)
	{
		strcpy(nom_fichier, buffer);
		fichier = fopen(nom_fichier, "w");
		if ((fichier != NULL))
		{
			erreur = 0;
			while (cour != NULL)
			{
				fprintf(fichier, "%d %d %s\n", cour->deb_valid, cour->fin_valid, cour->texte);
				cour = cour->suivant;
			}
			fclose(fichier);
		}
		else
			printf("Erreur lors de l'ouverture du fichier\n");
	}
	else
		printf("Erreur : problème d'allocation\n");
	return erreur;
}

/*----------------------------------------------------------------------------------------------*/
/* DATE_DU_JOUR					Retourne un entier représentant la date du jour					*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Récupérer la date système avec la fonction localtime()			*/
/*							- Mettre cette date de la forme aaaammjj							*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour			Pointeur sur la cellule courante								*/
/*				date			Entier représentant la date du jour								*/
/*																								*/
/*  En sortie : date 			Entier représentant la daje du jour sous la forme				*/
/*								aaaammjj														*/
/*----------------------------------------------------------------------------------------------*/

int DATE_DU_JOUR()
{
	time_t temps;
	struct tm * ajd;
	int date = 0;
	
	temps = time(NULL);
	ajd = localtime(&temps);

	int annee = ajd->tm_year + 1900;			/* tm_year : annee courante - 1900 */
	int mois = ajd->tm_mon + 1;					/* tm_mon : mois [0-11] */
	int jour = ajd->tm_mday;					/* tm_mday : jour du mois [1-31] */
	
	date += annee*10000 + mois*100 + jour;		/* date de la forme aaaammjj */
	return date;
}

/*----------------------------------------------------------------------------------------------*/
/* AFF_NON_EXP					Affiche les messages non expirés à la date du jour				*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Sauvegarder dans une variable la date système						*/
/*							  (sous-programme DATE_DU_JOUR)										*/
/*							- Tant que l'on n'a pas atteint la fin de la liste chaînée :		*/
/*								- Si la date système est inférieure à la date de fin de			*/
/*								  validité de la cellule courante :								*/
/*									- Afficher les valeurs contenues dans la cellule courante	*/
/*								- Avancer le pointeur courant dans la liste chaînée				*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : t				Pointeur sur le pointeur de tête de la liste					*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour			Pointeur sur la cellule courante								*/
/*				date			Entier représentant la date du jour								*/
/*----------------------------------------------------------------------------------------------*/

void AFF_NON_EXP(cellule_t ** t)
{
	cellule_t * cour = *t;
	int date;
	date = DATE_DU_JOUR();
	printf("date du jour : %d\n", date);
	printf("Messages non expirés :\n");
	while (cour != NULL)
	{
		if (date < cour->fin_valid)
			printf("%d %d %s\n", cour->deb_valid, cour->fin_valid, cour->texte);
		cour = cour->suivant;
	}
}

/*----------------------------------------------------------------------------------------------*/
/* SUPP_MESS_EXP				Supprime les messages devenus obsolètes dans une				*/
/*								liste chaînée													*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Sauvegarder la date système dans une variable						*/
/*							  (sous-programme DATE_DU_JOUR)										*/
/*							- Tant que l'on n'a pas atteint la fin de la liste chaînée :		*/
/*								- Si la date système est supérieure à la date de fin de			*/
/*								  validité de la cellule courante :								*/
/*									- Supprimer la cellule courante (sous-programme SUPP_CELL)	*/
/*								- Sinon : Avancer la pointeur sur le précédent dans la liste	*/
/*							- Avancer le pointeur courant dans la liste							*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : t				Pointeur sur le pointeur de tête de la liste					*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				date			Entier représentant la date du jour								*/
/* 				prec			Pointeur sur le précédant de la cellule courante				*/
/* 				cour			Pointeur sur la cellule courante								*/
/*----------------------------------------------------------------------------------------------*/

void SUPP_MESS_EXP(cellule_t ** t)
{
	int date = DATE_DU_JOUR();
	cellule_t ** prec = t;
	cellule_t * cour = *t;
	while (cour != NULL)
	{
		if (date > cour->fin_valid)
			SUPP_CELL(prec);
		else
			prec = &cour->suivant;
		cour = *prec;
	}
}

/*----------------------------------------------------------------------------------------------*/
/* MODIF_DATE_DEB				Modifie la date de début des messages d'une date				*/
/*								initiale donnée													*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Tant que l'on n'a pas atteint la fin de la liste chaînée :		*/
/*								- Si la date de début de validité de la cellule courante est	*/
/*								  égale à la date initiale à modifier :							*/
/*									- Modifier la date de début de validité de la cellule en	*/
/*									  la date voulue											*/
/*								- Avancer le pointeur courant dans la liste chaînée				*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : t				Pointeur de tête de la liste chaînée							*/
/*				date_init		Entier représentant la daate initiale à modifier				*/
/*				date_nouv		Entier représentant la nouvelle date							*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour			Pointeur sur la cellule courante								*/
/*----------------------------------------------------------------------------------------------*/

void MODIF_DATE_DEB(cellule_t * t, int date_init, int date_nouv)
{
	cellule_t * cour = t;
	while (cour != NULL)
	{
		if ((cour->deb_valid == date_init))
			cour->deb_valid = date_nouv;
		cour = cour->suivant;
	}
}
