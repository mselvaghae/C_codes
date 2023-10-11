OPTIONS=-Wall -Wextra -g
CC=gcc
 
prog: vecteur.o teZZt.o tests_vecteur.o
	${CC} -o prog vecteur.o teZZt.o tests_vecteur.o -g

vecteur.o: vecteur.c vecteur.h
	${CC} ${OPTIONS} vecteur.c -c

tests_vecteur.o: vecteur.h teZZt.h  tests_vecteur.c
	${CC} ${OPTIONS} tests_vecteur.c -c 

teZZt.o: teZZt.h teZZt.c
	${CC} ${OPTIONS} -c teZZt.c

clean:
	rm -f teZZt.o vecteur.o tests_vecteur.o prog *gch
