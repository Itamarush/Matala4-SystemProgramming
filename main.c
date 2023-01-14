#include "graph.h"
void insert_new_node_cmd(pnode *head);
int main()
{
    pnode head = 0;
    char choise, newChar, c;
    int stay = 1;

    while (EOF != scanf("%c", &choise))
    {
        scanf("%c", &c);
        if (choise == 'A')
        {
            deleteGraph_cmd(&head);
            build_graph_cmd(&head);
            scanf("%c", &c);

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
            choise = newChar;
        }
        if (choise == 'B')
        {
            insert_new_node_cmd(&head);
        }
        if (choise == 'D')
        {
            delete_node_cmd(&head);
        }
        if (choise == 'S')
        {
            shortsPath_cmd(&head);
        }
        if (choise == 'T')
        {
            TSP_cmd(&head);
        }

        if (choise != ' ')
        {
            stay = 0;
            break;
        }
    }

    deleteGraph_cmd(&head);
    return 0;
};