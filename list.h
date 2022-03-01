#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

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

}Liste;

void initListe(Liste *li,int type,char *(*afficher)(objet*),int(*comparer)(objet*,objet*));
Liste * creerliste(int type,char*(*afficher)(objet*),int (*comparer)(objet*,objet*));
static Element*  creeElement();
void insererEnTeteDeListe(Liste*li,objet*objet);
void afficherlc(Liste*li);
void insererEnFinDeLISTE(Liste*li,objet*objet);
static void insererapres(Liste*li,Element* precedent,objet*objet);

#endif // LIST_H_INCLUDED

