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

// void delete_node_cmd(pnode *head)
// {
//     int nameOfNode;
//     scanf("%d", &nameOfNode);

//     pnode curr = *head;
//     pnode needToBeDeleted = findNode(head, nameOfNode);
//     pnode oneBefore = findNodeBefore(head, nameOfNode);
//     pedge currEdge = curr->edges;
//     pedge tempEdge;

//     while (curr != NULL)
//     {
//         //update edges list
//         if (curr->node_num == nameOfNode) {
//             if (curr->edges != NULL) {
//                 tempEdge = curr->edges;
//                 while (tempEdge != NULL) {
//                     pedge temp = tempEdge;
//                     tempEdge = tempEdge->next;
//                     free(temp);
//                 }
//             }
//             // update oneBefore->next
//             oneBefore->next = needToBeDeleted->next;
//             free(needToBeDeleted);
//             break;
//         }
//         else {
//             currEdge = curr->edges;
//             while (currEdge != NULL)
//             {
//                 if (currEdge->endpoint->node_num == nameOfNode)
//                 {
//                     tempEdge = currEdge;
//                     currEdge = currEdge->next;
//                     if (tempEdge == curr->edges) {
//                         curr->edges = currEdge;
//                     }
//                     free(tempEdge);
//                 }
//                 else
//                     currEdge = currEdge->next;
//             }
//         }
//         curr = curr->next;
//     }
// }



void delete_node_cmd(pnode *head)
{
    int node_num;
    scanf("%d", &node_num); // get node number to delete

    pnode node = find_node(*head, node_num);
    if (node == NULL) // node does not exist
    {
        printf("0.Error: node %d does not exist\n", node_num);
        exit(1);
    }
    free_node(head, node); // delete node
};

void free_node(pnode *head, pnode node)
{
    if (node == *head) // node is head
    {
        *head = node->next;
    }
    else // node is not head
    {
        pnode before = find_node_before(*head, node->node_num);
        before->next = node->next;
    }
    disconnect_node(*head, node); // find nodes with edges to node and disconnect them
    free_edges(node->edges);
    free(node);
};

void disconnect_node(pnode head, pnode nodeToDisconnect)
{
    pnode temp = head;
    while (temp != NULL) // look for nodes with edges to node_num
    {
        if (temp->edges != NULL)
        {
            pedge edge = find_edge_to(temp->edges, nodeToDisconnect);
            if (edge != NULL) // node has edge to nodeToDisconnect
            {
                if (edge == temp->edges) // edge is head
                {
                    temp->edges = edge->next;
                }
                else // edge is not head
                {
                    pedge before = find_edge_before(temp->edges, edge->endpoint);
                    before->next = edge->next;
                }
                free(edge);
            }
        }
        temp = temp->next;
    }
};

void free_edges(pedge head)
{
    if (head == NULL) // empty list
    {
        return;
    }
    pedge temp = head;
    while (temp->next != NULL) // go over all edges in list
    {
        pedge temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    free(temp);
};

pedge find_edge_before(pedge head, pnode endpoint)
{
    if (head == NULL) // empty list
    {
        return NULL;
    }
    pedge temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->endpoint == endpoint)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
};

pedge find_edge_to(pedge head, pnode endpoint)
{
    if (head == NULL) // empty list
    {
        return NULL;
    }
    if (head->endpoint == endpoint) // edge is head
    {
        return head;
    }
    pedge before = find_edge_before(head, endpoint); // edge is not head
    return before != NULL ? before->next : NULL;     // edge found
};

pnode find_node(pnode head, int node_num)
{
    if (head == NULL)
    { // empty list
        return NULL;
    }
    if (head->node_num == node_num) // node is head
    {
        return head;
    }
    pnode before = find_node_before(head, node_num); // node is not head
    if (before == NULL)                              // node not found
    {
        return NULL;
    }
    return before->next; // node found
};

pnode find_node_before(pnode head, int node_num)
{
    if (head == NULL)
    { // empty list
        return NULL;
    }
    pnode temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->node_num == node_num)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
};