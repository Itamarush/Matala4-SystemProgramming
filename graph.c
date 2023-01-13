#include "graph.h"


void build_graph_cmd(pnode *header)
{   
    pnode head, tempNode , pointerToHead = 0;

    int amountOfNodes;
    scanf("%d", &amountOfNodes);
    int counter = 0;

        head = (pnode)malloc(sizeof(node));
        if (head == 0)
        {
            printf("error while trying to malloc"); 
        }
        *header = head;

        head->node_num = 0;
        head->edges = 0;
        head->next = 0;

        pointerToHead = head;

        size_t i = 1;
        while (i < amountOfNodes)
        {
            tempNode = (pnode)malloc(sizeof(node));
            if (tempNode == 0)
            {
                printf("error while trying to malloc"); 
            }
            tempNode->node_num = i;
            tempNode->next = 0;
            tempNode->edges = 0;
            pointerToHead->next = tempNode;
            pointerToHead = pointerToHead->next;
            i++;
        }
    // *header = &head;
}

void deleteGraph_cmd(pnode* head)
{
    pnode currNode = *head;
    pnode tempNode;
    pedge currEdges;
    pedge tempEdges;

    while (currNode != NULL )
    {
        currEdges = currNode->edges;
        while (currEdges != NULL)
        {
            tempEdges = currEdges;
            currEdges = currEdges->next;
            free(tempEdges);
        }
        tempNode = currNode;
        currNode = currNode->next;
        free(tempNode);
    }
}

