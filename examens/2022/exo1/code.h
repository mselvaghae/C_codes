#ifndef CODE_EXO1
#define CODE_EXO1

#include<stdio.h>

// conversion hexadecimal en decimal
int convert_to_d(char *);

// partie sur les nombres premiers et la decomposition
int  is_prime(int);
void facteurs_simple(char *, int);
void facteurs(char *, int);

// creation, lecture et multiplication de matrices carrees
double ** creer_id(int);
double ** lire_mat(char*, int*);
double ** multiplication(double **, double **, int);
void liberer(double **, int);
   

#endif