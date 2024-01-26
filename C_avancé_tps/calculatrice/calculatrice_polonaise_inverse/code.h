#ifndef GARDIEN_UNIQUE_CODE_H
#define GARDIEN_UNIQUE_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define CAPACITE 75


typedef enum ope {
  NONE = -1, ID , SIN, COS, LOG, EXP
} OP;

enum e{
     VAL, VAR, F1, F2, FIN
} ;

union u {
     double   val;
     double * var;
     double (*f1)(double);
     double (*f2)(double, double);
};

struct s {
     enum  e type;
     union u data;
};

typedef struct pile {
  double tab[CAPACITE];
  int taille;
} pile_t;



void push(struct pile *p, double val);
double pop(struct pile *p);

int identification_enum(char *str);

double mul (double a, double b);
double add (double a, double b);
double sou (double a, double b);
double dyv (double a, double b);


double identite(double v);
double erreur() ;


double elementaire_optimale(double a ,double b,char c);
double evalp(double v , OP operations);
void calcul (double a,double b, double delta ,struct s * donnees, FILE * file);

double evaluer(struct s *donnees);
struct s convertir(char * str);




#endif
