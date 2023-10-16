#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teZZt.h"
#include "hall_of_fame.h"

/*
   - decommenter au fur et a mesure que vous suivez l enonce et que le code est ecrit
   - compiler avec gcc *.c -g -Wall -Wextra -o executable
*/


BEGIN_TEST_GROUP(tableau_structure)

TEST(fgets) {
   char exemple [] = "scanf, c'est pas bien\n";
   LOG(exemple);
   char chaine1[25]= "mini bali";
   char chaine2[10];

   FILE * file = fmemopen(exemple, sizeof(exemple)+1, "r");
   // REQUIRE ( NULL != file);

   fgets(chaine1, 25, file);
   LOG(chaine1);
   fclose(file);
   REQUIRE( strlen(exemple) == strlen(chaine1) );

   file = fmemopen(exemple, sizeof(exemple)+1, "r");
   // REQUIRE ( NULL != file);

   fgets(chaine2, 10, file);
   LOG(chaine2);
   
   REQUIRE( strlen(exemple) > strlen(chaine2) );

   fgets(chaine2, 10, file);
   LOG(chaine2);
   fclose(file);
}


TEST(Sizeof) {
	int taille1 = sizeof(struct donnee);
   int taille2 = sizeof(int)+140*sizeof(char); 

	CHECK (taille1 == taille2);
}


/*
// pas de test mais un exemple simple de manipulation
TEST(AffichageA) {
   struct donnee essai;

   strcpy(essai.nom, "2048");
   strcpy(essai.alias, "loic");
   essai.score = 16000;

   printf("%s ", essai.nom);
   printf("%s ", essai.alias);
   printf("%d ", essai.score);

} */


TEST(AffichageB) {
   struct donnee essai;
   strcpy(essai.nom, "pokemon GO");
   strcpy(essai.alias, "loic");
   essai.score = 498;

   afficherDonnee(stdout, essai); 

   // creation du flux de texte => buffer
   char buffer[1024];
   FILE * file = fmemopen(buffer, 1024, "w");
   REQUIRE ( NULL != file);

   afficherDonnee(file, essai);
   fclose(file);

   CHECK( 0 == strcmp(buffer, "pokemon GO : loic avec 498\n") );
}


TEST(AffichageC) {
   donnee_t essai;
   strcpy(essai.nom, "overwatch");
   strcpy(essai.alias, "loic");
   essai.score = 2300;

   afficherDonnee(stdout, essai); 

   // creation du flux de texte => buffer
   char buffer[1024];
   FILE * file = fmemopen(buffer, 1024, "w");
   REQUIRE ( NULL != file);

   afficherDonnee(file, essai);
   fclose(file);

   CHECK( 0 == strcmp(buffer, "overwatch : loic avec 2300\n") );
} 


TEST(Saisie) {
   struct donnee essai;
   char buffer[1024];
   strcpy(buffer, "rien\ndutout\n10");
   FILE * file = fmemopen(buffer, 1024, "r");
   // REQUIRE ( NULL != file);
   char * str = "lslsjslj\n";
   saisirDonnee(file, &essai);
   fclose(file);

   afficherDonnee(stdout, essai);
   str = enlevalaligne(str);
   CHECK(  0 == strcmp(essai.nom, "rien\n") );
   CHECK(  0 == strcmp(str, "lslsjslj") );
   printf("%s\n",str);
   CHECK(  0 == strcmp(essai.alias, "dutout\n") );
   CHECK( 10 == essai.score );  
   free(str);
} 

/*
TEST(lectureFichier) {
   donnee_t tableau[TAILLE_MAX];
   int taille = 0;
   
   // test d'un fichier non existant
   taille = tableauFromFilename("inconnu.txt", tableau);      
   CHECK( 0 == taille );

   // test du fichier exemple
   taille = tableauFromFilename("jeu1.txt", tableau);

   REQUIRE( 2 == taille );
   CHECK  ( 0 == strcmp(tableau[0].nom, "2048"));
   CHECK  ( 0 == strcmp(tableau[0].alias, "loic")); // :-)
   CHECK  ( 64236 == tableau[0].score );
   CHECK  ( 0 == strcmp(tableau[1].nom, "Minecraft"));
   CHECK  ( 0 == strcmp(tableau[1].alias, "kiux")); 
   CHECK  ( 12304883 == tableau[1].score );
}
*/

END_TEST_GROUP(tableau_structure)


int main(void) {
	RUN_TEST_GROUP(tableau_structure); 
 	return 0;
}
