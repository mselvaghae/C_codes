#include "code.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void stats1(char *texte, int *nb_chars, int * nb_lignes, int * nb_mots){
 
}   


long taille_fichier(char * nom) {
  FILE * f  = fopen(nom, "rb");
  long r = 0;
  if (f) {
    fseek(f, 0, SEEK_END);
    r = ftell(f);
    fclose(f);
  }
  return r;
}

char * lecture(char * nom) {
 

  return NULL;
} 

void initialiser( info * infos) {
 
}

void inserer(info * infos, char * mot ){
 
} 

void stats2(char *texte, info * infos, int *nb_chars, int * nb_lignes, int * nb_mots){
 
}   

int total_mots(info * infos ) {
  return 0;
}

int total_mots_distincts(info * infos) {
  return 0;
}
