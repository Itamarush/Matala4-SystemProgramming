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
        newEdgeNode->edge->endpoint = findNode(head, toWhichNode);
    }
    
}