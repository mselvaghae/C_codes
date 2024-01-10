# Squelette d'un code C utilisant la bibliothèque teZZt.


Il suffit de taper la commande `make`
pour faire deux choses :
* produire un premier exécutable, celui des tests unitaires main_tests
* produire un deuxieme exécuble, le programme à exécuter si nécessaire

Une connexion internet est requise pour télécharger ou mettre à jour les fichiers de la bibliothèque de tests

`make clean` permet d'effacer les fichiers de construction

La structure du projet est la suivante :
* `main.c` contient le programme principal. Ce fichier utilise les types / fonctions / macros / variables déclarées dans `code.h`
* `main_tests.c` contient une suite de tests unitaires, en testant les fonctions déclarées dans `code.h`
* `code.h` et `code.c` contiennent le code que l'on veut voir exécuter
* `teZZt.h` et `teZZt.c` concernent la bibliothèque de tests unitaires

Le `Makefile` peut télécharger la bibliothèque de tests unitaires à la première utilisation ou en faisant explicitement
`make update`

Le fichier `Makefile` est volontairement basique. Pour ajouter un fichier de code, 
il faut l'ajouter aux bonnes lignes et rajouter les dépendances.
