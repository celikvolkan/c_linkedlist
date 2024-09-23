#include <stdio.h>
#include <stdlib.h> // stdlib
#include "linked_list.h"

#define INPUT_SIZE    (100)

const char menu_string[] =  "**********************  MENU  **************************\n" \
                            "'+' Add Node\n'-' Remove Node\n'*' Print the linked list\n'/' Exit from the program\n'm' See this menu\n" \
                            "********************************************************\n";

void add_node(node_t** ll_head, int val) 
{
    // add_node_to_end(ll_head, val);
    add_node_in_order(ll_head, val);
}

int main(void)
{
    node_t* head = NULL;
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
                add_node(&head, atoi(input));
                break;
            }
            case'-': {                
                printf("Enter value of the node to remove: ");
                gets_s(input, INPUT_SIZE);
                break;
            }
            case'*': {
                print_linked_list(NULL);
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
