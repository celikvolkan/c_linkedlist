#include <stdio.h>
#include <stdlib.h> // stdlib
#include "linked_list.h"

#define INPUT_SIZE    (100)

const char menu_string[] =  "**********************  MENU  **************************\n" \
                            "'+' Add Node\n'-' Remove Node\n'*' Print the linked list\n'/' Exit from the program\n'm' See this menu\n" \
                            "********************************************************\n";

void add_node(linked_list_t* pList, int val)
{
    // add_node_to_end(pList, val);
    add_node_in_order(pList, val);
}

int main(void)
{
    linked_list_t linked_list = {.head = NULL, .counter = 0};
    char input[INPUT_SIZE] = { 0 };
    char ch = 0;

    printf("%s", menu_string);

    do {
        printf("\nMenu command: ");
        gets_s(input, INPUT_SIZE);
        ch = input[0];
        switch (ch) {
            case'+': {
                printf("Enter value of the node to add: ");
                gets_s(input, INPUT_SIZE);
                add_node(&linked_list, atoi(input));
                break;
            }
            case'-': {                
                // remove_head_node(&head);
                remove_tail_node(&linked_list);
                // printf("Enter value of the node to remove: ");
                // gets_s(input, INPUT_SIZE);
                break;
            }
            case'*': {
                print_linked_list(&linked_list);
                break;
            }
            case'/': {
                printf("\nGOOD BYE!..\n\n");
                break;
            }
            case'm': {
                printf("%s", menu_string);
                break;
            }
            default: {
                printf("Undefined input!\n");
                break;
            }
        }
    } while (ch != '/');

    return 0;
}
