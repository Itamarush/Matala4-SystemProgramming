#include "graph.h"

void insert_new_node_cmd(pnode *head)
{
    int nameOfNode; 
    pnode theNode = 0;
    scanf("%d", &nameOfNode);
    theNode = findNode(head, nameOfNode);

    if(theNode == 0)
    {
        theNode = (pnode)calloc(1, sizeof(node));
        if (theNode == 0)
        {
            exit(0);
        }
        
        pnode lastNode = findLastNode(head);
        lastNode->next = theNode;
        theNode->node_num = nameOfNode;
        theNode->next = 0;
        addEdge(head, theNode);
    }

    else
    {
        freeAllEdges(theNode);
        theNode->edges = 0;
        addEdge(head, theNode);
    }
}

void insert_node_cmd(pnode *head)
{
    int nameOfNode; 
    pnode theNode = 0;
 
    scanf("%d", &nameOfNode);
    theNode = findNode(head, nameOfNode);
    addEdge(head, theNode);
}

pnode findNode(pnode *head, int nameOfNode)
{
    if (head == NULL)
    { 
        return NULL;
    }

    pnode curr = *head;
    
    while (curr != 0)
    {      
        if (curr->node_num == nameOfNode)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL; 
}

pnode findNodeBefore(pnode *head, int nameOfNode)
{
    if (head == NULL)
    {       
        return NULL;
    }

    pnode curr = *head;
    pnode before = curr;
    
    while (curr != 0)
    {      
        if (curr->node_num == nameOfNode)
        {
            return before;
        }
        before = curr;
        curr = curr->next;
    }
    return NULL; 
}

 pnode findLastNode(pnode *head)
 {
    pnode curr = *head;
    while (curr->next != 0)
    {
        curr = curr->next;
    }
    return curr;
 }

void delete_node_cmd(pnode *head)
{
    int nameOfNode;
    scanf("%d", &nameOfNode);

    pnode curr = *head;
    pnode needToBeDeleted = findNode(head, nameOfNode);
    pnode oneBefore = findNodeBefore(head, nameOfNode);
    pedge currEdge = curr->edges;
    pedge tempEdge;

    while (curr != NULL)
    {
        if (curr->node_num == nameOfNode) {
            if (curr->edges != NULL) {
                tempEdge = curr->edges;
                while (tempEdge != NULL) {
                    pedge temp = tempEdge;
                    tempEdge = tempEdge->next;
                    free(temp);
                }
            }
            oneBefore->next = needToBeDeleted->next;
            free(needToBeDeleted);
            break;
        }
        else {
            currEdge = curr->edges;
            while (currEdge != NULL)
            {
                if (currEdge->endpoint->node_num == nameOfNode)
                {
                    tempEdge = currEdge;
                    currEdge = currEdge->next;
                    if (tempEdge == curr->edges) {
                        curr->edges = currEdge;
                    }
                    free(tempEdge);
                }
                else
                    currEdge = currEdge->next;
            }
        }
        curr = curr->next;
    }
}