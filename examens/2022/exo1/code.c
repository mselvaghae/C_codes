#include "code.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

int convert_to_d(char * s) {
   int l =0;
   while (s[l] != '\0') { l++;}
   char tab[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
   int d = 0 ;
   for (int i =0;i<l;i++){
      int j =0 ;
      while (s[i] != tab[j]) { j++;}
      d+=pow(16,l-i-1)*j;
   }
   return d;
}

// ********************************************************

int is_prime(int n)
{
   if (n<2) {return 0;}
   for (int i=2;i<=(int)sqrt(n);i++){
      if (n%i==0){
         return  0;
      }
      
   }
   return 1;
}

void facteurs_simple(char * res, int n) {
   int a = 1 ;
   FILE * file = fmemopen(res,1024,"w");
   for (int i=2;i<=n;i++){
      if (is_prime(i) && (n%i==0)){
         if (1==a) { fprintf(file,"%d",i); a = -1; }
         else { fprintf(file," %d",i); }
         n = n/i;
         i=1;
     }
   }
  
   fclose(file);
}

void facteurs(char * res, int n) {

   char resultat[1024]="";
   facteurs_simple(resultat, n);

   FILE * file = fmemopen(res,1024,"w");

   int a=1, occ = 0;
   char *token = resultat, *nextToken;
   char currentFactor[1024]="" , previousFactor[1024]=" ";
   while (*token != '\0')
   {
      nextToken = token;
      while (*nextToken!= ' ' && *nextToken != '\0'){
         nextToken++;
      }

      char temp = *nextToken;
      *nextToken = '\0';

     strcpy(currentFactor,token);
     if(0 == strcmp(currentFactor,previousFactor))
     {
         occ++;
     }else{
      if(0!= strcmp(previousFactor," ")){
         if (a==1){
            a=2;
         }else{
            fprintf(file,"*");
         }
         fprintf(file,"%s",previousFactor);
         if(occ > 1){
            fprintf(file,"^%d",occ);
         }
      }
      strcpy(previousFactor,currentFactor);
      occ=1;
     }

     *nextToken = temp ;

     if (*nextToken == ' '){
       token = nextToken +1 ;
     }else{
      token = nextToken;
     }

   }

   if(0!= strcmp(previousFactor," ")){
      if (1 != a){
         fprintf(file,"*");
      }
      fprintf(file,"%s",previousFactor);
      if(occ > 1){
         fprintf(file,"^%d",occ);
      }
   }
   fclose(file);
}


// ********************************************************

double ** creer_id(int n)  {
   double **mat = malloc(n*sizeof(double *));
   if(mat != NULL){
      for (int i= 0 ; i < n ; i++){
         *(mat+i) = malloc(n*sizeof(double));
         if (*(mat + i) == NULL )
         {
            for(int j =0 ; j < i ; j++){
               free(mat[j]);
            }
            free(mat);
            return NULL ;
         }
         for (int j = 0 ; j< n ; j++){
            mat[i][j] = 0;
         }
         mat[i][i] = 1;
      }
   }
   return mat;
}

void liberer(double **m, int n) {
   if (m == NULL ) { return ;}
   for (int i = 0 ;i < n; i++){
      free(*(m+i));
   }
   free(m);
}

double **lire_mat(char *nom, int *pordre) {
    FILE *file = fopen(nom, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    if (fscanf(file, "%d", pordre) != 1) {
        perror("Error reading matrix order");
        fclose(file);
        return NULL;
    }

    double **mat = creer_id(*pordre);
    if (mat == NULL) {
        perror("Memory allocation failed for matrix");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *pordre; i++) {
        for (int j = 0; j < *pordre; j++) {
            if (fscanf(file, "%lf", &mat[i][j]) != 1) {
                liberer(mat,*pordre);
                perror("Error reading matrix data");
                fclose(file);
                return NULL;
            }
        }
    }

    fclose(file);
    return mat;
}



double ** multiplication(double ** a, double **b, int ordre) {
   double **mat = creer_id(ordre);
   if ( a==NULL || b == NULL) { return NULL;}
   for ( int i = 0 ; i < ordre ; i++){
      for (int j = 0 ; j < ordre ; j++){
         if ( i == j) mat[i][j] = 0;
         for(int k = 0 ; k < ordre ; k ++){
            mat[i][j]+= a[i][k] * b[k][j] ;
         }
      }
   }
   return mat;
}