#ifndef _FLOOD_IT_H
#define _FLOOD_IT_H

#define COULEUR 6
#define TAILL 12
#define MAXCOUP 22 

int initGame(int matGame[TAILL][TAILL]);
int afficheGame(int matGame[TAILL][TAILL]);
void remplirGame(int matGame[TAILL][TAILL], int CouleurChoisi, int CouleurOriginale, int ligne, int colonne );
int fin(int matGame[TAILL][TAILL]);


#endif