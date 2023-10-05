#include "mon_code.h"

// implementation des fonctions a ecrire
// c est bien DANS CE FICHIER qu'il faut le faire

int pgcd(int a, int b) {
   int pgcd = 0;
   pgcd = a%b;
   while (pgcd != 0){
      a = b;
      b = pgcd;
      pgcd = a%b;
   }
   pgcd = b ;
   return pgcd ;
}

void majuscules(char s[]) {
   int i = 0;
   while (s[i] != '\0'){
      if((s[i] >= 'a')&&(s[i] <= 'z')){
         s[i] = s[i] - 32 ;
      }
      i++;
   }

}
