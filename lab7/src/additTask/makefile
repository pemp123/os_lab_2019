CC=gcc
CFLAGS=-I. -std=c11 -pthread

all:  server client


server: server.c
	$(CC) -o server server.c $(CFLAGS)

client: client.c
	$(CC) -o client client.c $(CFLAGS)

clean:
	rm  server client
