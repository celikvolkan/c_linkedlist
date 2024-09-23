#pragma once

typedef struct sNode{
    struct sNode* next;
    int value;
}node_t;

void add_node_to_end(node_t** ll_head, int val);
void add_node_in_order(node_t** ll_head, int val);
void remove_head_node();
void remove_tail_node();
void remove_node_with_index(int index);
void remove_node_with_value(int value);
void print_linked_list(const node_t** ll_head);
