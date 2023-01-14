#include "graph.h"
int minimum = INF;

void shortsPath_cmd(pnode *head)
{
    int src, dest, answer = -1;
    scanf("%d %d", &src, &dest);

    pnode start = findNode(head, src);
    pnode end = findNode(head, dest);

    if (start != 0 && end != 0)
    {
        answer = dijkstra(&(*head), &(*start), &(*end));
    }
    if (answer == INF)
    {
        printf("Dijsktra shortest path: -1 \n");
        return;
    }
    printf("Dijsktra shortest path: %d \n", answer);
    answer = INF;
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

    while (curr!= 0)
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
        if (curr->next == 0)
        {
            return end->data;
        }
        
        curr->Visited = 1;
        curr = minNodeData(curr);
    }
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
    if (minimum == INF)
    {
        printf("TSP shortest path: -1 \n");
        minimum = INF;
    }
    else
    {
        printf("TSP shortest path: %d \n", minimum);
        minimum = INF;
    }

}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permutation(pnode *head, int *arr, int start, int end)
{
    int value = 0;
    if (start == end)
    {
        // printf("%d%d%d\n",arr[0],arr[1],[arr2]);
        value = tspUsingDijkstra(&(*head), arr, end);
        if (minimum > value)
        {
            minimum = value;
        }
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

    for (size_t i = 0; i < length; i++)
    {
        pnode start = findNode(head, arr[i]);
        pnode end = findNode(head, arr[i+1]);
        temp+= dijkstra(&(*head), &(*start), &(*end));
    }
    
    if (shortestRoute > temp)
    {
        shortestRoute = temp;
    }
    
    // printf("the shortest route is: %d\n", shortestRoute);
    return shortestRoute;
}


