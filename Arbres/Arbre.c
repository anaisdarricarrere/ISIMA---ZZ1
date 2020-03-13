/*----------------------------------------------------------------------------------------------*/
/*							TP2 - Gestion d'un dictionnaire arborescent							*/
/*												Arbre.c											*/
/*----------------------------------------------------------------------------------------------*/


#include "Arbre.h"

/*----------------------------------------------------------------------------------------------*/
/* RECH_PREC				Retourne l'adresse du pointeur (lien vertical ou 					*/
/*							lien horizontal) à modifier pour réaliser une insertion 			*/
/* 																								*/
/* Algorithme de principe																		*/
/*							- On initialise le pointeur précédent sur le pointeur de 			*/
/* 							  tête de la liste chaînée de l'arbre ;								*/
/*							- On initialise la profondeur de l'arbre à 0 ;						*/
/*							- On initialise un booléen stop à "faux" ;							*/
/*							- Tant que (stop est faux) et (fin de mot non atteint)				*/
/* 							  et (fin d'arbre non atteinte) faire								*/
/* 								- Si la lettre courante du mot succède celle de l'arbre 		*/
/* 								  dans l'ordre alphabétique alors on passe au lien horizontal ;	*/
/*								- Sinon															*/
/*									- Si la lettre courante du mot n'est pas la dernière du mot	*/
/*									  et est identique à celle de l'arbre alors					*/
/*										- On passe au lien vertical ;							*/
/*									  	- On incrémente la profondeur ;							*/
/* 									 	- On avance dans le mot ;								*/
/*									- Sinon on affecte "vrai" au booléen stop ;					*/
/*							FIN																	*/
/*																								*/
/* Lexique																						*/
/*																								*/
/*	En entrée : t			Pointeur sur le pointeur de tête de l'arbre			 				*/
/*				mot			Pointeur sur la chaîne de caractère contenant le mot à insérer		*/
/*				prof		Adresse de l'entier indiquant la profondeur courante dans l'arbre	*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour		Pointeur sur le bloc courant dans l'arbre							*/
/*				cour_m		Pointeur sur le courant dans le mot à insérer						*/
/*				stop		Booléen : condition d'arrêt											*/
/*																								*/
/*	En sortie : prec		Pointeur sur le précédent de la cellule recherchée					*/
/*----------------------------------------------------------------------------------------------*/


cellule_t ** RECH_PREC(cellule_t ** t, char * mot, int * prof)
{
	char * cour_m = mot;
    cellule_t ** prec = t;
    cellule_t * cour = *t;
    *prof = 0;
    int stop = 0;
    while ((cour != NULL) && (!stop) && (*cour_m != '\0'))
    {
        while ((cour != NULL) && (*cour_m > tolower(cour->lettre)))
        {
            prec = &(cour->lh);
            cour = *prec;
        }
        if ((cour != NULL) && (*cour_m == tolower(cour->lettre)) && (*(cour_m + 1) != '\0'))
        {
            prec = &(cour->lv);
            cour = *prec;
            *prof = *prof + 1;
        }
        else
            stop = 1;
        cour_m = cour_m + 1;
    }
    return prec;
}

/*----------------------------------------------------------------------------------------------*/
/* CREER_CELL				Création d'une cellule de type cellule_t							*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- Allouer un bloc de type cellule_t									*/
/*							- Si l'allocation est réussie :										*/
/*								- Copier le caractère entré en paramètre dans la				*/
/*							  	  nouvelle cellule 												*/
/*                              - Initialiser les liens vertical et horizontal de la nouvelle   */
/*                                cellule à NIL                                                 */
/*							FIN																	*/
/*																								*/
/*  Lexique																						*/
/*					         														    		*/
/*	En entrée : car 		Caractère à mettre dans la nouvelle cellule à créer					*/
/*																								*/
/*	En sortie : nouv		Pointeur sur la cellule créée										*/
/*----------------------------------------------------------------------------------------------*/

cellule_t * CREER_CELL(char car)
{
	cellule_t * nouv = NULL;
	nouv = (cellule_t*)malloc(sizeof(cellule_t));
	if (nouv != NULL)
	{
        nouv->lettre = car;
        nouv->lv = NULL;
        nouv->lh = NULL;
	}
	return nouv;
}

