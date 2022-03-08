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

int comparer(objet* objet1, objet* objet2) {
int *entier1=(int*)objet1;
int *entier2=(int*)objet2;
if (entier1>entier2) return 1;
else if (entier1<entier2) return -1;
else return 0;}



int main()
{
    int num =0;
    int enter=0;
    Liste* lp= creerliste(0,ecrireEntier,comparer);

    while(enter==0){

       printf("pour inserer en tete entrer 1:\npour inserer en fin entrer 2 \npour supprimer en tete entrer 3 \npour supprimer en fin entrer 4 \npour supprimer apres un objet entrer5 \n");
    scanf("%d",&num);

    switch(num){
    case 1:{
    printf("1-entrez un entier: en tete \n ");
    int * entier =(int*) malloc (sizeof(int));
    scanf("%d",entier);
    insererEnTeteDeListe(lp,entier);
    }break;
    case 2:{
    printf("2-entrez un entier: \n");
    int * entier4 =(int*) malloc (sizeof(int));
    scanf("%d",entier4);
    insererEnFinDeLISTE(lp,entier4);

    }break;
    case 3:{
    extraireEnTeteDeListe(lp);
    }break;
    case 4:{
    extraireEnFinDeListe(lp);
    }break;
    case 5:{
            printf("entrez un entier à supprimer: \n");
            Element * entier4 =(Element*) malloc (sizeof(Element));
            scanf("%d",entier4);
            extraireUnobjet(lp,entier4);
    }break;
    default:
        printf("out of rang");
    }
        listerListe(lp);

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
