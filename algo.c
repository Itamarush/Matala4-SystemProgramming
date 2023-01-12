#include "graph.h"

void shortsPath_cmd(pnode head)
{
    int src, dest = -1;
    scanf("%d %d", &src, &dest);

    pnode start = findNode(head, src);
    pnode end = findNode(head, dest);
    if (start != 0 && end != 0)
    {
        dijkstra(start, end);
    }
    
}

void dijkstra(pnode start, pnode end)
{
    start->data = 0;
    pnode curr = start;
    pedge edge = curr->edges;

    while (curr != 0 )
    {
        curr->data = INF;
        curr->Visited = 0;
        curr = curr->next;
    }
    
    while (curr != 0)
    {
        while (edge != 0)
        {
            if (curr->data + edge->weight < edge->endpoint->data && edge->endpoint->Visited == 0)
            {
                edge->endpoint->data = curr->data + edge->weight;
            }
            edge = edge->next;
        }

        curr->Visited = 1;
        curr = minNodeData(curr);
    }
    printf("the short is%d", end->data);
}

pnode minNodeData(pnode curr)
    {
        pnode min = 0;
        min->data = INF;
        pedge edge = curr->edges;
        while (edge != 0)
        {
            if (edge->endpoint->data < min->data)
            {
                min = edge->endpoint;
                edge->next;
            }
        }
        return min;
    }

void TSP_cmd(pnode head)
{
    printf("ok tsp");
}