/*
 * LES FICHIERS A MODIFIER SONT UNIQUEMENT CODE.H ET CODE.C
 * Tout compiler par make
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "code.h"
#include "teZZt.h"


// DEBUT DES FONCTIONS DE TESTS
BEGIN_TEST_GROUP(exo1)


TEST(CONVERSION_X_TO_D, "") {

   CHECK(        0 == convert_to_d("0") );
   CHECK(        1 == convert_to_d("1") );
   CHECK(        9 == convert_to_d("9") );
   CHECK(       10 == convert_to_d("A") );
   CHECK(       15 == convert_to_d("F") );
   CHECK(      255 == convert_to_d("FF") );
   CHECK(     3071 == convert_to_d("BFF") );
   CHECK( 11154380 == convert_to_d("AA33CC") );
}



TEST(ISPRIME, "") {
    CHECK(1 == is_prime(2));
    CHECK(1 == is_prime(3));
    CHECK(1 == is_prime(5));
    CHECK(1 == is_prime(11));
    CHECK(1 == is_prime(17));
    CHECK(1 == is_prime(53));
    CHECK(1 == is_prime(157));

    CHECK(0 == is_prime(-1));
    CHECK(0 == is_prime(0));
    CHECK(0 == is_prime(1));
    CHECK(0 == is_prime(4));
    CHECK(0 == is_prime(21));
    CHECK(0 == is_prime(195));
}

TEST(DECOMPOSITION_1, "") {
    char resultat[1024];

    facteurs_simple(resultat, 147);
    printf("%s\n",resultat);
    printf("%c\n",resultat[0]);


    CHECK(0 == strcmp(resultat, "3 7 7"));


    facteurs_simple(resultat, 241);
    CHECK(0 == strcmp(resultat, "241"));

    facteurs_simple(resultat, 999);
    CHECK(0 == strcmp(resultat, "3 3 3 37"));

    facteurs_simple(resultat, 6*6*6*6*6);
    CHECK(0 == strcmp(resultat, "2 2 2 2 2 3 3 3 3 3"));

    facteurs_simple(resultat, 1234567890);
    CHECK(0 == strcmp(resultat, "2 3 3 5 3607 3803"));
}

TEST(DECOMPOSITION_2, "") {
    char resultat[1024];

    facteurs(resultat, 147);
    CHECK(0 == strcmp(resultat, "3*7^2"));

    facteurs(resultat, 241);
    CHECK(0 == strcmp(resultat, "241"));

    facteurs(resultat, 999);
    CHECK(0 == strcmp(resultat, "3^3*37"));

    facteurs(resultat, 6*6*6*6*6);
    CHECK(0 == strcmp(resultat, "2^5*3^5"));

    facteurs(resultat, 1234567890);
    CHECK(0 == strcmp(resultat, "2*3^2*5*3607*3803"));
}




TEST(MAT_1, "") {
    double ** m = NULL;

    m = creer_id(4);

    REQUIRE( 0 != m);
    // je ferai tous les tests
    CHECK( 1 == m[2][2]);
    CHECK( 0 == m[1][3]);

    liberer(m, 4);
}

TEST(MAT_2, "") {
    double ** m = NULL;
    int ordre   = 0;

    m = lire_mat("matrice1.txt", &ordre);

    REQUIRE( 0 != m);
    REQUIRE( 3 == ordre);
    // je ferai tous les tests
    CHECK(  6 == m[1][1]);
    CHECK( 10 == m[2][0]);

    liberer(m, 3);
}

TEST(MAT_3, "") {
    double ** m = NULL;
    int ordre   = 0;

    m = lire_mat("matrice2.txt", &ordre);

    REQUIRE( 0 == m);
    liberer(m, 3);
}

TEST(MAT_4, "") {
    double ** m = NULL;
    double ** r = NULL;

    m = creer_id(3);

    REQUIRE( 0 != m);
    r = multiplication(m, m, 3);
    // je ferai tous les tests
    CHECK( 1 == r[2][2]);
    CHECK( 0 == r[1][2]);
    
    REQUIRE( 0 != r);

    liberer(m, 3);
    liberer(r, 3);
}

TEST(MAT_5, "") {
    double ** m = NULL;
    double ** r = NULL;
    int ordre   = 0;

    m = lire_mat("matrice1.txt", &ordre);

    REQUIRE( 0 != m);
    REQUIRE( 3 == ordre);
    r = multiplication(m, m, 3);   
    // je ferai tous les tests
    CHECK(  41 == r[0][0]);    
    CHECK( 123 == r[1][1]);
    CHECK( 111 == r[2][2]);
    
    REQUIRE( 0 != r);

    liberer(m, 3);
    liberer(r, 3);
}


END_TEST_GROUP(exo1)


int main() {
    RUN_TEST_GROUP(exo1); 
 
   return 0;
}

