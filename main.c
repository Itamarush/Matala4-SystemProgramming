#include "graph.h"
void insert_new_node_cmd(pnode *head);
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
            while (scanf("%c", &newChar) != 0)
            {               
            if (newChar == 'n')
                {
                    insert_node_cmd(&head);
                }
            else
                {
                    break;
                } 
            }
           
        }
        else if (c == 'B')
        {
            insert_new_node_cmd(&head);
        }
        else if (c == 'D')
        {
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

        else if (c != ' ')
        {
            stay = 0;
            break;
        }
    }

    deleteGraph_cmd(&head); // free memory
    return 0;
};