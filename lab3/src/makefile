CC=gcc
CFLAGS=-I. -Wall -std=c99

all: sequential_min_max parallel_min_max ex5_sequential

ex5_sequential: ex5_sequential.o
	$(CC) $(CFLAGS) -o ex5_sequential ex5_sequential.o

sequential_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(CFLAGS) -o sequential_min_max find_min_max.o utils.o sequential_min_max.c

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) $(CFLAGS) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c

utils.o : utils.h
	$(CC) $(CFLAGS) -o utils.o -c utils.c

find_min_max.o : utils.h find_min_max.h
	$(CC) $(CFLAGS) -o find_min_max.o -c find_min_max.c

ex5_sequential.o:
	$(CC) $(CFLAGS) -o ex5_sequential.o -c ex5_sequential.c

clean :
	rm *.o sequential_min_max parallel_min_max ex5_sequential