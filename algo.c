#include "graph.h"

void shortsPath_cmd(pnode *head)
{
    int src, dest = -1;
    scanf("%d %d", &src, &dest);

    pnode start = findNode(head, src);
    pnode end = findNode(head, dest);
    if (start != 0 && end != 0)
    {
        dijkstra(&(*head), &(*start), &(*end));
    }
    
}

int dijkstra(pnode *head, pnode start, pnode end)
{
    pnode curr = *head;

    while (curr != 0 )
    {
        curr->data = INF;
        curr->Visited = 0;
        curr = curr->next;
    }

    curr = start;
    curr->data = 0;

    while (curr != 0)
    {
        pedge edge = curr->edges;
        
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
    printf("Dijsktra shortest path: %d ", end->data);
    return end->data;
}

pnode minNodeData(pnode curr)
    {
        pnode min = 0;
        int minValue = INF;
        pedge edge = curr->edges;
        while (edge != 0)
        {
            if (edge->endpoint->data < minValue)
            {
                min = edge->endpoint;
            }
            edge = edge->next;
        }
        return min;
    }

void TSP_cmd(pnode *head)
{
    int length;
    scanf("%d", &length);
    int arr[length];
    for (size_t i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    permutation(&(*head), arr, 0, length-1);
}

void swap(int* arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void permutation(pnode *head, int *arr, int start, int end)
{
    if (start == end)
    {
        int x = arr[0];
        int y = arr[1];
        int z = arr[2];
        tspUsingDijkstra(&(*head), arr, end);
        return;
    }

    for (size_t i = start; i <= end; i++)
    {           
        swap(&arr[start], &arr[i]);           
        permutation(&(*head), arr, start+1, end);           
        swap(&arr[start], &arr[i]);        
    }
}

int tspUsingDijkstra(pnode *head, int *arr, int length)
{
    int shortestRoute = INF;
    int temp = 0;

    for (size_t i = 0; i < length-1; i++)
    {
        pnode start = findNode(head, arr[i]);
        pnode end = findNode(head, arr[i+1]);
        temp+= dijkstra(&(*head), &(*start), &(*end));
    }
    
    if (shortestRoute > temp)
    {
        shortestRoute = temp;
    }
    
    printf("%d", shortestRoute);
    return shortestRoute;
}


