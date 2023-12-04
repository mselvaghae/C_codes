#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "liste_chainé.h"

int main(int argc, char *argv[]){ // premier amélioration
   // char ligne[Max_long] = "" ; // statique

   char * ligne =(char *) malloc(Max_long *sizeof(char )); // dynamique

   
    // appartient au premier amélioration debut 
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <fichier> <int>\n", argv[0]);
        return 0;
    }

    FILE *fichier = fopen(argv[1], "r");
    if (fichier == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", argv[1]);
        return 0;
    } // fin 

    liste_t * list =(liste_t *) malloc(sizeof(liste_t));

    initialiser_liste(list);

    while ((fgets(ligne,Max_long,fichier /*amélioration à la place de "stdin"*/)!= NULL)&&/*(strcmp(ligne,"###fin###\n")!=0)*/(!feof(stdin))){
        
        /*size_t len = strlen(ligne);
        if (len > 0 && ligne[len - 1] == '\n') {
            ligne[len - 1] = '\0';
        } // supperssion de \n statique */ 

        ligne = supenter(ligne); // supperssion de \n dynamique
        
        cellule_t * cellule = cree_une_cellule(ligne);
        inserer_cellule_fin(list,cellule); 
    }

    fclose(fichier); // amélioration
   
    afficherDonnee(stdout,list);
    libererList(list);
    free(ligne);
    
    return 1;
}

void initialiser_liste (liste_t *list){
   list->tete = NULL;
   list->fin =NULL;
}

int estvide (liste_t  * list){
    if(list->tete != NULL) {
        return 0;
    }
    return 1;
}

char * supenter(char * str){
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return str;
}

cellule_t * cree_une_cellule (char * ligne){
    cellule_t * cellule = (cellule_t *)malloc (1*sizeof(cellule_t));
    cellule->ligne =(char *) malloc(Max_long *sizeof(char ));//dynamique
    strcpy(cellule->ligne,ligne); 
    cellule->suiv = NULL;
    return cellule;
}


void inserer_cellule_fin(liste_t * list ,cellule_t * cellule){
    if (estvide(list)){
        list->tete = cellule;
        list->fin = cellule;
    }
    else{
        list->fin->suiv = cellule;
        list->fin =cellule;
    }
}

void afficherDonnee(FILE * file, liste_t * list) {
   if(file){  
      cellule_t * cour = list->tete;
      fprintf(file,"[%s]",cour->ligne);
      cour = cour->suiv;
      while(cour){
        fprintf(file,"->[%s]",cour->ligne);
        cour = cour->suiv;
      }
      fprintf(file,"\n");
   }
}

void libererList(liste_t * list){
    cellule_t *courant = list->tete;
    while (courant != NULL) {
        cellule_t *temp = courant;
        courant = courant->suiv;
        free(temp->ligne); //dynamique 
        free(temp);
    }
    free(list);
}