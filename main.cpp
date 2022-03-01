#include "list.h"
#include "list.c"
#include <stdio.h>
#include <iostream>
char* ecrireEntier(objet*objet){
int *entier=(int*)objet;
char* output=(char*)malloc(sizeof(int));
snprintf(output,sizeof(int),"%d\n",*entier);
return output;

}




int main()
{
    int num =0;
    int enter=0;
    Liste* lp= creerliste(0,ecrireEntier,NULL);

    while(enter==0){


       printf("pour inserer en tete entrer 1:\n  pour inserer en fin entrer 2 \n");
    scanf("%d",&num);

    switch(num){
    case 1:{
    printf("entrez un entier: en tete \n ");
    int * entier =(int*) malloc (sizeof(int));
    scanf("%d",entier);
    insererEnTeteDeListe(lp,entier);
    }break;
    case 2:{
    printf("entrez un entier: \n");
    int * entier4 =(int*) malloc (sizeof(int));
    scanf("%d",entier4);
    insererEnFinDeLISTE(lp,entier4);

    }break;
    default:
        printf("out of rang");
    }
  printf("vous voulez ajouter un nombre entrer 0\n");
  scanf("%d",&enter);


    }
//printf("le dernier element est \n %d",*((int*)lp->dernier->refer));



    /*printf("entrez un entier: en tete  ");
    int * entier =(int*) malloc (sizeof(int));
    scanf("%d",entier);
    insererEnTeteDeListe(lp,entier); printf("entrez un entier 2 en tete: ");
    int * entier2 =(int*) malloc (sizeof(int));
    scanf("%d",entier2);
    insererEnTeteDeListe(lp,entier2);
    printf("entrez un entier 3 inserer en tete: ");
    int * entier3 =(int*) malloc (sizeof(int));
    scanf("%d",entier3);
    insererEnTeteDeListe(lp,entier3);*/

   listerListe(lp);
   //afficherlc(lp);



    return 0;
}
