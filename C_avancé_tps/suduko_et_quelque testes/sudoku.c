#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<time.h>
#include "sudoku.h"

int main(){
   srand(time(NULL));

   printf("/**                             *******SUDOKU*******                                **/\n");
   
   int grill[N][N] = {{0}} ;
   int remplisage = 0;
   FILE * file = fopen("sudoku.txt","r");


    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

   //int * tab = (int *)malloc(4 * sizeof(int));

   remplisage+=/*initPlan(grill)*/initFicher(file,grill);

   while(remplisage < N*N)
   {
    printf("le nombre des cases remplis est %d\n", remplisage);
    
    printPlan(grill);

    //tab = saisirNumber(grill);

    remplisage+=/*tab[3]*/saisirNumber(grill);
   }
    //free(tab);
    printPlan(grill);
   
   {(VerifieGrill(grill))? printf("merci ,vous avez perdu :(\n") :  printf("merci ,vous avez gagné ;)\n") ;}

   fclose(file);
}


int initPlan(int grill[N][N]){
    int remplisage =0;
    for (int j =0; j < N ; j ++){
        for (int i =0; i < N ; i ++){
            if (rand()%10 < FACILITY){
                grill[j][i] = (i + j*3 +j /3) %9 +1 ;
                remplisage++;
            }            
        }   
    }
    return remplisage;

}

int initFicher(FILE * file , int grill[N][N]){
  int remplisage =0;
    for (int j =0; j < N ; j ++){
        for (int i =0; i < N ; i ++){
           
            fscanf(file,"%d ",&grill[j][i]);
            if (rand()%10 < DIFICULTY){
                grill[j][i] = 0 ;
                remplisage++;
            }                        
        }   
    }
    return remplisage;  
}

int  saisirNumber(int grill[N][N]) {
    //int * Donnée = (int *)malloc(4 * sizeof(int));
    int remplisage =0 ;
    bool arreter = false;
    int i , j , valeur;

    printf("Saisir le numéro de ligne, puis le numéro de colonne (les deux doivent être entre 0 et 8), et enfin la valeur que vous souhaitez (entre 1 et 9).\n");

    while (!arreter) {
        scanf("%d %d %d", &j, &i, &valeur);

        if ((i >= 0 && i <= 8) && (j >= 0 && j <= 8) && (valeur >= 1 && valeur <= 9)) {
            if (grill[j][i] == 0) {
                grill[j][i] = valeur;
                arreter = true;
                remplisage++;
            } else {
                printf("La place est déjà occupée. Saisir de nouveaux numéros (les deux uniquement, votre valeur choisie est enregistrée) encore !!\n");
            }
        } else {
            printf("Mauvais numéro de ligne, colonne ou valeur saisie. Saisir de nouveaux numéros (les deux uniquement, votre valeur choisie est enregistrée) encore !!\n");
        }
    }
    /*Donnée[0]=j;
    Donnée[1]=i;
    Donnée[2]=valeur;
    Donnée[3]=remplisage;*/

    return /*Donnée*/remplisage;
    //free(Donnée);
}

int verifieLigneColone(int grill[N][N], int nomber, int sens, int lignej, int colonei) {
    int result = 1;

    if (lignej < 0 || lignej >= N || colonei < 0 || colonei >= N) {
       return 0; // Invalid indices, return 0
    }
   if (sens == HORZT) 
   {
    for (int i = 0; i < N; i++) {
        if ( i != colonei && grill[lignej][i]  ==  nomber ) {
            result = 0; // Number already exists in the same row, return 0
        }
    }
   } else 
   {
    for (int i = 0; i < N; i++) {
        if (i != lignej && grill[i][colonei] ==  nomber  ) {
            result = 0; // Number already exists in the same column, return 0
        }
    }
   }
    
    return result;
}


int verifieRgeion(int grill[N][N], int k, int l) {
    int result = 1;
    for (int i = 0; i < 3 && result; i++) {
        for (int j = 0; j < 3 && result; j++) {
            if (!(verifieLigneColone(grill, grill[k * 3 + i][l * 3 + j], HORZT, k * 3 + i, l * 3 + j) &&
                  verifieLigneColone(grill, grill[k * 3 + i][l * 3 + j], VERT, k * 3 + j, l * 3 + i))) {
                result = 0;
            }
        }
    }
    return result;
}


int VerifieGrill(int grill[N][N]){
    int result = 1;
    for (int i = 0  ; i < 3 ; i ++){
        for (int j = 0  ; j < 2 ; j ++){
            if(!verifieRgeion(grill,i,j)){
                result = 0;
            }
        }
    }
    return result;
}

void printPlan(int grill[N][N]){
    for (int i =0; i < N ; i ++){
        for (int j =0; j < N ; j ++){
            printf("%d (%d,%d)| ", grill[i][j],i,j);
        }
        printf("\n");
    }
    printf("\n");    
}
