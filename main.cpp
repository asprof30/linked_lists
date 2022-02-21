#include "list.h"
#include "list.c"
#include <stdio.h>




int main()
{
    Liste* lp= creerliste(0,NULL,NULL);
    printf("entrez un entier ");
    int * entier =(int*) malloc (sizeof(int));
    scanf("%d",entier);
    insererEnTeteDeListe(lp,entier);
    printf("le premier entier est :%d",(*((int *)lp->premier->refer)));

    return 0;
}
