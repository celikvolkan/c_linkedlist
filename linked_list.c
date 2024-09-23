#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


void add_node_to_end(node_t** ll_head, int val)
{
    if (ll_head == NULL) { // Error
        return;
    }
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->value = val;
    new_node->next = NULL;
    if (*ll_head == NULL) { // empty linked list
        *ll_head = new_node;        
        return;
    }    
    node_t* pNode = *ll_head;
    while(pNode->next != NULL) {
        pNode = pNode->next;
    }
    pNode->next = new_node;
}

// value ascending order
void add_node_in_order(node_t** ll_head, int val)
{
    if (ll_head == NULL) { // Error
        return;
    }
    node_t* new_node = malloc(sizeof(node_t));
    if (NULL == new_node) {
        return;
    }
    new_node->value = val;
    new_node->next = NULL;
    if (*ll_head == NULL) { // empty linked list
        *ll_head = new_node;
        return;
    }
        
    node_t* pNode = *ll_head;
    if (new_node->value < pNode->value) { // new_node has the smallest value
        *ll_head = new_node;
        new_node->next = pNode;
        return;
    }
        
    while (1) {
        if (pNode->next == NULL || (pNode->value <= new_node->value && pNode->next->value > new_node->value)) {
            new_node->next = pNode->next;
            pNode->next = new_node;
            return;
        }
        else {
            pNode = pNode->next;
        }
    }
}


void print_linked_list(const node_t** ll_head)
{
    if (ll_head == NULL) {
        printf("Error in head!\n");
        return;
    }
    
    if (*ll_head == NULL) {
        printf("Empty Linked List!\n");
        return;
    }

    const node_t* pNode = *ll_head;

    while (pNode != NULL) {
        printf("%d", pNode->value);
        printf("->");
        pNode = pNode->next;
    }
    printf("NULL\n");
}