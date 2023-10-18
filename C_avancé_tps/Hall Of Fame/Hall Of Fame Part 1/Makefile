OPTIONS=-Wall -Wextra -g 
CC=gcc
 
prog: hall_of_fame.o teZZt.o hall_of_tests.o
	${CC} -o prog hall_of_fame.o teZZt.o hall_of_tests.o -g 

hall_of_fame.o: hall_of_fame.c hall_of_fame.h
	${CC} ${OPTIONS} hall_of_fame.c -c

hall_of_tests.o: hall_of_fame.h teZZt.h  hall_of_tests.c
	${CC} ${OPTIONS} hall_of_tests.c -c 

teZZt.o: teZZt.h teZZt.c
	${CC} ${OPTIONS} -c teZZt.c

clean:
	rm -f teZZt.o hall_of_fame.o hall_of_tests.o prog *gch
