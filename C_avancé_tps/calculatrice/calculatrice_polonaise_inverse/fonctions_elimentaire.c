#include "code.h"

double mul (double a, double b){ return a*b;}
double add (double a, double b){return a+b;}
double sou (double a, double b){return a-b;}
double dyv (double a, double b){
    if(0==b){
        printf("valeur indeterminé");
        return -1;
    }
    return a/b;
}
double identite(double v) { return v;}
double erreur() {
    fprintf(stderr,"%s\n","erreur parametre ou la fonction");
    return -1; 
}