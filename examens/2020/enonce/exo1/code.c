#include "code.h"

#include <stdlib.h>

char * init(char * tab, int taille) {
   //tab = calloc(sizeof(char),taille); //dynamique
   if (tab == NULL) { return NULL;}
   tab[0]=0;  tab[1]=0;
   for( int i=2; i < taille ; i++)
   {
      tab[i]=1;
   }
  return tab;
}  


void affichage(FILE * file, char * tab, int taille ) {
   if (file != NULL){
      for (int i = 2 ; i < taille ; i++){
         if (tab[i]) {
            if (i>2) { fprintf(file," "); }
            fprintf(file,"%d",i);
         }
      }
   }
}

void suppMultiple(char * tab, int taille, int nb) {
   int i = 2 ;
   while ( nb > 1 && nb*i < taille ){
      tab[nb*i] = 0;
      i++;
   }
}

int prochainNombre(char * tab, int taille, int nb) {
   int i = nb +1 ;
   while (i >= 0 && i < taille && !tab[i] ) {
      i++;
   }
   if (i >= taille || i < 0) { return -1 ;}
   return i;

}

int listeNombrePremiers(FILE * file, int taille) {
   char tab[taille];
   init(tab,taille);
   for (int i=2 ; i >=0 && i<taille ; i=prochainNombre(tab,taille,i)) { 
      suppMultiple(tab,taille,i);
   }
   int res = 0 ;
   for(int j = 0; j<taille ; j++){ if(tab[j]) res++; }
   affichage(file,tab,taille);
   
   return res;
}

