#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


void afficherDonnee(FILE * file, donnee_t * element) {
   if(file){  
      donnee_t * cour = element;
      while(cour){
        fprintf(file,"[%s : %s avec %d]->",cour->nom,cour->alias,cour->score);
        cour = cour->next;
      }
      printf("[NULL]\n");
   }
}
char * supenter(char * str){
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return str;
}

void saisirDonnee(FILE *file, donnee_t *element) {
     element->next = NULL;
     element->nom = NULL;
     element->alias = NULL;
     char str[255];
    if (file) {
        element->nom = malloc(100*sizeof(char));
        element->alias= malloc(40 *sizeof(char));
        if (fgets(element->nom,100,file) ==NULL) { 
            fprintf(stderr, "Error reading element->nom.\n");
            return; 
        }
        if (fgets(element->alias,40,file) == NULL) {
            fprintf(stderr, "Error reading element->alias.\n");
            return; 
        }
        if (fgets(str,255,file) == NULL) {
            fprintf(stderr, "Error reading element->score.\n");
            return; 
        }
        element->score = atoi(str);   
    }
    element->nom = supenter(element->nom);
    element->alias = supenter(element->alias);
}

donnee_t * insereList(donnee_t * head , donnee_t * element){
    element->next = head;
    head=element;
    return head;
}

donnee_t * ListFromFilename(char *name) {
    FILE *file = fopen(name, "r");
    if (!file) {
        return NULL; // Le fichier n'a pas pu être ouvert
    }

    donnee_t *first = NULL;  // Garder une référence au premier élément
    donnee_t *cour = NULL;   // Pointeur courant
    donnee_t *prev = NULL;   // Pointeur précédent

    do {
        cour = malloc(sizeof(donnee_t));
        saisirDonnee(file, cour);

        if (first == NULL) {
            first = cour;  // Premier élément
        }

        if (prev != NULL) {
            prev->next = cour; // Lier l'élément précédent au courant
        }

        prev = cour;

    } while (!feof(file));
    fclose(file);
    return first;  // Retourne le premier élément de la liste
}

donnee_t * editerElement(donnee_t * head , int index){
    if(head == NULL){
        return head;
    }
    donnee_t *cour = head ;
    donnee_t *prec = NULL;
    for (int i =0;i < index; i++){
        cour = cour->next;
    }
    prec = cour;
    prec = prec->next;
    if(cour->nom != NULL) { free(cour->nom);}
    if(cour->alias != NULL) { free(cour->alias);}
    saisirDonnee(stdin,cour);
    cour->next = prec;


    return head;
}

void libererList(donnee_t * head){
    while(head){
        donnee_t *temp =head;
        head = head->next;
        free(temp->nom);
        free(temp->alias);
        free(temp);
    }
}
