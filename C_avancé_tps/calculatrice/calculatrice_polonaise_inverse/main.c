#include<stdio.h>

#include "code.h"  // Assurez-vous que ce fichier existe et est correct
#include "teZZt.h" // Assurez-vous que ce fichier existe et est correct

//double (*tab2[]) (double, double) = { mul, add, NULL, sou, NULL, dyv };

int main() {
    char chain1[1024]="";  // Taille augmentée pour une chaîne de caractères plus réaliste
    char chain[1024]="";
    char exp1[7]="";
    char exp2[7]="";
    char op='0';
    double a=0, b=0, delta=0;

    printf("Mon beau petit programme principal\n");
    printf("Saisir respectivement :\n");
    printf("la fonction à afficher,\n");
    printf("les bornes de l'intervalle et la progression\n");
    fgets(chain, 1024, stdin);
    printf("....here...\n");
    fgets(chain1, 1024, stdin);

    
    //strncpy(chain1, chain, 15); 
    //chain1[16] = '\0'; // Assurez-vous que 'chain1' est terminée par '\0'

    // Supposons que les entiers commencent après les 7 premiers caractères
    int result = sscanf(chain, "%lf %lf %lf", &a, &b, &delta);
    int result1 = sscanf (chain1,"%s %c %s", exp1, &op, exp2);
    if (result != 3) { 
        printf("1 Échec de l'analyse des entrées.\n");
        return 0;
    }
    if (result1 != 3) { 
        printf(" 2 Échec de l'analyse des entrées.\n");
        return 0;
    }
	
    struct s donnees[] = {
        convertir(exp1),    
        convertir(exp2),     
        {F2, .data.f2 = tab2[op-'*']},       
        {FIN, {0}}                 
    };

    calcul(a, b, delta, donnees,stdout);
    return 0;
}
