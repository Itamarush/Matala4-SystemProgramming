#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
void shortsPath_cmd(pnode *head);
void TSP_cmd(pnode *head);
void addEdge(pnode *head, pnode newEdgeNode);
pedge lastEdge(pedge edge);
void insert_new_node_cmd(pnode *head);
pnode findNode(pnode *head, int nameOfNode);
pnode findNodeBefore(pnode *head, int nameOfNode);
void freeAllEdges(pnode tmpNode);
int dijkstra(pnode *head, pnode start, pnode end);
pnode minNodeData(pnode curr);
void permutation(pnode *head, int *arr, int start, int end);
void swap(int *x, int *y);
int tspUsingDijkstra(pnode *head, int *arr, int length);
pnode findLastNode(pnode *head);
void free_edges(pedge head);
void disconnect_node(pnode head, pnode nodeToDisconnect);
pedge find_edge_to(pedge head, pnode endpoint);
pedge find_edge_before(pedge head, pnode endpoint);





#endif
