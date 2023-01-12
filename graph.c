#include "graph.h"


void build_graph_cmd(pnode *head)
{
    int amountOfNodes;
    scanf("%d", &amountOfNodes);

    int counter = 0;
    while (counter < amountOfNodes)
    {

        pnode new_node = (pnode)malloc(sizeof(node));
        if (new_node == 0)
        {
            printf("error while trying to malloc"); 
        }

        node *head = 0;
        head->node_num = 0;
        head->edges = 0;
        head->next = 0;

        pnode mallocNode = 0;
        pnode tempNode;
        size_t i = 0;
        while (i < amountOfNodes)
        {
            mallocNode = (pnode)malloc(sizeof(node));
            if (mallocNode == 0)
            {
                printf("error while trying to malloc"); 
            }
            new_node->node_num = i;
            tempNode->next = new_node;
            tempNode = tempNode->next;
            i++;
        }
    }
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

