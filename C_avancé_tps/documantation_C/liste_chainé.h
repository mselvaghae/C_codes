#ifndef _LIST_CHAINE_H
#define _LIST_CHAINE_H

#define Max_long 255

typedef struct cellule {
   // char ligne[255]; //statique
    char * ligne;
    struct cellule * suiv;
} cellule_t;

typedef struct liste {
    cellule_t * tete;
    cellule_t * fin;
} liste_t;

int estvide (liste_t *list);
void initialiser_liste (liste_t *list);
char * supenter(char * str);
cellule_t * cree_une_cellule (char * ligne);
void inserer_cellule_fin (liste_t * list ,cellule_t *);
void afficherDonnee(FILE * file, liste_t * list);
void libererList(liste_t * list);

#endif