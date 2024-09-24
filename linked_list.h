#pragma once

typedef struct sNode{
    struct sNode* next;
    int value;
}node_t;

typedef struct sLinkedList {
    node_t* head;
    unsigned int counter;
}linked_list_t;

void add_node_to_end(linked_list_t* pList, int val);
void add_node_in_order(linked_list_t* pList, int val);
void remove_head_node(linked_list_t* pList);
void remove_tail_node(linked_list_t* pList);
void remove_node_with_index(linked_list_t* pList, int index);
void remove_node_with_value(linked_list_t* pList, int value);
void print_linked_list(const linked_list_t* pList);
