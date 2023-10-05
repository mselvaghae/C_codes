OPTIONS=-Wall -Wextra -g
CC=gcc
LD = gcc 

prog: mon_code.o teZZt.o main.o
	${LD} -o prog mon_code.o teZZt.o main.o -g 

mon_code.o: mon_code.c mon_code.h
	${CC} ${OPTIONS} mon_code.c -c

main.o: mon_code.h teZZt.h main.c
	${CC} ${OPTIONS} main.c -c

teZZt.o: teZZt.h teZZt.c
	${CC} ${OPTIONS} -c teZZt.c

clean:
	rm -f mon_code.o teZZt.o main.o prog *.gch 
