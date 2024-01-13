#include "code.h"

const char * OPER_NAMES[]= { "x", "sin(x)", "cos(x)", "log(x)", "exp(x)", NULL }; 
OP operations[] = {ID, SIN, COS, LOG, EXP};

double identite(double v) { return v;}

/*double sin(double v) { return sin(v);}
double cos(double v) { return cos(v);}
double log(double v) { return log(v);}
double exp(double v) { return exp(v);}*/

double erreur() {
    fprintf(stderr,"%s\n","erreur parametre ou la fonction");
    return -1; 
}

double (*OPER_FN [])(double) = { identite, sin, cos, log, exp, erreur };

int identification(char *str){
    for (int i=0 ; OPER_NAMES[i]!= NULL ; i++){
        if(strcmp(str,OPER_NAMES[i])==0) return i;
    }
    return -1;

}

int identification_enum(char *str){
    for (int i=0 ; OPER_NAMES[i]!= NULL ; i++){
        if(strcmp(str,OPER_NAMES[i])==0) return operations[i];
    }
    return NONE;
}

double evalf(double v , OP operations){
    double result = 0;
    switch (operations){
        case ID :
         result = v;
        break;
        case SIN :
         result = sin (v);
        break;
        case COS:
         result = cos(v);
        break;
        case EXP:
         result = exp(v);
        break; 
        case LOG:
         result = log(v);
        break; 
        case NONE:
         printf("not operation chosen");
         return 0.0;
        break;
    }
    return result;
}

double evalp(double v , OP operations){
    if (NONE  == operations) { return erreur();}
    return (*OPER_FN[operations])(v);
}

void calcul (double a,double b, double delta , OP operation , FILE * file){
    if(operation == NONE) {return;}
    for (int i=0; i < (int)((b-a)/delta); i++){
        fprintf(file,"%f ",evalf(a+i*(delta),operation));
    }
    fprintf(file,"%f\n",evalf(a+((int)((b-a)/delta))*(delta),operation));
    
}
//pris


// implementation des fonctions declarees dans le fichier .h
// definition eventuelle des variables globales s'il y en a