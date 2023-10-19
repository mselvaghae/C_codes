#ifndef hall_of_fame_h
#define hall_of_fame_h

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin

#define TAILLE_MAX 1024

// on utilise lla list chainé de tete reel
typedef struct donnee{
    int score;
    char * nom;
    char * alias;
    struct donnee * next;
}  donnee_t;


/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t *);
char * supenter(char * str);
void saisirDonnee (FILE * , donnee_t *);
donnee_t * ListFromFilename(char * );
donnee_t * insereList(donnee_t *  , donnee_t * );
donnee_t * editerElement(donnee_t * head , int index);
void libererList(donnee_t * head);
// mettre ici les autres declarations

#endif