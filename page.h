void exsist_list_page(int* list_count);
void unexsist_list_page();

#ifndef PAGE_H
#define PAGE_H

typedef struct data {
    char stock_name[100];
    int past_price;
    int now_price;
    int stock_count;
} data_type;

typedef struct node {
    data_type data;
    struct node* next;
} node_type;

int length_list(node_type* h); 

#endif
