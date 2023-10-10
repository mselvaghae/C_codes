#ifndef _SUDOKU_H
#define _SUDOKU_H

#define N 9
#define HORZT 0
#define VERT 1
#define DIFICULTY 9
#define FACILITY 9

int initPlan(int grill[N][N]);/*creer la grill à partir d'une expressions matématique connu*/

int initFicher(FILE * file , int grill[N][N]);/*creer la grill à partir d'une fichier*/

int  saisirNumber(int grill[N][N]);

int verifieLigneColone(int grill[N][N], int nomber , int sens, int lignej , int colonei);

int verifieRgeion(int grill[N][N], int k , int l );

int VerifieGrill(int grill[N][N]);

void printPlan(int grill[N][N]);


#endif