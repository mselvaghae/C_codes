#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


void afficherDonnee(FILE * file, donnee_t essai) {
   if(file){
      fprintf(file,"%s : %s avec %d\n",essai.nom,essai.alias,essai.score);
   }
}
char *enlevalaligne(char *s) {
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        i++;
    }

    char *res = (char *)malloc((i + 1) * sizeof(char));
    if (res == NULL) {
        return NULL;  // Handle memory allocation failure
    }

    // Copy characters from s to res
    for (int j = 0; j < i; j++) {
        res[j] = s[j];
    }
    res[i] = '\0';  // Null-terminate the result

    return res;
}

void saisirDonnee(FILE *file, donnee_t *essai) {
    if (file) {
        if (fscanf(file,"%s",essai->nom) ==EOF) { 
            fprintf(stderr, "Error reading essai->nom.\n");
            return; 
        }
        if (fscanf(file,"%s",essai->alias) == EOF) {
            fprintf(stderr, "Error reading essai->alias.\n");
            return; 
        }
        if (fscanf(file,"%d", &essai->score) == EOF) {
            fprintf(stderr, "Error reading essai->score.\n");
            return; 
        }
    }
}

int tableauFromFilename(char * name, donnee_t * tableau){
    FILE * file = fopen(name,"r");
    int taille = 0 ;
    if(file){
        do {
           saisirDonnee(file,(tableau+taille));
            taille++;
        }while(!feof(file));
        fclose(file);
    }
    return taille ; 
}
