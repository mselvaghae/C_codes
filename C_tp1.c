#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*Si vous oubliez l'option -o, 
le nom du fichier compilé _s'il n'y a pas d'erreur_ sera a.out. 
Le programme obtenu après compilation est directement exécutable.*/

int main() {
    
    int m=-12;
    float n1 = 1.2 ;
    printf("%u\n",m);
    
    //printf("%f\n",m); 
/*si tu tromp dans le format ,qui est dans printf le compilateur affiche : 
  ""warning: format ‘la format que tu as écrit’ expects argument of type ‘format correcte’, but argument 2 has type ‘type dde l'element’ [-Wformat=]""
*/
    printf("%f\n",n1);
   //printf("%d\n",n1);
/*exemple de ce qu'on a dit :
    si tu compile avec ligne 19 :
    "warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘double’ [-Wformat=]"
    si tu compile avec ligne 13 :
    "warning: format ‘%f’ expects argument of type ‘double’, but argument 2 has type ‘int’ [-Wformat=]"
*/
    /*les messages d'erreurs ou avertissement fondamental:
        si Renommer la fonction main() ou si oublier la fonction main() :
         ".....référence indéfinie vers « main »....."
        si on duplique la fonction main() ou plus :
         "....redefinition of ‘main’...."
        si on oublier la definition d'un variable ou commenter la parti de definition :
         ".....‘a’ undeclared ...."
        si Commenter la ligne avec #include :
         "....note: include ‘la studio que vous oublier ou la que vous commenter’ or provide a declaration of..."
    */
// les formats 
        /*
    Pour les entiers :
     %d : Conversion en décimal signé (ex : -42).
     %x : Conversion en hexadécimal (ex : 1A).
     %u : Conversion en décimal non signé (ex : 42)."Il convertit les bits de l'entier négatif en une valeur non signée, en interprétant la séquence de bits comme un nombre positif."

    Pour les réels :
     %f : Conversion en décimal à virgule flottante (ex : 3.14).
     %F : Conversion en décimal à virgule flottante (équivalent à %f).
     %g : Conversion en décimal à virgule flottante (format court, notation scientifique si nécessaire).
     */
/*************************Tests************************************/
   //"Vous pouvez ajouter "partout" l'option -lm sauf entre l'option -o et son paramètre !"

   int i = 17304;

    if (i == -1)  printf("i vaut -1\n");
    if (i != -1)  printf("i est différent de -1\n");
    if (i != 0)   printf("i est non nul\n");
    if (i)        printf("i est non nul également\n");
    if (i == 0)   printf("i est nul\n");
    if (!i)       printf("i est nul encore !\n");
    if ((i>=0) && (i<=10)) printf("i est petit\n");
    if ((i>3) || (i<-3)) printf("i est hors intervalle [-3,3]\n"); 
        /********solution d'une equation du deuxieme degre*****/
    float a = 1 ,b = -3, c = 2;
    printf("inserer les coefficients de l'equation dans l'ordre ax²+bx+c \n ");
    scanf("%f %f %f", &a,&b,&c);
    if (a){
        int d = 0;
        d = (b*b - 4*a*c);
        if (d<0){
            printf("\t l'equation n'a pas de solution\n ");
        }
        else{
            float e = (-b-sqrt(d))/(2*a);
            float f = (-b+sqrt(d))/(2*a);
            if(e!=f){
                printf("\t les solutions sont %f et %f \n",e,f);
            }
            else{
                printf("\t le solution double est %f \n",e);
            }
        }
    }
    else{
        if(b){
            float e = - c / b;
            printf("\t le solution est %f \n",e);
        }
        else{
            if(c){
                printf("\t l'equation n'a pas de solution\n");
            }
            else{
                printf("\t infinité de solution\n");
            }
        }
    }
/*************************les Boucles***********************/
    printf("\tafficher le nombre de 0 à un nombre au clavier\n");
    int nombre = 0,n = 0;
    i = 0;
    scanf("%d", &nombre);

    while (i <= nombre) {
       printf("%d ", i);
       i++;
    }

    printf("\n\tafficher les carrés de 0 à un nombre saisie au clavier \n");

    scanf("%d", &nombre);
    i = 0;
    do {
       printf("%d ", i * i);
       i++;
    } while (i <= nombre);

    printf("\n\tCalculer la somme des n^2 pour n saisie au clavier\n");

    scanf("%d", &n);
    int somme1 = 0;
    i = 0;
    printf("Avec la boucle while :\n");
    while (i <= n) {
       somme1 += i * i;
       i++;
    }
    printf("Somme = %d\n", somme1);

    printf("\t Calculer la somme des n^(-2) pour n saisie au clavier\n");

    scanf("%d", &n);
    double somme = 0.0;
    i = 1;
    printf("Avec la boucle while :\n");
    while (i <= n) {
       somme += 1.0 / (i * i);
       i++;
    }
    printf("Somme = %lf\n", somme);

    printf("\t Afficher les tables de multiplication de 1 à 12\n");
    for (int i = 1; i <= 12; i++) {
        printf("Table de multiplication de %d :\n", i);
        for (int j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
/*!!!!ATTENTION !!!!
    "Le format de la chaîne de caractères que vous avez utilisé dans scanf doit correspondre exactement à la manière dont les nombres sont entrés.
     Lorsque vous saisissez un nombre suivi d'un espace, scanf attend également un espace dans l'entrée."
    */
/**************************Affichages en tout genre**************/
     loat x =1.0, y=.0;
    i = 7;
    /* Quelques exemples */
    printf("Un mot\n");
    printf("un nombre : %d\n", 3);
    printf("Solution x:%f, y:%f\n", x, y);

    printf("%d\n", i);
    printf("%d\n", ++i);
    printf("%d\n", i);
    printf("%d\n", i++);
    printf("%d\n", i);

    printf("%d\n", 3.5);
    printf("\n");
    printf("\t\t %d\n", i);

/***********fin tp1******************/
    return 0;
}
