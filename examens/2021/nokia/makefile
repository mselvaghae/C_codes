CC=gcc
ISWSL := $(shell uname -r | grep microsoft; echo $$?)
exo1:exo1.o code.o  teZZt.o
	$(CC) -o exo1 exo1.o code.o teZZt.o -lm
# $(if condition,then-part[,else-part])
ifneq ($(ISWSL), 0) 
	$(info "Lancer le programme avec  ./exo1") 
else 
	$(info "Lancer le programme avec  valgrind ./exo1") 
endif
teZZt.o:teZZt.h teZZt.c
	$(CC) -c teZZt.c -o teZZt.o
exo1.o:exo1.c code.h 
	$(CC) -c exo1.c -g -Wall -Wextra
code.o:code.h code.c
	$(CC) -c code.c -g -Wall -Wextra 
clean:
	rm -rf exo1 code.o examen.o *.gch
