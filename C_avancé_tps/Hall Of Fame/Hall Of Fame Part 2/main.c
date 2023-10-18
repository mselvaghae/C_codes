#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


int main(void) {
	 donnee_t essai;
   strcpy(essai.nom, "overwatch");
   strcpy(essai.alias, "loic");
   essai.score = 2300;

   afficherDonnee(stdout, essai); 

   char buffer[1024];
   FILE * file = fmemopen(buffer, 1024, "w");

   afficherDonnee(file, essai);
   fclose(file);
 
 	return 0;
}
