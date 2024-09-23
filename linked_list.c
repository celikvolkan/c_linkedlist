#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


void add_node_to_end(node_t** pHead, int val)
{
    if (pHead == NULL) { // Error
        return;
    }
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->value = val;
    new_node->next = NULL;
    if (*pHead == NULL) { // empty linked list
        *pHead = new_node;        
        return;
    }    
    node_t* pNode = *pHead;
    while(pNode->next != NULL) {
        pNode = pNode->next;
    }
    pNode->next = new_node;
}

// value ascending order
void add_node_in_order(node_t** pHead, int val)
{
    if (pHead == NULL) { // Error
        return;
    }
    node_t* new_node = malloc(sizeof(node_t));
    if (NULL == new_node) {
        return;
    }
    new_node->value = val;
    new_node->next = NULL;
    if (*pHead == NULL) { // empty linked list
        *pHead = new_node;
        return;
    }
        
    node_t* pNode = *pHead;
    if (new_node->value < pNode->value) { // new_node has the smallest value
        *pHead = new_node;
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

static bool check_before_remove_node(const node_t** pHead)
{
    if (pHead == NULL) {
        printf("Error! NULL input\n");
        return false;
    }

    if (*pHead == NULL) {
        printf("Empty Linked List!\n");
        return false;
    }
    
    return true;
}

void remove_head_node(node_t** pHead)
{
    if (check_before_remove_node(pHead) == false) {
        return; 
    }

    node_t* pNode = *pHead;
    *pHead = (*pHead)->next;
    free(pNode);
    printf("Removed head node successfully!\n");
}

void remove_tail_node(node_t** pHead)
{
    if (check_before_remove_node(pHead) == false) {
        return;
    }
    
    node_t* pNode = *pHead;
    if (pNode->next == NULL) { // 1 element Linked List
        free(pNode);
        *pHead = NULL;
        printf("Removed last remaining node successfully!\n");
        return;
    }
        
    node_t* pNextNode = pNode->next;

    while (pNextNode->next != NULL) {
        pNode = pNextNode;
        pNextNode = pNextNode->next;
    }
    free(pNextNode);
    pNode->next = NULL;

    printf("Removed tail node successfully!\n");
}

void remove_node_with_index(int index)
{

}

void remove_node_with_value(int value)
{

}

void print_linked_list(const node_t** pHead)
{
    if (pHead == NULL) {
        printf("Error in pHead!\n");
        return;
    }
    
    if (*pHead == NULL) {
        printf("Empty Linked List!\n");
        return;
    }

    const node_t* pNode = *pHead;

    while (pNode != NULL) {
        printf("%d", pNode->value);
        printf("->");
        pNode = pNode->next;
    }
    printf("NULL\n");
}