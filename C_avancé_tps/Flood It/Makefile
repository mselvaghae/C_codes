OPTIONS=-Wall -Wextra -g
CC=gcc

Flood_it: Flood_it.o
	${CC} -o Flood_it  Flood_it.o -g

Flood_it.o: Flood_it.c Flood_it.h
	${CC} ${OPTIONS} Flood_it.c -c

Flood_it_SDL: Flood_it_SDL.o
	${CC} -o Flood_it_SDL  Flood_it_SDL.o -g

Flood_it_SDL.o: Flood_it_SDL.c Flood_it_SDL.h
	${CC} ${OPTIONS} Flood_it_SDL.c -c
clean:
	rm -f Flood_it.o Flood_it  Flood_it_SDL.o Flood_it_SDL *.gch

