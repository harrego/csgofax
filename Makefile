TARGET = csgofax
LIBS = -lxdo $(shell pkg-config --libs glib-2.0 gio-2.0)
CC = gcc
CFLAGS = -g -Wall $(shell pkg-config --cflags glib-2.0 gio-2.0)

OBJS = main.o dbus.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: all
	./$(TARGET)

clean:
	rm *.o $(TARGET)