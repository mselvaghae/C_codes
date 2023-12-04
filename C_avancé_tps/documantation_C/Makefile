OPTIONS=-Wall -Wextra -g 
CC=gcc
 
prog: liste_chainé.o 
	${CC} -o prog liste_chainé.o  -g 

liste_chainé.o: liste_chainé.c liste_chainé.h
	${CC} ${OPTIONS} liste_chainé.c -c
documenter: documentation.o
	${CC} -o documenter documentation.o -g

documentation.o: documentation.c
	${CC} ${OPTIONS} documentation.c -c

clean:
	rm -f teZZt.o liste_chainé.o  prog documentation.o documenter  *gch