/*----------------------------------------------------------------------------------------------*/
/* ADJ_CELL   				Insère une cellule dans le dictionnaire arborescent à une adresse   */
/*                          donnée                                          					*/
/* 																								*/
/* Algorithme de principe																		*/
/*							- Faire pointer le lien horizontal de la nouvelle cellule sur       */
/*                            la cellule suivante                                   		    */
/*                          - Initialiser le lien vertical de la nouvelle cellule à NIL         */
/*							- Faire pointer la cellule précédente (lien vertical ou horizontal  */
/*                            selon les cas) sur la nouvelle cellule	                        */
/*							FIN																	*/
/*																								*/
/* Lexique																						*/
/*																								*/
/*	En entrée : prec		Pointeur sur le précédent de l'emplacement auquel il faut insérer   */
/*                          la cellule                                                      	*/
/* 				nouv		Pointeur sur la nouvelle cellule        							*/
/*----------------------------------------------------------------------------------------------*/

void ADJ_CELL(cellule_t ** prec, cellule_t * nouv)
{
    nouv->lh = *prec;
    nouv->lv = NULL;
    *prec = nouv;
}

/*----------------------------------------------------------------------------------------------*/
/* INSERT   				Insère un mot par ordre alphabétique dans le dictionnaire           */
/*                          arborescent				                                        	*/
/* 																								*/
/* Algorithme de principe																		*/
/*							- On recherche du précédent pour l'insertion du mot dans l'arbre    */
/*                            (sous-programme RECH_PREC)                                        */
/*                          - Tant que la dernière lettre du mot n'est pas atteinte             */
/*                                  et elle n'est pas en majuscule faire                        */
/*                              - On insère une cellule contenant la lettre courante du mot à   */
/*                                insérer dans l'arbre au niveau du précédent                   */
/*                                (sous-programme ADJ_CELL)                                     */
/*                              - On passe au lien vertical dans l'arbre                        */
/*                          - Mettre le caractère contenue dans la cellule courante en majuscule*/
/*							FIN																	*/
/*																								*/
/* Lexique																						*/
/*																								*/
/*	En entrée : t			Pointeur sur le pointeur de tête de l'arbre			 				*/
/*				mot			Pointeur sur la chaîne de caractère contenant le mot à insérer		*/
/*																								*/
/*  Variables intermédiaires :																	*/
/*				prec		Pointeur sur le précédent du bloc courant dans l'arbre				*/
/*				cour_m		Pointeur sur le courant dans le mot à insérer						*/
/*				prof		Entier indiquant la profondeur courante dans l'arbre            	*/
/*              nouv		Pointeur sur la cellule insérée										*/
/*----------------------------------------------------------------------------------------------*/


void INSERT(cellule_t ** t, char * mot)
{
    cellule_t ** prec;
    cellule_t * nouv;
    char * cour_m;
    int prof = 0;
    prec = RECH_PREC(t, mot, &prof);
    cour_m = mot + prof;
    while (*(cour_m + 1) != '\0')
    {
        nouv = CREER_CELL(*cour_m);
        if (nouv != NULL)
        {
            ADJ_CELL(prec, nouv);
            prec = &((*prec)->lv);
            cour_m = cour_m + 1;
        }
    }
    if (*prec == NULL)
    {
        nouv = CREER_CELL(*cour_m);
        if (nouv != NULL)
            ADJ_CELL(prec, nouv);
    }
    if (*prec != NULL)
        (*prec)->lettre = toupper((*prec)->lettre);
}

