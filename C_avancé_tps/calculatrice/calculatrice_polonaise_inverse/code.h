#ifndef GARDIEN_UNIQUE_CODE_H
#define GARDIEN_UNIQUE_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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





int identification_enum(char *str);

double mul (double a, double b);
double add (double a, double b);
double sou (double a, double b);
double dyv (double a, double b);
double identite(double v);
double erreur() ;

double elementaire_optimale(double a ,double b,char c);
double evalp(double v , OP operations);
void calcul (double a,double b, double delta ,OP exp1 ,OP exp2,char op, FILE * file);


#endif
