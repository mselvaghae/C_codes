#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


void afficherDonnee(FILE * file, donnee_t essai) {
   if(file){
      fprintf(file,"%s : %s avec %d\n",essai.nom,essai.alias,essai.score);
   }
}

char * supenter(char * str){
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return str;
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
