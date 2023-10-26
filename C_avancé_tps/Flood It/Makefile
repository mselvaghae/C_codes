CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lSDL2 -lm
TARGET = Flood_it_SDL
SOURCES = Flood_it.c Flood_it_SDL.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean


