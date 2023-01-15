#include "graph.h"

void addEdge(pnode *head, pnode newEdgeNode)
{
    int toWhichNode, weightOfEdge;
    pnode newEdgeNode1 = newEdgeNode;
    while (scanf("%d", &toWhichNode) != 0 && scanf("%d", &weightOfEdge) != 0 && !(isalpha(toWhichNode) && isalpha(weightOfEdge)))
    {
        if (newEdgeNode1->edges == 0)
        {
            newEdgeNode1->edges = (pedge)malloc(sizeof(edge));
            if (newEdgeNode->edges == 0)
            {
                printf("error while trying to malloc");
                exit(0);
            }
            newEdgeNode1->edges->next = 0;
            newEdgeNode1->edges->weight = weightOfEdge;
            newEdgeNode1->edges->endpoint = findNode(head, toWhichNode);
        }
        else
        {
            pedge newEdges = 0;
            newEdges = lastEdge(newEdgeNode->edges);
            newEdges->next = (pedge)malloc(sizeof(edge));
            if (newEdges->next == 0)
            {
                printf("error while trying to malloc"); 
                exit(0);
            }
            newEdges = newEdges->next;
            newEdges->weight = weightOfEdge;
            newEdges->endpoint = findNode(head, toWhichNode);
            newEdges->next = NULL;
        }


    }
}


pedge lastEdge(pedge edge)
{   
    while (edge->next != 0)
    {
        edge = edge->next;
    }
    return edge;
}

void freeAllEdges(pnode tmpNode)
{
    pedge deleteEdge = tmpNode->edges;
    pedge tempEdge = 0;

    while (deleteEdge != 0)
    {
        tempEdge = deleteEdge;
        deleteEdge = deleteEdge->next;
        free(tempEdge);
    }
}