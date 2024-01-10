#include<stdio.h>

#include "code.h"  // Assurez-vous que ce fichier existe et est correct
#include "teZZt.h" // Assurez-vous que ce fichier existe et est correct

int main() {
    char chain1[10]="";  // Taille augmentée pour une chaîne de caractères plus réaliste
    char chain[1024]="";
    double a=0, b=0, delta=0;

    printf("Mon beau petit programme principal\n");
    printf("Saisir respectivement :\n");
    printf("la fonction à afficher,\n");
    printf("les bornes de l'intervalle et la progression\n");
    fgets(chain, 1024, stdin);

    
    strncpy(chain1, chain, 6); 
    chain1[9] = '\0'; // Assurez-vous que 'chain1' est terminée par '\0'

    // Supposons que les entiers commencent après les 7 premiers caractères
    int result = sscanf(chain + 7, "%le %le %le", &a, &b, &delta);
    if (result != 3) { 
        printf("Échec de l'analyse des entrées.\n");
        return 0;
    }
	//printf("%s %d %d %d",chain1,a,b,delta);
	//pri

    calcul(a, b, delta, identification_enum(chain1), stdout);
    return 0;
}
