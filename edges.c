#include "graph.h"

void addEdge(pnode *head, pnode newEdgeNode)
{
    int toWhichNode, weightOfEdge;

    while (scanf("%d", &toWhichNode) != 0 && scanf("%d", &weightOfEdge) != 0 && !(isalpha(toWhichNode) && isalpha(weightOfEdge)))
    {
        if (newEdgeNode->edges == 0)
        {
            newEdgeNode->edges = (pedge)malloc(sizeof(edge));
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
            newEdges = lastEdge(newEdgeNode->edges);
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
}

pedge find_edge_before(pedge head, pnode endpoint)
{
    if (head == NULL) // empty list
    {
        return NULL;
    }
    pedge temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->endpoint == endpoint)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
};

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