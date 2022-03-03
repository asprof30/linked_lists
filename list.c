#include "list.h"
#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
objet* extrait;

//fonction d'initialisation:
void initListe(Liste *li,int type,char *(*afficher)(objet*),int(*comparer)(objet*,objet*)){
li->premier=NULL;
li->dernier=NULL;
li->courant=NULL;
li->nbElt=0;
li->type=type;
li->afficher=afficher;

}


//fonction de creation
Liste * creerliste(int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*)){
Liste*li=(Liste*)malloc(sizeof(Liste));
initListe(li,type,afficher,comparer);
return li;
}

bool listeVide(Liste* li){
return li->nbElt==0;
}


int nbElement(Liste* li){
return li->nbElt;

}

//fonction pour allouer l'espace memoire a un element:
static Element*  creeElement(){
return (Element*)malloc(sizeof(Element));

}


//fonction pour inserer entete
void insererEnTeteDeListe(Liste*li,objet* objet){
Element* nouveau=creeElement();
nouveau->refer=objet;
nouveau->suivant=li->premier;
li->premier=nouveau;
if(li->dernier==NULL)li->dernier=nouveau;
li->nbElt++;



}
void afficherlc(Liste*li){
    int i =0;
    li->courant = li->premier;
while(i<li->nbElt)
{
    printf("--%d-",*((int *)li->courant->refer));
    li->courant=li->courant->suivant;
    i++;
}
}

//fonction pour inserer apres un element precedent
static void insererapres(Liste*li,Element* precedent,objet*objet){
if(precedent==NULL){

    insererEnTeteDeListe(li,objet);
}else{
 Element*nouveau =creeElement();
 nouveau->refer=objet;
 nouveau->suivant=precedent->suivant;
 precedent->suivant=nouveau;
 if(precedent==li->dernier){
    li->dernier=nouveau;
 }
}
}

//fonction pour inserer en fin de liste(apres le dernier element)
void insererEnFinDeLISTE(Liste*li,objet*objet){
insererapres(li,li->dernier,objet);

}



void ouvrirListe(Liste*li){
li->courant=li->premier;
}

bool finListe(Liste*li){
return li->courant==NULL;

}


static Element* elementCourant(Liste*li){
Element * ptc=li->courant;
if(li->courant!=NULL){

    li->courant=li->courant->suivant;
}
return ptc;

}


objet* objetCourant(Liste* li){
Element* ptc=elementCourant(li);
return ptc==NULL ? NULL:ptc->refer;

}

void listerListe(Liste * li){
ouvrirListe(li);
while(!finListe(li)){
    objet *objet=objetCourant(li);
    printf("-%s-",li->afficher(objet));

}
}
//fonction pour chercher un objet dans la liste
objet*chercherUnObjet(Liste* li,objet* objetCherche){
bool trouve=false;
objet*objet;
ouvrirListe(li);
while(!finListe(li)&&!trouve){
    objet = objetCourant (li);
    trouve = li->comparer (objetCherche, objet)==0;
  }
  return trouve ? objet : NULL;
}
//fonction pour extraire un element entete d'une liste
objet* extraireEnTeteDeListe (Liste* li) {
  Element* extrait = li->premier;
  if (!listeVide (li)) {
     li->premier = li->premier->suivant;
    if (li->premier=NULL) li->dernier=NULL;
     li->nbElt--;
  return extrait != NULL ? extrait->refer : NULL;
}
}
//fonction pour extraire un element apres un precedent
static objet* extraireApres (Liste* li, Element* precedent) {
  if (precedent == NULL) {
    return extraireEnTeteDeListe (li);
   } else {
    Element* extrait = precedent->suivant;
   if (extrait != NULL) {
      precedent->suivant = extrait->suivant;
      if (extrait == li->dernier) li->dernier = precedent;
      li->nbElt--;
    }
    return extrait != NULL ? extrait->refer : NULL;
  }
}
//fonction extraire un element en fin de liste

objet* extraireEnFinDeListe (Liste* li) {
  objet* extrait;
  if (listeVide (li)) {
    extrait = NULL;
   } else if (li->premier == li->dernier){
    extrait = extraireEnTeteDeListe (li);
   } else {
    Element* ptc=li->premier;
    while (ptc->suivant != li->dernier) ptc = ptc->suivant;
    extrait = extraireApres (li, ptc);
  }
  return extrait;
}
bool extraireUnobjet (Liste* li, objet* objet) {

  Element* precedent = NULL;
  Element* ptc = NULL;
  bool trouve = false;
  ouvrirListe (li);
  while (!finListe (li) && !trouve) {
    precedent = ptc;
    ptc= elementCourant (li);
    trouve =(ptc->refer == objet) ? true : false;
  }
  if (!trouve){
    return false;
  }
  extrait= extraireApres (li, precedent);
  return true;
}


void detruireListe (Liste* li) {
  ouvrirListe (li);
 while (!finListe (li)) {
    Element* ptc = elementCourant (li);
    //free (ptc->reference);
    free (ptc);
    char* t;
  initListe (li,5,t,7);
}
}





