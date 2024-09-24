#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"


void add_node_to_end(linked_list_t* pList, int val)
{
    if (pList == NULL) { // Error
        return;
    }
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->value = val;
    new_node->next = NULL;
    if (pList->head == NULL) { // empty linked list
        pList->head = new_node;        
        return;
    }    
    node_t* pNode = pList->head;
    while(pNode->next != NULL) {
        pNode = pNode->next;
    }
    pNode->next = new_node;
}

// value ascending order
void add_node_in_order(linked_list_t* pList, int val)
{
    if (pList == NULL) { // Error
        return;
    }
    node_t* new_node = malloc(sizeof(node_t));
    if (NULL == new_node) {
        return;
    }
    new_node->value = val;
    new_node->next = NULL;
    if (pList->head == NULL) { // empty linked list
        pList->head = new_node;
        return;
    }
        
    node_t* pNode = pList->head;
    if (new_node->value < pNode->value) { // new_node has the smallest value
        pList->head = new_node;
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

static bool check_before_remove_node(const linked_list_t* pList)
{
    if (pList == NULL) {
        printf("Error! NULL input\n");
        return false;
    }

    if (pList->head == NULL) {
        printf("Empty Linked List!\n");
        return false;
    }
    
    return true;
}

void remove_head_node(linked_list_t* pList)
{
    if (check_before_remove_node(pList) == false) {
        return; 
    }

    node_t* pNode = pList->head;
    pList->head = (pList->head)->next;
    free(pNode);
    printf("Removed head node successfully!\n");
}

void remove_tail_node(linked_list_t* pList)
{
    if (check_before_remove_node(pList) == false) {
        return;
    }
    
    node_t* pNode = pList->head;
    if (pNode->next == NULL) { // 1 element Linked List
        free(pNode);
        pList->head = NULL;
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

void remove_node_with_index(linked_list_t* pList, int index)
{
    if (check_before_remove_node(pList) == false) {
        return;
    }

    if (index < 0) {
        printf("Error! Negative index: %d\n", index);
        return;
    }

    if (index == 0) {
        remove_head_node(pList);
        return;
    }
    // Here index is 1 or more
    node_t* pNode = pList->head;
    if (pNode->next == NULL) { // 1 element Linked List && index > 0
        printf("Error! Wrong index for 1 element linked list. Index: %d\n", index);
        return;
    }

        
}

void remove_node_with_value(linked_list_t* pList, int value)
{
    if (check_before_remove_node(pList) == false) {
        return;
    }

}

void print_linked_list(const linked_list_t* pList)
{
    if (check_before_remove_node(pList) == false) {
        return;
    }

    const node_t* pNode = pList->head;

    while (pNode != NULL) {
        printf("%d", pNode->value);
        printf("->");
        pNode = pNode->next;
    }
    printf("NULL\n");
}