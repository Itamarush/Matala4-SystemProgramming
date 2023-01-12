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
    return head;
}

void insert_node_cmd(pnode *head)
{
    int stay = 1;
    int nameOfNode, toWhichNode, weightOfEdge; 
    pnode theNode = 0;

    while (stay)
    {
        {   
            scanf("%d", nameOfNode);
            theNode = findNode(head, nameOfNode);
            while (scanf("%d", &toWhichNode) != 0 && scanf("%d", &weightOfEdge) != 0)
            {
                if (isdigit(toWhichNode) && isdigit(weightOfEdge))
                {
                    addEdge(head, theNode, toWhichNode, weightOfEdge);
                }
                else
                {
                    break;
                }
            }
        }
    }   
}

pnode findNode(pnode head, int nameOfNode)
{
    pnode curr = head;
    pnode before = curr;
    
    while (curr != 0)
    {      
        if (curr->node_num = nameOfNode)
        {
            return curr;
        }
        curr = curr->next;
    }
    printf("didnt find");
    return NULL; 
}

pnode findNodeBefore(pnode head, int nameOfNode)
{
    pnode curr = head;
    pnode before = curr;
    
    while (curr != 0)
    {      
        if (curr->node_num = nameOfNode)
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

    pnode needToBeDeleted = findNode(head, nameOfNode);
    pnode oneBefore = findNodeBefore(head, nameOfNode);

    if (needToBeDeleted == *head)
    {
        *head = needToBeDeleted->next;
    }
    else
    {
        
        oneBefore->next = needToBeDeleted->next;
    }
}

void deleteGraph_cmd(pnode* head)
{
    pnode currNode = head;
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

