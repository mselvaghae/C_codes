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

void saisirDonnee(FILE *file, donnee_t * essai){
   
   if(file){
      char str[1024];
      fgets(essai->nom,100,file);
      //strcpy(srt,essai->nom);
      fgets(essai->alias,40,file);
      fgets(str,100,file);
      
      essai->score =atoi(str);
   }
   
   /*enlevalaligne(essai->nom);
   enlevalaligne(essai->alias);*/
  

}
