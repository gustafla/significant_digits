TARGET = significant_digits
LIBS = 
CC = gcc
CFLAGS = -Wall -std=c89

debug: CFLAGS += -g
release: CFLAGS += -O2

.PHONY: default all clean debug release

default: $(TARGET)
all: default
debug: default
release: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
