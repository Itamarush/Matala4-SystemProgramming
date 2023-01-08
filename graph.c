#include "graph.h"

void build_graph_cmd(pnode *head)
{
    // it means that a graph is already exists and we wanna delete the old one

    if (*head != NULL)
    {
        void deleteGraph_cmd(pnode* head);
    }

    // gets the amount of nodes from the user
    int amountOfNodes;
    scanf("%d", &amountOfNodes);

    // gets the nodes numbers and its edges
    int counter = 0;
    while (counter < amountOfNodes)
    {

        pnode new_node = (pnode)malloc(sizeof(node));

        pedge new_edge = malloc(2 * sizeof(edge)); 
        new_edge[counter].endpoint = NULL;
        new_edge[counter].weight = INF;
        new_edge[counter].next = new_edge + 1;
        counter++;
        new_edge[counter].endpoint = NULL;
        new_edge[counter].weight = INF;
        new_edge[counter].next = NULL;
        new_node->edges = new_edge;
        new_node->next = NULL;
    }
}

void insert_node_cmd(pnode *head)
{
    int stay = 1;
    char newChar;
    int nameOfNode, toWhichNode1, weightOfEdge1, toWhichNode2, weightOfEdge2; 
    while (stay)
    {
        scanf("%c", &newChar);
        if (newChar == 'n')
        {   
            int counter = 0;
            scanf("%d", &nameOfNode);
            pnode new_node = (pnode)malloc(sizeof(node));
            new_node->node_num = nameOfNode;

            while (stay)
            {
                int returnValue = scanf("%d,%d,%d,%d", &toWhichNode1, &weightOfEdge1, &toWhichNode2, &weightOfEdge2);
                if(returnValue < 2)
                {
                    stay = 0;
                    break;
                }
                pedge new_edge = malloc(2*sizeof(edge));
                new_edge[counter].endpoint = toWhichNode1;
                new_edge[counter].weight = weightOfEdge1;
                new_edge[counter].next = new_edge + 1;
                counter++;
                new_edge[counter].endpoint = (pnode)toWhichNode2;
                new_edge[counter].weight = weightOfEdge2;
                new_edge[counter].next = NULL;
                new_node->edges = new_edge;

                new_node->next = NULL;
                stay = 0;
            }   
        }
    }   
}

pnode findNode(pnode head, int nameOfNode)
{
    pnode curr = head;
    pnode before = curr;
    do
    {      
        if(curr == NULL)
        {
            return 0;
        }

        if (curr->node_num = nameOfNode)
        {
            return before;
        }
        before = curr;
        curr = curr->next;
        
    }
    while(curr->next != NULL);  
    printf("didnt find");
    return NULL; 
}

void delete_node_cmd(pnode *head)
{
    int nameOfNode;
    scanf("%d", &nameOfNode);

    pnode needToBeDeleted = findNode(head, nameOfNode);

    if (needToBeDeleted == *head)
    {
        *head = needToBeDeleted->next;
    }
    else
    {
        needToBeDeleted->next = needToBeDeleted->next->next;
    }
}

void shortsPath_cmd(pnode head);


