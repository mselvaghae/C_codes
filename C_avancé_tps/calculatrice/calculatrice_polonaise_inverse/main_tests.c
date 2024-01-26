#include "code.h"
#include "teZZt.h"

// NE PAS COMMENTER CETTE LIGNE
BEGIN_TEST_GROUP(code)


TEST(premier_test) {

   CHECK( 1 );
}
/*
TEST(identification_avec_indice) {
  CHECK(  0 == elementaire_optimale(1,-1,'+'));
  CHECK(  2 == elementaire_optimale(1,1,'+'));
  CHECK(  1 == elementaire_optimale(2,1,'-'));
  CHECK(  2 == elementaire_optimale(1,2,'*'));
  CHECK(  3 == elementaire_optimale(6,2,'/'));
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

TEST(control_eval_p) {
  CHECK( EQ( 1.0, evalp( 1.0, ID)));
  CHECK( EQ( 0.0, evalp( 0.0, SIN)));
  CHECK( EQ( 1.0, evalp( 0.0, COS)));
  printf("%f\n",evalp( 0.0, COS));
  CHECK( EQ( 1.0, evalp( 0.0, EXP)));

  CHECK( EQ(      M_PI , evalp( M_PI, ID)));
  CHECK( EQ(       1.0 , evalp( M_PI/2, SIN)));
  //printf();
  CHECK( EQ(      -1.0 , evalp( M_PI, COS)));
  CHECK( EQ( exp(M_PI) , evalp( M_PI, EXP)));
   
  CHECK( EQ( 0.0 , evalp( M_PI/2.0, COS)));
}*/
double x = 10.0;
struct s donnees[] = {
    {VAR, .data.var = &x},    
    {VAL, .data.val = 3.0},     
    {F2, .data.f2 = add},       
    {FIN, {0}}                 
};

TEST(evaluer_) {
  CHECK(  13 == evaluer(donnees));
  x=3;
  CHECK(  6 == evaluer(donnees));
  x=4;
  CHECK(  7 == evaluer(donnees));
  x=5;
  CHECK(  8 == evaluer(donnees));
  x=17;
  CHECK(  20 == evaluer(donnees));
}


END_TEST_GROUP(code)
//pru
// NE PAS COMMENTER CETTE FONCTION
// execute tous les tests
int main(void) {
	RUN_TEST_GROUP(code); 
 	return 0;
}
