#
# Makefile for the hello example package
#

CFLAGS+=$(TARGET_CFLAGS)
LDFLAGS+= -lrt -lpthread


all: socket_server

socket_server: main.o Queue.o C2S.o S2C.o server.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f socket_server *.o