/*----------------------------------------------------------------------------------------------*/
/* LECTURE      			    Création d'un dictionnaire arborescent à partir du fichier	    */
/*		 					    d'entrée									        		    */
/*																								*/
/*	Algorithme de principe:																		*/
/*							    - Initialiser une chaîne de caractère vide de 30 mots           */
/*                                (variable auxilière)                              			*/
/*					            - Ouvrir le fichier en lecture						   			*/
/*							    - Si le fichier est ouvert :						    		*/
/*                                  - Répéter :                                                 */
/*                                      - Stocker le mot lu dans le fichier dans la variable    */
/*                                        auxilière                                             */
/*                                      - Insérer la chaîne de caractère dans le dictionnaire   */
/*                                        arborescent (sous-programme INSERT)                   */
/*                                  jusqu'à la fin du fichier                                   */ 
/*							    - Fermer le fichier									        	*/
/*							    FIN																*/
/*						        																*/
/*  Lexique																						*/
/*																								*/
/*	En entrée : nom_fichier		Nom du fichier d'entrée (chaîne de caractères) 					*/
/*				t				Pointeur sur le pointeur de tête de l'arbre         			*/
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				fichier			Pointeur sur le fichier d'entrée								*/
/*              lg              Entier représentant la longueur de la chaîne de caractères mot  */
/*				mot				Chaîne de caractères intermédiaire contenant le mot à insérer	*/
/*																								*/
/*  En sortie : erreur 			Entier valant 0 si le fichier est lu et 1 sinon					*/
/*----------------------------------------------------------------------------------------------*/

int LECTURE(char * nom_fichier, cellule_t ** t)
{
		FILE * fichier;
		int erreur = 1;
        int lg;
		char mot[30];
        fichier = fopen(nom_fichier, "r");
        if (fichier != NULL)
        {
            erreur = 0;
            while(!feof(fichier))
            {
                fgets(mot, 30, fichier);
                lg = strlen(mot);
                if(lg >= 2)
                {
                    if(mot[lg-1] == '\n')
                        lg = lg - 1;
                    mot[lg] = '\0';
                    INSERT(t, mot);
                }
            }
            fclose(fichier);
        }	
		return erreur;
}


/*----------------------------------------------------------------------------------------------*/
/* AFFICHAGE      			Affiche un dictionnaire arborescent déjà créé avec éventuellement   */
/*                          un motif en début de chaque mot                                		*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- On initialise le courant sur le pointeur de tête de la liste      */
/*                            chaînée 				                                            */
/*							- On initialise la pile                                 			*/
/*							- Tant que la pile n'est pas vide ou qu'on est pas à la fin d'une   */
/*                            branche faire      		                                    	*/
/*								- On empile l'adresse de la case lettre de la cellule           */
/*                              - Si la lettre est en majuscule alors                           */
/*                                  - On affiche le contenu de la pile précédée d'un éventuel   */
/*                                    motif (sous-programme AFF_PILE)                           */
/*                              - On passe au lien vertical dans l'arbre                        */
/*								- Tant qu'on est à la fin d'une branche et que la pile n'est    */
/*                                pas vide faire                                                */
/*                                      - On dépile et on affecte au courant l'élément dépilé   */
/*                                      - On passe au lien horizontal dans l'arbre              */
/*                          - Libérer la pile                                                   */
/*                          FIN                                                                 */
/*                                                                                              */
/*  Lexique																						*/
/*																								*/
/*	En entrée : t		        Pointeur sur le pointeur de tête de la liste chaînée			*/
/*              deb             Chaîne de caractère undiquant un éventuel motif à répéter en    */
/*                              début de chaque mot du dictionnaire                             */
/*																								*/
/*  Variables intermédiaires :																	*/
/* 				cour			Pointeur sur une cellule de la liste chaînée					*/
/*				p		        Pointeur sur le bloc de tête de la pile 		            	*/
/*																								*/
/*	Constante globale :                                                                         */
/*              NP              Taille maximum de la pile										*/
/*----------------------------------------------------------------------------------------------*/

void AFFICHAGE(cellule_t ** t, char * deb)
{
    cellule_t * cour = * t;
    pile_t * p;
    p = INIT_PILE(NP);
    while (!(PILE_VIDE(p)) || (cour != NULL))
    {
        EMPILER(p,cour);
        if (isupper(cour->lettre))
        {
            AFF_PILE(p, deb);
        }
        cour = cour->lv;
        while ((cour == NULL) && !(PILE_VIDE(p)))
        {
            cour = DEPILER(p);
            cour = cour->lh;
        }
    }
    LIBERER_PILE(p);
}

