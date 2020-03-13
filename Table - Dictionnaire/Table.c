/*----------------------------------------------------------------------------------------------*/
/*									TP4 - Gestion de table										*/
/*											Table.c												*/
/*----------------------------------------------------------------------------------------------*/


#include "Table.h"

/*----------------------------------------------------------------------------------------------*/
/* hash_string              Fonction de hachage appliquée sur une chaîne de caractères          */
/*                          (fonction de hachage de D.J. Bernstein)                             */
/*----------------------------------------------------------------------------------------------*/

unsigned int hash(const char * str)
{
    unsigned int hash = 5381;
    const char * s;
    for (s = str; *s; s++)
        hash =  ((hash << 5) + hash) + tolower(*s);
    return (hash & 0x7FFFFFFF)%HASH_MAX;
}

/*----------------------------------------------------------------------------------------------*/
/* CREER_TABLE				Création de la table majeure vide									*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- On alloue un bloc de N mots										*/
/*							- Si l'allocation est réussie alors									*/
/*								- On affecte NULL à chacun des mots								*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : maj 		Adresse de la table majeure											*/
/*----------------------------------------------------------------------------------------------*/

void CREER_TABLE(cellule_t ** maj)
{
	int i;
	maj = (cellule_t **)malloc(sizeof(cellule_t*)*HASH_MAX);
	if (maj != NULL)
	{
		for (i=0; i<HASH_MAX; i++)
			maj+i = NULL;
	}
}


/*----------------------------------------------------------------------------------------------*/
/* RECHERCHE				Recherche du précédent d'une cellule contenant le mot à rechercher	*/
/*							dans une liste chaînée												*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- On initialise le pointeur courant sur la première cellule de la 	*/
/*							  sous-table contenant le mot donné en entrée 						*/
/*							  (utilisation de la fonction de hachage)							*/
/*							- On initialise une variable trad à la chaîne de caractère vide		*/
/*							- Tant qu'on est pas à la fin de la sous-table et que la cellule	*/
/*							  courante ne contient pas le mot faire :							*/
/*								- On avance le pointeur du courant au bloc suivant dans la 		*/
/*								  liste chaînée													*/
/*							- Si on a trouvé le mot alors										*/
/*								- On sauvegarde le mot traduit correspondant					*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : maj 		Adresse de la table majeure											*/
/*				word		Chaîne de caractère contenant le mot recherché						*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour		Pointeur sur la cellule courante									*/
/*																								*/
/*	En sortie : trad		Chaîne de caractère vide si le mot n'est pas trouvé et contenant le */
/*							mot traduit sinon 													*/
/*----------------------------------------------------------------------------------------------*/

char * RECHERCHE(cellule_t ** maj, char * word)
{
	cellule_t * cour;
	char * trad = '\0';
	cour = *(maj + hash_string(word));
	while ((cour != NULL) && (strcmp(cour->mot,word) != 0)
	{
		cour = cour->suivant;
	}
	if (cour != NULL)
		trad = cour->trad;
	return trad;
}


/*----------------------------------------------------------------------------------------------*/
/* INSERT_CELL			    Insertion d'une cellule dans une sous-table 			 			*/
/*																								*/
/*	Algorithme de principe:																		*/
/*                          - Calculer l'indice de début de la sous-table                       */
/*                            (utilisation de la fonction de hachage)                           */
/*							- Rechercher l'adresse du suivant de la dernière cellule de la      */
/*                            sous-table                                						*/
/*                          - Avancer dans la sous-table jusqu'à la dernière cellule            */
/*							- Insérer la nouvelle cellule à cette adresse						*/
/*							  (sous-programme ADJ_CEL)											*/
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : nouv		Pointeur sur la cellule à insérer									*/
/*				maj 		Adresse de la table majeure											*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				prec		Pointeur sur le précédent											*/
/*----------------------------------------------------------------------------------------------*/

void INSERT_CELL(cellule_t * nouv, cellule_t ** maj)
{
	cellule_t ** prec;
    cellule_t * cour;
    prec = maj + hash(nouv->mot);
    cour = *prec;
    while (cour != NULL)
    {
        prec = &(cour->suivant);
        cour = *prec;
	}
	ADJ_CELL(prec, nouv);
}

/*---------------------------------------A MODIFIER !!!!!!!--------------------------------------------*/
/* DICTIONNAIRE      			Création d'un dictionnaire à partir d'un fichier d'entrée	    */
/*																								*/
/*	Algorithme de principe:																		*/
/*							    - Initialiser deux chaînes de caractère vides de 30 mots        */
/*                                (variables auxilières)                              			*/
/*					            - Ouvrir le fichier en lecture						   			*/
/*							    - Si le fichier est ouvert :						    		*/
/*                                  - Tant que le fichier n'est pas fini faire :                */
/*                                      - Stocker les mots contenus sur une ligne du fichier 	*/
/*										  dans les deux variables auxilières					*/
/*										- Créer une cellule avec les deux chaînes de caractère 	*/
/*										  dans le dictionnaire en tant que mot à traduite et 	*/
/*										  mot traduit											*/
/*                                      - Insérer la nouvelle cellule dans la table				*/						
/*                                        (sous-programme INSERT_CELL)              		    */
/*							    - Fermer le fichier									        	*/
/*							    FIN																*/
/*						        																*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : nom_fichier		Nom du fichier d'entrée (chaîne de caractères) 					*/
/*				maj				Adresse de la table majeure         							*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 	   fichier					Pointeur sur le fichier d'entrée								*/
/*     lg_ligne,lg_mot,lg_trad  Entiers représentant les longueurs respectives d'une ligne du 	*/
/*								fichier, du mot à traduire et du mot traduit					*/
/*	   ligne,temp_mot,temp_trad Chaînes de caractère intermédiaires contenant respectivement	*/
/*								la ligne courante du fichier, le mot à traduire et le 			*/
/*								mot traduit														*/
/*																								*/
/*  En sortie : erreur 			Entier valant 0 si le fichier est lu et 1 sinon					*/
/*------------------------------------MODIF PAS FINIES!!!!!!!!!!!!!!!!!!!!!!!!!!!!---------------------------------------------*/

int DICTIONNAIRE (char * nom_fichier, cellule_t ** maj)
{
		FILE * fichier;
		int erreur = 1;
        int lg_ligne, lg_mot, lg_trad;
		char ligne[60], temp_mot[30], temp_trad[30];
		char * mot, * trad;
		cellule_t * nouv;
        fichier = fopen(nom_fichier, "r");
        if (fichier != NULL)
        {
            erreur = 0;
            while(!feof(fichier))
            {
                fgets(ligne, 60, fichier);
                lg_ligne = strlen(ligne);
                if(lg_ligne >= 2)
                {
                    if(ligne[lg_ligne-1] == '\n')
                        lg_ligne = lg_ligne - 1;
                    ligne[lg_ligne] = '\0';
                }
                temp_mot = strtok(str,";");
                lg_mot = strlen(temp_mot);
                mot = (char *)malloc(sizeof(char)*lg_mot);
                temp_trad = strtok(NULL,'\0');
                lg_trad = strlen(temp_trad);
                trad = (char *)malloc(sizeof(char)*lg_trad);
                nouv = CREER_CELL(mot, trad);
                INSERT_CELL(nouv, maj); 
            }
            fclose(fichier);
        }	
		return erreur;
}




