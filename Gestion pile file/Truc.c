/*--------------------------------------------------------------------------------------*/
/*						TP2 - Gestion d'une pile et d'une file							*/
/*											Truc.c										*/
/*--------------------------------------------------------------------------------------*/

#include "Truc.h"

/*--------------------------------------------------------------------------------------*/
/* TRUC_REC		        	Retourne toutes les permutations n-i+1 derniers éléments    */
/*                          d'un tableau initial de manière récursive                  	*/
/*																						*/
/*  Algorithme de principe																*/
/*							- Si l'indice i est supérieur à la taille du tableau: on    */
/*                          retourne un message d'erreur                    			*/
/*                          - Sinon                                                     */
/*                              - Si l'indice i est égal à la taille du tableau: on     */
/*                                affiche le tableau                                    */
/*                              - Sinon :                                               */
/*                                  - Pour j allant de i à n :                          */
/*                                      - On échange les i-ème et j-ème éléments du     */
/*                                      tableau                                         */
/*                                      - On affiche le tableau                         */
/*                                      - On rééchange les i-ème et j-ème éléments du     */
/*                                      tableau                                         */
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : i 			Indice à partir duquel on commence les permutations  		*/
/*              n           Taille du tableau                                           */
/*              T           Tableau donnée en entrée indicé à partir de 0               */	
/*--------------------------------------------------------------------------------------*/

void TRUC_REC(int i, int n, element_pile *T)
{
    int j;
    element_pile temp;
    if (i > n-1)
    {
        printf("Erreur: l'indice i est superieur a la taille du tableau");
    }
    else
    {
        if (i == n-1)
        {
            for (j=0; j<n; j++)
                printf(format, T[j]);
            printf("\n");
         }
         else
        {
            for (j=i; j<n; j++)
            {
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
                TRUC_REC(i+1,n,T);
                temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
}

/*--------------------------------------------------------------------------------------*/
/* ECHANGE		             Echange deux éléments dans un tableau                     	*/
/*																						*/
/*  Algorithme de principe																*/
/*							- On crée une variable temporaire pour sauvegarder          */
/*                            l'élément d'indice i                            			*/
/*                          - On remplace l'élément d'indice i par celui d'indice j     */
/*                          - On remplace l'élément d'indice j par celui sauvegarder    */
/*                            dans temp                                                 */
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : i,j 		Indices des deux éléments à changer                  		*/
/*              T           Tableau donnée en entrée indicé à partir de 0               */	
/*--------------------------------------------------------------------------------------*/


void ECHANGE(int i, int j, element_pile * T)
{
    int temp;
    temp = T[i];
    T[i] = T[j];
    T[j] = temp;
}


/*--------------------------------------------------------------------------------------*/
/* TRUC_ITER		        Retourne toutes les permutations n-i+1 derniers éléments    */
/*                          d'un tableau initial de manière itérative                  	*/
/*																						*/
/*  Algorithme de principe																*/
/*							- On initialise la pile                         			*/
/*                          - Tant que la variable d'arrêt est nulle:                  */
/*                              - Si l'indice i est inférieur à la taille du tableau -1 */
/*                                  - On empile l'élement i puis l'élément j            */
/*                                  - On échange les éléments d'indice i et j           */
/*                                  - On incrémente i                                   */
/*                                  - On affecte i à j                                  */
/*                              - Sinon (soit i = n):                                   */
/*                                  - On affiche le tableau                             */
/*                                  - Répéter:                                          */
/*                                      - Si la variable d'arrêt est nulle :            */
/*                                          - On dépile en affectant à j l'élément du   */
/*                                          sommet                                      */
/*                                          - On dépile en affectant à i l'élément du   */
/*                                          sommet                                      */
/*                                          - On échange les éléments d'indice i et j   */
/*                                          - On incrémente j                           */
/*                                      - Sinon: on affecte 1 à la variable d'arrêt     */
/*                                  Jusqu'à ce que j soit inférieur à n-1 et que la     */
/*                                  variable d'arrêt soit égale à 1                     */
/*																						*/
/*  Lexique																				*/
/*																						*/
/*	En entrée : i 			Indice à partir duquel on commence les permutations  		*/
/*              n           Taille du tableau                                           */
/*              T           Tableau donnée en entrée indicé à partir de 0               */
/*                                                                                      */
/* Variables temporaires:                                                               */
/*              k,j         Indices pour parcourir le tableau                           */
/*              stop        Entier qui arrête le programme si elle vaut 1 et 0 sinon    */
/*              pile        Pointeur sur le bloc de tête de la pile                     */	
/*--------------------------------------------------------------------------------------*/

void TRUC_ITER(int i, int n, element_pile * T)
{
    int k, j = i, stop = 0;
    pile_t * pile = NULL;
    pile = INIT_PILE(2*n);
    while (!stop)
    {
        if (i<n-1)
        {
            EMPILER(pile, i);
            EMPILER(pile, j);
            ECHANGE(i,j,T);
            i++;
            j = i;
        }
        else
        {
            for (k = 0; k<n; k++)
                printf(format, T[k]);
            printf("\n");
            do
            {   if(!PILE_VIDE(pile))
                {
                    j = DEPILER(pile);
                    i = DEPILER(pile);
                    ECHANGE(i,j,T);
                    j++;
                }
                else
                    stop = 1;
            }while((!stop) && j>n-1);
        }
    }
}