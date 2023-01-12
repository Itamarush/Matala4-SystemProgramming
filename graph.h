#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "edges.c"
#include "graph.c"
#include "algo.c"
#include "nodes.c"

#define INF 999999
#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;; // why two?

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
        // i use it for the dijkstra algo
    int data;
    int Visited;

    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;

} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

#endif
