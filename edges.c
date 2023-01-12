#include "graph.h"

void add_edge(pnode *head, pnode newEdgeNode, int toWhichNode, int weightOfEdge)
{
    if (newEdgeNode->edges = 0)
    {
        newEdgeNode->edges = (pnode)malloc(sizeof(node));
        if (newEdgeNode->edges == 0)
        {
            printf("error while trying to malloc"); 
        }
        newEdgeNode->edges->next = 0;
        newEdgeNode->edges->weight = weightOfEdge;
        newEdgeNode->edges->endpoint = findNode(head, toWhichNode);
    }
    else
    {
        pedge newEdges = 0;
        newEdges = lastEdge(newEdges);
        newEdges->next = (pedge)malloc(sizeof(edge));
        if (newEdges->next == 0)
        {
            printf("error while trying to malloc"); 
        }
        newEdges = newEdges->next;
        newEdges->weight = weightOfEdge;
        newEdges->endpoint = findNode(head, toWhichNode);
        newEdges->next = NULL;
    }
    
}

pedge lastEdge(pedge edge)
{   
    pedge before;

    while (edge =! 0)
    {
        before = edge;
        edge = edge->next;
    }
    return before;
}