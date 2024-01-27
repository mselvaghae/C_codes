#include "code.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// ********************************************************
//  TESTS DES FONCTIONS POUR FICHIERS STATIQUES
// ********************************************************

void static_insert(char fichier[LINES][COLUMNS], int i) {
  
}

void static_export(FILE * file, char fichier[LINES][COLUMNS]) {
    
}

void static_import_text(char * nom, char fichier[LINES][COLUMNS]) {
    
}

// ********************************************************
//  TESTS DES FONCTIONS POUR FICHIERS DYNAMIQUES
// ********************************************************


text * dynamic_import_text(char * nom) {

    return NULL;  
}

void dynamic_export(FILE * file, text * t) {
    
}

void dynamic_insert(text ** t, int i) {
  
}

void dynamic_add(text ** t, char * chaine) {
  
}

void dynamic_free(text ** t) {
  
}

// ********************************************************
//  TESTS DES FONCTIONS UTILITAIRES
// ********************************************************

int is_header(char * ligne) {

  return -1;
} 

void emphasis(char * ligne) {
   
}

void strong_emphasis(char * ligne) {
  
}

void static_transform(char dest[LINES][COLUMNS], char source[LINES][COLUMNS]) {
 
}

text * dynamic_transform(text * src) {
 
  return NULL;
}
