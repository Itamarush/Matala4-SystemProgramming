# edges.o: edges.c graph.h
# 	gcc -c edges.o edges.c 

# algo.o: algo.c graph.h
# 	gcc -c algo.o algo.c 

# nodes.o: nodes.c graph.h
# 	gcc -c nodes.o nodes.c 

# graph.o: graph.c graph.h
# 	gcc -c graph.o graph.c 

# main.o: main.c graph.h
# 	gcc -c main.o main.c 

# graph: main.o graph.o nodes.o algo.o edges.o
# 	gcc -Wall -g -o graph main.o graph.o graph.h nodes.o algo.o edges.o

# all: graph

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

CC=gcc
OBJ=nodes.o edges.o algo.o graph.o main.o graph.h
NAME = main
CFLAGS = -Wall -g

all : graph
graph: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o graph  
nodes.o: nodes.c graph.h
	$(CC) $(CFLAGS) -c nodes.c
edges.o: edges.c graph.h
	$(CC) $(CFLAGS) -c edges.c
graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c
algo.o: algo.c graph.h
	$(CC) $(CFLAGS) -c algo.c
main.o: main.c graph.h
	$(CC) $(CFLAGS) -c main.c

.PHONY = clean all 

clean:
	rm -f *.o *.a *.txt graph