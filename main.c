#include <stdio.h>
#include "graph.h"
// #include "graph.c"

int main()
{

    pnode head = NULL;
    char c, newChar;
    int stay = 1;

    while (EOF != c && stay == 1)
    {
        c = getchar();

        if (c == 'A')
        {
            deleteGraph_cmd(&head);
            build_graph_cmd(&head);
            scanf("%c", &newChar);
            if (newChar == 'n')
            {
                insert_node_cmd(&head);
            }
            
        }
        else if (c == 'B')
        {
            // add new node to graph
            insert_node_cmd(&head);
        }
        else if (c == 'D')
        {
            // delete node from graph
            delete_node_cmd(&head);
        }
        else if (c == 'S')
        {
            // shortest path
            shortsPath_cmd(head);
        }
        else if (c == 'T')
        {
            // travelling salesman problem
            TSP_cmd(head);
        }
        else if (c == 'P')
        {
            // print graph
            printGraph_cmd(head);
        }
        else if (c != ' ')
        {
            stay = 0;
            break;
        }
    }

    deleteGraph_cmd(&head); // free memory
    return 0;
};