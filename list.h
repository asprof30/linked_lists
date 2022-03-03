#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdbool.h>
typedef void objet;


typedef struct element{
objet* refer;
struct element * suivant;
}Element;

typedef struct{
Element *premier;
Element *dernier;
Element *courant;
int nbElt;
int type;
char* (*afficher)(objet*);
int (*comparer)(objet*,objet*);

}Liste;

void initListe(Liste *li,int type,char *(*afficher)(objet*),int(*comparer)(objet*,objet*));
Liste * creerliste(int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*));
static Element*  creeElement();
void insererEnTeteDeListe(Liste*li,objet*objet);
void afficherlc(Liste*li);
void insererEnFinDeLISTE(Liste*li,objet*objet);
static void insererapres(Liste*li,Element* precedent,objet*objet);
objet*chercherObjet(Liste li,objet*objetchercher);
objet* extraireEnTeteDeListe (Liste* li);
static objet* extraireApres (Liste* li, Element* precedent) ;
objet* extraireEnFinDeListe (Liste* li);
bool extraireUnobjet (Liste* li, objet* objet);
void detruireListe (Liste* li);


#endif // LIST_H_INCLUDED

