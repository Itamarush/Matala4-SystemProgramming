# graph.o: graph.c
# 	gcc -o graph.o graph.c

# main.o: main.c
# 	gcc -c main.o main.c 

graphk: main.o graph.o
	gcc -o graph main.o graph.o graph.h

all: graphk

# CC = gcc
# CFLAGS = -Wall -g -fPIC

# all: graph

# graph: main.o graph.o algo.o
# 	$(CC) $(CFLAGS) $^ -o $@

# #------- o files-------
# %.o:%.c
# 	$(CC) $(CFLAGS) -c $^ -o $@	
# #------------------------------

# clean:
# 	rm  *.o graph