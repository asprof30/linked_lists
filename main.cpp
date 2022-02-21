#include "list.h"
#include "list.c"
#include <stdio.h>




int main()
{
    Liste* lp= creerliste(0,NULL,NULL);
    printf("entrez un entier: ");
    int * entier =(int*) malloc (sizeof(int));
    scanf("%d",entier);
    insererEnTeteDeListe(lp,entier); printf("entrez un entier 2: ");
    int * entier2 =(int*) malloc (sizeof(int));
    scanf("%d",entier2);
    insererEnTeteDeListe(lp,entier2);
    printf("entrez un entier 3: ");
    int * entier3 =(int*) malloc (sizeof(int));
    scanf("%d",entier3);
    insererEnTeteDeListe(lp,entier3);
    afficherlc(lp);


    return 0;
}
