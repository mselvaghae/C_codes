#ifndef GARDIEN_UNIQUE_CODE_H
#define GARDIEN_UNIQUE_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef enum ope {
  NONE = -1, ID , SIN, COS, LOG, EXP
} OP;


int identification(char *str);
int identification_enum(char *str);
double identite(double v);
/*double sin(double v);
double cos(double v);
double log(double v);
double exp(double v);*/
double erreur() ;


double evalf(double v , OP operations);
double evalp(double v , OP operations);
void calcul (double a,double b, double delta , OP operation , FILE * file);
//pret





// fichier d'entete classique ou l'on declare les types necessaires, 
// les fonctions implementees dans le fichier .c
// les declaration de variables globales externes

#endif
