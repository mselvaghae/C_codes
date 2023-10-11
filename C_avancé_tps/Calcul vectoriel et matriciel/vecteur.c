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


float * vecteurFromFileByName(char * name , int * ordre) 
{
	float * retour = NULL;
	FILE * file = fopen(name,"r");
	if (file) {
		fscanf(file,"%d",ordre);
	    retour = (float *) malloc((*ordre) * sizeof(float));
	    if(retour)
	    {
			for (int j=0 ; j < *ordre ; j++){
				fscanf(file,"%f ", (retour+j));
		    }
	    }
		fclose(file);
	}
	
	return retour;
	
}



float   produitScalaire(VecteurType v1 , VecteurType v2 , int ordre) 
{
	float retour ;
	if(!(v1 == NULL || v2 == NULL || ordre == 0)){
		retour = v1[0]*v2[0];
		for (int i =1 ; i < ordre ; i++){
			retour += v1[i]*v2[i];
		}
	}

    return retour;
} 
