#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Flood_it.h"

int main() {
    srand(time(NULL));
    int matGame[TAILL][TAILL];
    initGame(matGame);
    int coupCounter = 0;
    int CouleurChoisi = -1;
    int CouleurOriginale = matGame[0][0];
    bool stop = false;
    
    while (coupCounter < MAXCOUP) {
        afficheGame(matGame);
        printf("Pick one color: ");
        stop = false;
        CouleurOriginale = matGame[0][0];
        while (!stop) {
            scanf("%d", &CouleurChoisi);
            if (CouleurChoisi < 0 || CouleurChoisi >= COULEUR) {
                printf("Pick a color between 0 and %d: ", COULEUR - 1);
            } else {
                stop = true;
            }
        }
        
        remplirGame(matGame, CouleurChoisi, CouleurOriginale, 0, 0);
        coupCounter++;
    }
    
    afficheGame(matGame);

    {(fin(matGame)? printf("vous avez gagné !! \n") : printf("vous avez perdu !! \n"));}
    return 0;
}


int afficheGame(int matGame[TAILL][TAILL]) {
    for (int i = 0; i < TAILL; i++) {
        for (int j = 0; j < TAILL; j++) {
            switch (matGame[i][j]) {
                case 0 :
                 printf("\033[41m%d  \033[0m",matGame[i][j]);
                break;
                case 1 :
                 printf("\033[42m%d  \033[0m",matGame[i][j]);
                break;
                case 2 :
                 printf("\033[43m%d  \033[0m",matGame[i][j]);
                break;
                case 3 :
                 printf("\033[44m%d  \033[0m",matGame[i][j]);
                break;
                case 4 :
                 printf("\033[45m%d  \033[0m",matGame[i][j]);
                break;
                case 5 :
                  printf("\033[46m%d  \033[0m",matGame[i][j]);
                break;

            }
           // printf("%d  ", matGame[i][j]);
        }
        printf("\n");
    }

    return 0;
}