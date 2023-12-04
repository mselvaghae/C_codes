#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Fonction pour vérifier si une ligne est un commentaire
int estCommentaire(char *ligne) {
    char *ptr = strchr(ligne, '/');
    if (ptr != NULL && *(ptr + 1) == '/') {
        return 1; // Ligne de commentaire
    }
    return 0; // Pas un commentaire
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <fichier.c>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen("resultat.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Erreur lors de la création du fichier de sortie.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    char ligne[MAX_LENGTH];
    int commentaire = 0;
    int codeC = 0;
    int commentairesLignes = 0;
    int lignesCodeC = 0;

    fprintf(outputFile, "/*\n");
    fprintf(outputFile, "Fichier : %s\n", argv[1]);
    fprintf(outputFile, "Auteurs : [Vos noms ici]\n");
    fprintf(outputFile, "Date : [Date ici]\n");
    fprintf(outputFile, "*/\n\n");

    while (fgets(ligne, MAX_LENGTH, inputFile) != NULL) {
        if (strncmp(ligne, "#", 1) == 0) {
            fprintf(outputFile, "%s", ligne); // Directives du préprocesseur
        } else if (strstr(ligne, "/*") != NULL) {
            commentaire = 1; // Début d'un commentaire
            fprintf(outputFile, "%s", ligne);
            commentairesLignes++;
        } else if (commentaire == 1 && strstr(ligne, "*/") != NULL) {
            commentaire = 0; // Fin d'un commentaire
            fprintf(outputFile, "%s", ligne);
            commentairesLignes++;
        } else if (estCommentaire(ligne)) {
            fprintf(outputFile, "%s", ligne); // Commentaires de code
            commentairesLignes++;
        } else if (strlen(ligne) > 1) {
            fprintf(outputFile, "%s", ligne); // Code C
            lignesCodeC++;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    codeC = commentairesLignes + lignesCodeC;

    printf("Statistiques de qualité du code :\n");
    printf("Nombre total de lignes de code C : %d\n", lignesCodeC);
    printf("Nombre total de lignes de commentaires : %d\n", commentairesLignes);
    printf("Proportion de commentaires par rapport au code C : %.2f%%\n",
           (float)(commentairesLignes * 100) / codeC);

    return EXIT_SUCCESS;
}
