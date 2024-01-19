#include "code.h"


const char * EXP_NAMES[]= { "x", "sin(x)", "cos(x)", "log(x)", "exp(x)", NULL }; 
OP operations[] = {ID, SIN, COS, LOG, EXP};


double (*tab2[]) (double, double) = { mul, add, NULL, sou, NULL, dyv };
double (*OPER_FN [])(double) = { identite, sin, cos, log, exp, erreur };

struct s donnees[256];

int identification_enum(char *str){
    for (int i=0 ; EXP_NAMES[i]!= NULL ; i++){
        if(strcmp(str,EXP_NAMES[i])==0) return operations[i];
    }
    return NONE;
}


double elementaire_optimale(double a ,double b,char c){
    if((c-'*' <= -1 || c-'*' >= 6 ) || tab2[c-'*']==NULL){
        printf("\noperation n'existe pas\n");
        return -1;
    }
    return tab2[c-'*'](a,b);
}


double evalp(double v , OP operations){
    if (NONE  == operations) { return erreur();}
    return (*OPER_FN[operations])(v);
}

void calcul (double a,double b, double delta , OP exp1 , OP exp2,char op, FILE * file){
    if(exp1 == NONE || exp2 == NONE) {return;}
    for (int i=0; i < (int)((b-a)/delta); i++){
        fprintf(file,"%f ",elementaire_optimale(evalp(a+i*(delta),exp1),evalp(a+i*(delta),exp2),op));
    }
    fprintf(file,"%f\n",elementaire_optimale(evalp(a+((int)((b-a)/delta))*(delta),exp1),evalp(a+((int)((b-a)/delta))*(delta),exp2),op));
    
}
