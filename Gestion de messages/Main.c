/*----------------------------------------------------------------------------------------------*/
/*									TP1 - Gestion de messages									*/
/*                                                                                              */
/*										    Module Main.c										*/
/*                                                                                              */
/* Fichier contenant le programme principal, test des fonctions de gestion de messagerie        */
/*----------------------------------------------------------------------------------------------*/

#include "TP1.h"

int main()
{
	int okL1 = 1, okL2 = 1, okL3 = 1;
	int okS1 = 1, okS2 = 1;
	cellule_t * tete = NULL;
	cellule_t * tete_vide = NULL;
	char * nom_fichier;

    /* Test de la lecture du fichier */
			/*fichier existant*/
	okL1 = LECTURE("messages.txt", &tete); 
	printf("Test de la fonction de lecture de fichier : ");
	if (okL1 == 1)
		printf("Erreur : fichier non lu \n\n");
	else
		printf("Fichier lu, liste chainee triée \n\n");
			/*fichier qui n'existe pas*/
	okL2 = LECTURE("messagges.txt", &tete); 
	printf("Test de la fonction de lecture de fichier : ");
	if (okL2 == 1)
		printf("Erreur : fichier non lu \n\n");
	else
		printf("Fichier lu, liste chainee triée \n\n");
			/*fichier vide*/
	okL3 = LECTURE("vide.txt", &tete);
	printf("Test de la fonction de lecture de fichier : ");
	if (okL3 == 1)
		printf("Erreur : fichier non lu \n\n");
	else
		printf("Fichier lu, liste chainee triée \n\n");
    /*Test de la sauvegarde de la liste chaînée dans un fichier */
			/*liste chaînée existante*/
	okS1 = SAUVEGARDE(tete, nom_fichier);   
	printf("\nTest de la fonction de sauvegarde de la liste chaînée : ");
	if (okS1 == 1)
		printf("Erreur : fichier non crée \n\n");
	else
		printf("Fichier crée \n\n");
			/*liste chaînée vide*/
	okS2 = SAUVEGARDE(tete_vide, nom_fichier);   
	printf("\nTest de la fonction de sauvegarde de la liste chaînée : ");
	if (okS2 == 1)
		printf("Erreur : fichier non crée \n\n");
	else
		printf("Fichier crée \n\n");
			
    /* Test de la fonction d'affichage des messages non expirés */

	AFF_NON_EXP(&tete);

    /* Test de la fonction de suppression des messages expirés */

	printf("\nTest de la fonction de suppression des messages expires\n\n");
	SUPP_MESS_EXP(&tete);
	printf("Messages expirés supprimés\n");
	SAUVEGARDE(tete, nom_fichier);

    /* Test de la fonction de modification d'une date de début connue */ 
			/*date deb_valid inexistante*/
	printf("\nTest de la fonction de modification d'une date de début connue :\n");
	MODIF_DATE_DEB(tete, 19980406, 19980608);
	printf("Date modifiée\n");
	SAUVEGARDE(tete, nom_fichier);
			/*date deb_valid existante*/
	printf("\nTest de la fonction de modification d'une date de début connue :\n");
	MODIF_DATE_DEB(tete, 19980405, 19980608);
	printf("Date modifiée\n");
	SAUVEGARDE(tete, nom_fichier);

	/*Libération de la liste chaînée*/

	SUPP_LCH(&tete);

	return 0;
}
