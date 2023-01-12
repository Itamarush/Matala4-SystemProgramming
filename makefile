edges.o: edges.c
	gcc -c edges.o edges.c

algo.o: algo.c
	gcc -c algo.o algo.c

nodes.o: nodes.c
	gcc -c nodes.o nodes.c

graph.o: graph.c
	gcc -c graph.o graph.c

main.o: main.c
	gcc -c main.o main.c 

graphk: main.o graph.o
	gcc -o graph main.o graph.o graph.h nodes.o algo.c edges.c

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