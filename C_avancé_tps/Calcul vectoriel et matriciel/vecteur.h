// on appelle cette constante symbolique un gardien, cela permet de s'assurer que ce fichier
// ne sera pas inclus de maniere recursive
#ifndef C3__VECTEUR_H
#define C3__VECTEUR_H

#include <stdio.h>

typedef float*  VecteurType;
 void    vecteurToFile(FILE * ,VecteurType ,int  );
// float * vecteurFromFileByName();
// float   produitScalaire();

#endif