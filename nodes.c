#include "graph.h"

void insert_new_node_cmd(pnode *head)
{
    int nameOfNode; 
    pnode theNode = 0;
    scanf("%d", &nameOfNode);
    theNode = findNode(head, nameOfNode);

    if(theNode == 0)
    {
        theNode = (pnode)malloc(sizeof(node));
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

pnode findNodeBefore(pnode head, int nameOfNode)
{
    pnode curr = head;
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
    printf("didnt find");
    return NULL; 
}

void delete_node_cmd(pnode *head)
{
    int nameOfNode;
    scanf("%d", &nameOfNode);

    pnode curr = *head;
    pnode needToBeDeleted = findNode(*head, nameOfNode);
    pnode oneBefore = findNodeBefore(*head, nameOfNode);
    pedge currEdge = curr->edges;
    pedge tempEdge = 0;

    while (curr != 0)
    {
        if (curr == needToBeDeleted)
        {
            curr= curr->next;
        }
        
        while (currEdge != 0)
        {
            if (currEdge->endpoint == needToBeDeleted)
            {
                tempEdge = currEdge;
                currEdge = currEdge->next;
                free(tempEdge);
            }
        }
        oneBefore->next = needToBeDeleted->next;
        free(needToBeDeleted);   
    }   
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