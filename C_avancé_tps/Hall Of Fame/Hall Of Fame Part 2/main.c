#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hall_of_fame.h"


int main(void) {
  /********************************************programme pour gere des donnees stock dans une list chainee **************/
  donnee_t * head = NULL;
  printf("Menu principale :\n");
  printf("\t 1 : afficher la liste de donner \n\t 2 : insere un nouveaux element\n\t 3 : quitter\n\t 4 : editer et modifier un élment\n\t 5 : Lire/sauvegarder une list apartir d'une name fichier texte\n");
  bool stop = false; 
  int valeur = -1 ;
  
  while(!stop){  
    switch (valeur) {
      case 3 :
         stop = true;
         printf("good bay :{)\n");
        break;
      case 1 : 
         afficherDonnee(stdout,head);
         valeur = -1;
        break;
      case 2 :
         donnee_t * element = malloc(sizeof(donnee_t));
         saisirDonnee(stdin,element);
         head = insereList(head,element);
         valeur = -1;         
        break;
      case 5 : 
         printf("saisir le nom de fichier : ");
         char *name = malloc(1024*sizeof(char));

         fgets(name, 1024, stdin);

         name = supenter(name);

         head = ListFromFilename(name);

         valeur =-1;

         free(name);        
        break;
      case 4 :
         printf("saisir l'indice de l'element que vous voules éditer : ");
         int index = -1;

         scanf("%d",&index);
         getchar();

         head = editerElement(head,index);

         valeur =-1;
        break;
      default : 
         printf("saisir un nombre de menu pricipale :\n");
         if(scanf("%d",&valeur)!=1)
         {  
          printf("erreur de saisie\n");
          return 0;
          }
          getchar();
        break;

    }
  }
  
  libererList(head);
 
 
 	return 0;
}
