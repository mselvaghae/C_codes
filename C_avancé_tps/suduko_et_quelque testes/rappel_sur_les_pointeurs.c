#include<stdio.h>
#include<stdlib.h>

void echPpoint(int * , int * );
int compter1(char * );
int compter2(char * ); 
int compter3(char * ); 

int main()
{
   char * s = "loupar";
  // printf("%lu %lu %lu\n", sizeof(char), sizeof(int), sizeof(double));
   //int i = 0 , j =2 ;
   //echPpoint(&i,&j);
   //printf("i = %d et j=%d \n", i, j);
   printf("lg1 = %d et lg3=%d\n", compter1(s), compter3(s));
   
   int tab[] = {0,1,2,3,4,5};

   printf("%lu %lu %lu\n", sizeof(char), sizeof(int), sizeof(double));

   int  * p1;
   char * p2;

   p1 = tab; 
   ++p1;
   printf("%d ", *p1);

   p2 = (char *) p1;
   p2 += sizeof(int);

   printf("%d", *((int*)p2));
   printf("%d", *(p1+6));

   /*p1 = NULL;
   printf("%d", *p1);*/

   

   return 0 ;
}

void echPpoint(int * a , int * b){
   int  c  = *a;
  
   *a = *b ;
   *b = c;

}
/* type        sizeof
   char        1 octet
   short tem   2
   int         2/4 
   flot        reel en simple precision
   long int    4
   doublé      8 (reeil en double precision)
   void *     8
*/
int compter1(char * chaine) 
{   
  int i = 0;

  while (*(chaine+i) != '\0')
     ++i;

  return i;
}

int compter2(char * chaine) 
{   
  char * s = chaine;

  while (*chaine != '\0')
     ++chaine;

  return chaine - s; 
}

int compter3(char * chaine) // cette fonction compte le '\0' à la fin de liste 
{   
  char * s = chaine;

  while (*chaine++);

  return chaine - s; 
}
