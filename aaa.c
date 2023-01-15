#include "graph.h"

pnode getNode(int id, pnode *head){

    pnode check = *head;

    while (check != NULL)
    {
        if (check -> node_num ==id)
        {
            return check;
        }
        check = check -> next;
    }
    return NULL;
}

void add_edge1(pnode newNode, int dest, int weight, pnode *head)
{

    if (newNode->edges == NULL)
    {
        newNode->edges = (pedge)malloc(sizeof(edge));
        if (newNode->edges == NULL)
        {
            perror("malloc didnt work");
            exit(0);
        }
        newNode->edges->weight = weight;
        newNode->edges->next = NULL;
        node *destNode = getNode(dest, head);
        newNode->edges->endpoint = &(*destNode);
    }
    else
    {
        pedge nodeEdges = newNode->edges;
        while (nodeEdges->next != NULL)
        {
            nodeEdges = nodeEdges->next;
        }
        //add the new edge
        nodeEdges->next = (pedge)malloc(sizeof(edge));
        if (nodeEdges->next == NULL)
        {
            perror("malloc didnt work");
        }
        nodeEdges->next->next = NULL;
        nodeEdges->next->weight = weight;
        node *destNode = getNode(dest, head);
        nodeEdges->next->endpoint = &(*destNode);
    }
}

void insert_new_node_cmd(pnode *head)
{
    int src;
    scanf("%d", &src);
    int dest;
    int weight;
    pnode temp = getNode(src, head);
    if (temp == NULL)
    {
        pnode pGraphNode = *head;
        while (pGraphNode->next != NULL)
        {
            pGraphNode = pGraphNode->next;
        }
        pnode newNode = (pnode)(malloc(sizeof(node)));
        if (newNode == NULL)
        {
            perror("malloc didnt work");
            exit(0);
        }
        newNode->node_num = src;
        newNode->edges = NULL;
        newNode->next = NULL;
        pGraphNode->next = newNode;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                break;
            }
            add_edge1(newNode, dest, weight, head);
        }
    }
    else
    {
        free_edges1(temp);
        temp->edges = NULL;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest) || isalpha(weight))
            {
                break;
            }
            add_edge1(temp, dest, weight, head);
        }
    }
}

void free_edges1(pnode tmpNode)
{
    if (tmpNode->edges != NULL)
    {
        pedge temp = tmpNode->edges;

        while (temp != NULL)
        {
            pedge freeEdge = NULL;
            freeEdge = temp;
            temp = temp->next;
            free(freeEdge);
        }
    }
    else{
        free(tmpNode->edges);
    }
}


