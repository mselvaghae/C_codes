CC=gcc
CFLAGS=-Wall -Wextra -g 
LDFLAGS= -lm 
SRC=code.c
all:teZZt.h main main_tests
main:code.o main.o
	${CC} -o main code.o main.o ${LDFLAGS}
main_tests:code.o main_tests.o teZZt.o
	${CC} -o main_tests code.o main_tests.o teZZt.o ${LDFLAGS}
code.o:code.c code.h
	${CC} ${CFLAGS} code.c -c 
main.o:code.h teZZt.h main.c
	${CC} ${CFLAGS} main.c -c
main_tests.o:code.h teZZt.h main_tests.c
	${CC} ${CFLAGS} main_tests.c -c
teZZt.o:teZZt.h teZZt.c
	${CC} ${CFLAGS} -c teZZt.c
clean:
	rm -f *.gch main.o main_tests.o code.o main main_tests teZZt.o

