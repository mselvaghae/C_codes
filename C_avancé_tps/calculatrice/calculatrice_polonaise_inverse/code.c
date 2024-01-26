#include "code.h"


const char * EXP_NAMES[]= { "x", "sin(x)", "cos(x)", "log(x)", "exp(x)", NULL }; 
OP operations[] = {ID, SIN, COS, LOG, EXP};

double var = 0;
double (*tab2[]) (double, double) = { mul, add, NULL, sou, NULL, dyv };
double (*OPER_FN [])(double) = { identite, sin, cos, log, exp, erreur };


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

struct s convertir(char * str){
    struct s donnee ;
    if (identification_enum(str)!=NONE && identification_enum(str) != ID){
        donnee.type = F1;
        donnee.data.f1 = (*OPER_FN[identification_enum(str)]);
    }else {
        if (identification_enum(str) == ID) {
            donnee.type = VAR;
            donnee.data.var = &var;
        }else {
            donnee.type = VAL;
            donnee.data.val = atof(str);
        }
    }

    return donnee;
}

void calcul (double a,double b, double delta , struct s * donnees, FILE * file){
    //if(exp1 == NONE || exp2 == NONE) {return;}
    for (int i=0; i < (int)((b-a)/delta); i++){
        var = i;
        fprintf(file,"%f ",evaluer(donnees));
    }
    var = a+((int)((b-a)/delta));
    fprintf(file,"%f\n",evaluer(donnees));
    
}


