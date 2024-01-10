#include "code.h"
#include "teZZt.h"

// NE PAS COMMENTER CETTE LIGNE
BEGIN_TEST_GROUP(code)


TEST(premier_test) {

   CHECK( 1 );
}

TEST(identification_avec_indice) {
  CHECK(  0 == identification("x"));
  CHECK( -1 == identification("x\n"));
  CHECK(  1 == identification("sin(x)"));
  CHECK(  2 == identification("cos(x)"));
  CHECK(  3 == identification("log(x)"));
  CHECK(  4 == identification("exp(x)"));
  CHECK( -1 == identification("t"));
}

TEST(identification_avec_enum) {
  CHECK(   ID == identification_enum("x"));
  CHECK( NONE == identification_enum("x\n"));
  CHECK(  SIN == identification_enum("sin(x)"));
  CHECK(  COS == identification_enum("cos(x)"));
  CHECK(  LOG == identification_enum("log(x)"));
  CHECK(  EXP == identification_enum("exp(x)"));
  CHECK( NONE == identification_enum("t"));
}

  TEST(control_eval_f) {
   CHECK( EQ( 0.0, evalf( 0.0, ID)));
   CHECK( EQ( 0.0, evalf( 0.0, SIN)));
   CHECK( EQ( 1.0, evalf( 0.0, COS)));
   CHECK( EQ( 1.0, evalf( 0.0, EXP)));

   CHECK( EQ(      M_PI , evalf( M_PI, ID)));
   CHECK( EQ(       0.0 , evalf( M_PI, SIN)));
   CHECK( EQ(      -1.0 , evalf( M_PI, COS)));
   CHECK( EQ( exp(M_PI) , evalf( M_PI, EXP)));
   
   CHECK( EQ( 0.0 , evalf( M_PI/2.0, COS)));
}


// NE PAS COMMENTER CETTE LIGNE
END_TEST_GROUP(code)
//pru
// NE PAS COMMENTER CETTE FONCTION
// execute tous les tests
int main(void) {
	RUN_TEST_GROUP(code); 
 	return 0;
}
