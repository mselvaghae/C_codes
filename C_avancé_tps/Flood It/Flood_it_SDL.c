#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Flood_it.h"


int width = 1000;
int height = 1000;

SDL_Color intToColor(int number) {
    SDL_Color myColor;
    switch (number) {
        case 0:
            myColor.r = 255;
            myColor.g = 255;
            myColor.b = 255;
            myColor.a = 255;
            break;
        case 1:
            myColor.r = 255;
            myColor.g = 0;
            myColor.b = 0;
            myColor.a = 255;
            break;
        case 2:
            myColor.r = 0;
            myColor.g = 0;
            myColor.b = 255;
            myColor.a = 255;
            break;
        case 3:
            myColor.r = 0;
            myColor.g = 255;
            myColor.b = 0;
            myColor.a = 255;
            break;
        case 4:
            myColor.r = 0;
            myColor.g = 255;
            myColor.b = 255;
            myColor.a = 255;
            break;
        case 5:
            myColor.r = 255;
            myColor.g = 255;
            myColor.b = 0;
            myColor.a = 255;
            break;
        default:
            myColor.r = 0;
            myColor.g = 0;
            myColor.b = 0;
            myColor.a = 255; // Default color for unknown numbers
            break;
    }
    return myColor;
}

void afficherFenetre(SDL_Renderer *renderer, int matGame[TAILL][TAILL], int width, int height) {
    SDL_RenderClear(renderer);
    SDL_Rect rect[TAILL][TAILL];
    SDL_Color myColor;
    
    for (int i = 0; i < TAILL; i++) {
        for (int j = 0; j < TAILL; j++) {
            myColor = intToColor(matGame[i][j]);
            SDL_SetRenderDrawColor(renderer, myColor.r, myColor.g, myColor.b, myColor.a);
            rect[i][j].x = i * (width / TAILL);
            rect[i][j].y = j * (height / TAILL);
            rect[i][j].w = width / TAILL;
            rect[i][j].h = height / TAILL;
            SDL_RenderFillRect(renderer, &rect[i][j]);
        }
    }
    SDL_RenderPresent(renderer);
}

int main() {
    srand(time(NULL));
    int matGame[TAILL][TAILL];
    initGame(matGame);
    
    int CouleurChoisi = -1;
    int CouleurOriginale = matGame[0][0];

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Erreur d'initialisation de la SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window;
    window = SDL_CreateWindow("Flood It!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
        fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        fprintf(stderr, "Erreur de création du rendu: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Event event;
    int coupCounter = 0;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_WINDOWEVENT:
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_CLOSE:
                            printf("Appui sur la croix\n");
                            break;
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            width = event.window.data1;
                            height = event.window.data2;
                            printf("Size: %d, %d\n", width, height);
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    CouleurOriginale = matGame[0][0];
                    int x = event.button.x / (width / TAILL);
                    int y = event.button.y / (height / TAILL);
                    CouleurChoisi = matGame[x][y];
                    
                    coupCounter++;
                    break;
                case SDL_QUIT:
                    printf("On quitte\n");
                    running = 0;
                    break;
            }
        }
        remplirGame(matGame, CouleurChoisi, CouleurOriginale, 0, 0);
        afficherFenetre(renderer, matGame, width, height);

        if (coupCounter >= MAXCOUP) {
            running = 0;
        }

        SDL_Delay(1); // Minimal delay
    }

    (fin(matGame) ? printf("Vous avez gagné !!\n") : printf("Vous avez perdu !!\n"));

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
