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

void push(struct pile *p, double val) {
    if (p->taille < CAPACITE) {
        p->tab[p->taille++] = val;
    } else {
        printf("pile est pleine\n");
    }
}

double pop(struct pile *p) {
    if (p->taille > 0) {
        return p->tab[--p->taille];
    } else {
        printf("pile est vide");
        return -1; // Valeur par défaut en cas d'erreur
    }
}

double evaluer(struct s *donnees) {
    struct pile p;
    p.taille = 0; // Initialiser la pile

    for (int i = 0; donnees[i].type != FIN; ++i) {
        switch (donnees[i].type) {
            case VAL:
                push(&p, donnees[i].data.val);
                break;

            case VAR:
                push(&p, *(donnees[i].data.var));
                break;

            case F1: {
                double val = pop(&p);
                push(&p, donnees[i].data.f1(val));
                break;
            }

            case F2: {
                double val1 = pop(&p);
                double val2 = pop(&p);
                push(&p, donnees[i].data.f2(val2, val1)); // Notez l'ordre des opérandes
                break;
            }

            default:
                // Gérer les erreurs ou les cas non pris en charge
                break;
        }
    }

    return pop(&p); // Retourne le résultat final
}


