CC		= gcc
CFLAGS		= -g -c -Wall
LDFLAGS		=
INCLUDES	= -I../.
SOURCES		= echo_server.c echo_cli.c 
OBJECTS		= $(SOURCES:.c=.o)
TARGET		= echo_server echo_cli

all: $(SOURCES) $(TARGET)

echo_server: echo_server.o
	$(CC) echo_server.o $(FDFLAGS) -o echo_server

echo_cli: echo_cli.o
	$(CC) echo_cli.o $(FDFLAGS) -o echo_cli

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

.PHONY: clean

clean:
	rm -rf $(OBJECTS) $(TARGET)