/*----------------------------------------------------------------------------------------------*/
/* RECH_MOTIF      			Affiche tous les mots d'un dictionnaire commençant par un motif     */
/*                          donné                                                               */
/*																								*/
/*	Algorithme de principe:	        															*/
/*							- On initialise le courant sur le pointeur de tête de l'arbre       */
/*							- On initialise la profondeur de l'arbre à 0 ;						*/
/*							- On applique la recherche du précédent sur le motif                */
/*                            (sous-programme RECH_PREC)	                                	*/
/*                          - Si la lettre trouvée par la recherche du précédent correspond à   */
/*                            la dernière lettre du motif alors                                 */
/*                              - Si le motif est un mot existant dans le dictionnaire alors    */
/*                                  - Afficher le motif                                         */
/*                              - Afficher le contenu de l'arbre ayant pour racine la cellule   */
/*                                trouvée par la recherche du précédent                         */
/*                          FIN                                                                 */
/*                                                                                              */
/*  Lexique																						*/
/*																								*/
/*	En entrée : t		        Pointeur sur le pointeur de tête de l'arbre         			*/
/*              motif           Chaîne de caractère contenant le motif recherché                */
/*																								*/
/*  Variables intermédiaires :																	*/
/*              cour            Pointeur sur le pointeur courant de l'arbre          	       	*/
/*				prof		    Entier indiquant la profondeur courante dans l'arbre           	*/
/*																								*/
/*	Constante globale :                                                                         */
/*              NP              Taille maximum de la pile										*/
/*																								*/
/*	En sortie : ok		        Entier valant 1 si le motif est présent, 0 sinon    			*/
/*----------------------------------------------------------------------------------------------*/

int RECH_MOTIF(cellule_t ** t, char * motif)
{
    int ok = 0;
    cellule_t ** cour = t;
    int prof = 0;
    cour = RECH_PREC(t, motif, &prof);
    if (tolower((*cour)->lettre) == motif[prof])
    {
        if (isupper((*cour)->lettre))
            printf("%s \n", motif);                 /* Affichage du motif */
        AFFICHAGE(&((*cour)->lv), motif);
        ok = 1;
    }
    return ok;
}

/*----------------------------------------------------------------------------------------------*/
/* SUPP_ARBRE				Libère l'arbre                          							*/
/*																								*/
/*	Algorithme de principe:																		*/
/*							- On initialise le courant sur le pointeur de tête de l'arbre       */
/*							- On initialise la pile                                 			*/
/*							- Tant que la pile n'est pas vide ou qu'on est pas à la fin d'une   */
/*                            branche faire      		                                    	*/
/*								- On empile l'adresse de la cellule courante de l'arbre         */
/*                              - On passe au lien vertical dans l'arbre                        */
/*								- Tant qu'on est à la fin d'une branche et que la pile n'est    */
/*                                pas vide faire                                                */
/*                                      - On dépile et on affecte au courant l'élément dépilé   */
/*                                      - On sauvegarde le courant dans une variable            */
/*                                        auxiliaire temp                                       */
/*                                      - On passe au lien horizontal dans l'arbre              */
/*                                      - On libère la cellule d'adresse sauvegardée dans temp  */
/*                          - Libérer la pile                                                   */
/*                          FIN                                                                 */
/*  Lexique																						*/
/*					         														    		*/
/*	En entrée : t		    Pointeur sur le pointeur de tête de l'arbre              			*/
/*																								*/
/*  Variables intermédiaires :																	*/
/*              cour        Pointeur sur la cellule courante de l'arbre                	       	*/
/*              temp        Variable auxiliaire                                                 */
/*              p           Pointeur sur le bloc de tête de la pile                             */
/*----------------------------------------------------------------------------------------------*/

void SUPP_ARBRE(cellule_t ** t)
{
    cellule_t * cour = *t;
    cellule_t * temp = NULL;
    pile_t * p;
    p = INIT_PILE(NP);
    while (!(PILE_VIDE(p)) || (cour != NULL))
    {
        EMPILER(p,cour);
        cour = cour->lv;
        while ((cour == NULL) && !(PILE_VIDE(p)))
        {
            cour = DEPILER(p);
            temp = cour;
            cour = cour->lh;
            free(temp);
        }
    }
    LIBERER_PILE(p);
}