OPTIONS=-Wall -Wextra -g 
CC=gcc
 
prog: hall_of_fame.o main.o
	${CC} -o prog hall_of_fame.o main.o -g 

hall_of_fame.o: hall_of_fame.c hall_of_fame.h
	${CC} ${OPTIONS} hall_of_fame.c -c

main.o: hall_of_fame.h  main.c
	${CC} ${OPTIONS} main.c -c 

clean:
	rm -f teZZt.o hall_of_fame.o main.o prog *gch
