CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lSDL2 -lm
TARGET_SDL = Flood_it_SDL
TARGET_TERMINAL = Flood_it_terminal
SOURCES = Flood_it.c Flood_it_SDL.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET_SDL) $(TARGET_TERMINAL)

$(TARGET_SDL): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(TARGET_TERMINAL): Flood_it_terminal.c Flood_it.c Flood_it.h
	$(CC) $(CFLAGS) Flood_it_terminal.c Flood_it.c -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET_SDL) $(TARGET_TERMINAL)

.PHONY: all clean



