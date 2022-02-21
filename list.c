#include "list.h"
#include <math.h>
#include <stdio.h>
#include <stddef.h>
void initListe(Liste *li,int type,char *(*afficher)(objet*),int(*comparer)(objet*,objet*)){
li->premier=NULL;
li->dernier=NULL;
li->courant=NULL;
li->nbElt=0;
li->type=type;
li->afficher=afficher;

}
Liste * creerliste(int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*)){
Liste*li=(Liste*)malloc(sizeof(Liste));
initListe(li,type,afficher,comparer);
return li;
}
static Element*  creeElement(){
return (Element*)malloc(sizeof(Element));

}
void insererEnTeteDeListe(Liste*li,objet* objet){
Element* nouveau=creeElement();
nouveau->refer=objet;
nouveau->suivant=li->premier;
li->premier=nouveau;
if(li->dernier==NULL)li->dernier=nouveau;
li->nbElt++;

}
