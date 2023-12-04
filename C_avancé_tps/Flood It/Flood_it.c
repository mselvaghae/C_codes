#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Flood_it.h"

int initGame(int matGame[TAILL][TAILL]) {
    
    
    for (int i = 0; i < TAILL; i++) {
        for (int j = 0; j < TAILL; j++) {
            matGame[i][j] = rand() % COULEUR;
        }
    }
    
    return 0;
}

void remplirGame(int matGame[TAILL][TAILL], int CouleurChoisi, int CouleurOriginale, int ligne, int colonne ) {
    if (!(ligne < 0 || ligne >= TAILL || colonne < 0 || colonne >= TAILL || matGame[ligne][colonne] != CouleurOriginale|| CouleurChoisi == CouleurOriginale)) {
       matGame[ligne][colonne] = CouleurChoisi;
       remplirGame(matGame, CouleurChoisi, CouleurOriginale, ligne - 1, colonne); 
       remplirGame(matGame, CouleurChoisi, CouleurOriginale, ligne + 1, colonne); 
       remplirGame(matGame, CouleurChoisi, CouleurOriginale, ligne, colonne - 1); 
       remplirGame(matGame, CouleurChoisi, CouleurOriginale, ligne, colonne + 1); 
    } 

 
}



int fin(int matGame[TAILL][TAILL]){
    for (int i = 0; i < TAILL; i++) {
        for (int j = 0; j < TAILL; j++) {
            if(matGame[i][j] != matGame[0][0])
              return 0;
        }
        printf("\n");
    }
    
    return 1;
}
