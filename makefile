edges.o: edges.c graph.h
	gcc -Wall -g -c edges.c 

algo.o: algo.c graph.h
	gcc -Wall -g -c algo.c 

nodes.o: nodes.c graph.h
	gcc -Wall -g -c nodes.c 

graph.o: graph.c graph.h
	gcc -Wall -g -c graph.c 

main.o: main.c graph.h
	gcc -Wall -g -c main.c 

graph: main.o graph.o nodes.o algo.o edges.o
	gcc -Wall -g main.o graph.o graph.h nodes.o algo.o edges.o -o graph 

all: graph

.PHONY = clean all 

clean:
	rm -f *.o *.a *.txt graph
	