#include <stdio.h>
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
    scanf("d", &amountOfNodes);

    // gets the nodes numbers and its edges
    char ch;
    while (1)
    {
        ch = getchar();
    }
}

void insert_node_cmd(pnode *head)
{
    int stay = 1;
    char newChar;
    int nameOfNode, toWhichNode, weightOfEdge; 
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
                int returnValue = scanf("%d%d", toWhichNode, weightOfEdge);
                if(returnValue < 2)
                {
                    stay = 0;
                    break;
                }
                pedge new_edge = malloc(2*sizeof(edge));
                new_edge[counter].endpoint = toWhichNode;
                new_edge[counter].weight = weightOfEdge;
                new_edge[counter].next = new_edge + 1;
                new_node->edges = new_edge;
            }
            
        }
        
    }   
}

pnode create_node(int node_num, pnode to1, int edge1_w, pnode to2, int edge2_w)
{
    pnode new_node = (pnode)malloc(sizeof(node));
    new_node->node_num = node_num;

    pedge pedges = malloc(2 * sizeof(edge)); // allocate space for 2 edges
    pedges[0].endpoint = to1;                // set the first edge
    pedges[0].weight = edge1_w;
    pedges[0].next = pedges + 1;
    pedges[1].endpoint = to2; // set the second edge
    pedges[1].weight = edge2_w;
    pedges[1].next = NULL;
    new_node->edges = pedges;

    new_node->next = NULL;

    new_node->d = -1; // used for dijkstra
    new_node->isVisited = -1;

    return new_node;
};

