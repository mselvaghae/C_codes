#include "vecteur.h"
#include<stdlib.h>


void  vecteurToFile(FILE * file ,VecteurType vecteur,int ordre ) 
{
	fprintf(file,"%d\n",ordre);
	fprintf(file,"%.3f",vecteur[0]);
	for(int i=1; i < ordre ; i++){
		fprintf(file," %0.3f",vecteur[i]);
	}
}

/*
float * vecteurFromFileByName() 
{
	float * retour = NULL;

	return retour;
}
*/

/*
float   produitScalaire() 
{
	float retour;

    return retour;
} 
*/