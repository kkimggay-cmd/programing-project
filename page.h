
#ifndef PAGE_H
#define PAGE_H
typedef struct data {
    int index;
    char stock_name[100];
    int past_price;
    int now_price;
    int stock_count;
} data_type;

typedef struct node {
    data_type data;
    struct node* next;
} node_type;

void exsist_list_page(int* list_count);
void unexsist_list_page();
int length_list(node_type* h);
void list_check(node_type** head);
void list_add(node_type** head);
void delete_stock(node_type** head,int*p1,int*p2);
void add_stock(node_type** head);
void charge_calculate(node_type** head);
void all_sell(node_type** head);

#endif
