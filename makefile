# edges.o: edges.c
# 	gcc -c edges.o edges.c 

# algo.o: algo.c
# 	gcc -c algo.o algo.c 

# nodes.o: nodes.c
# 	gcc -c nodes.o nodes.c 

# graph.o: graph.c
# 	gcc -c graph.o graph.c 

# main.o: main.c
# 	gcc -c main.o main.c 

# graphk: main.o graph.o nodes.o algo.o edges.o
# 	gcc -o graph main.o graph.o graph.h nodes.o algo.c edges.c

# all: graphk

# # CC = gcc
# # CFLAGS = -Wall -g -fPIC

# # all: graph

# # graph: main.o graph.o algo.o
# # 	$(CC) $(CFLAGS) $^ -o $@

# # #------- o files-------
# # %.o:%.c
# # 	$(CC) $(CFLAGS) -c $^ -o $@	
# # #------------------------------

# # clean:
# # 	rm  *.o graph

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