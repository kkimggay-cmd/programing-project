#include <stdio.h>
#include <stdlib.h>
#include "page.h"

void list_check(node_type** head) {
    node_type* p;
    p = head;
    int counting = 1;
    printf("\n");
    printf("\n");
    while (p != NULL)
    {
        
        printf("주식 no.%d\n", counting);
        printf("주식 이름:%s\n", p->data.stock_name);
        printf("주식의 현재가:%d\n", p->data.now_price);
        printf("주식의 과거가:%d\n", p->data.past_price);
        printf("주식의 수:%d\n", p->data.stock_count);
        counting++;

        p = p->next;
    }
    printf("\n");
    printf("\n");
}
void list_add(node_type** head)
{
    node_type* newNode = malloc(sizeof(node_type));

    // ★ 리스트가 비어 있으면 여기서 head 초기화 후 종료
    if (!newNode) {
        printf("메모리 할당 실패\n");
        return;
    }

    printf("추가할 주식 이름을 입력하세요: ");
    scanf_s("%s", newNode->data.stock_name, (unsigned)_countof(newNode->data.stock_name));

    printf("과거 가격을 입력하세요: ");
    scanf_s("%d", &newNode->data.past_price);

    printf("현재 가격을 입력하세요: ");
    scanf_s("%d", &newNode->data.now_price);

    printf("보유한 주식 수량을 입력하세요: ");
    scanf_s("%d", &newNode->data.stock_count);

    newNode->next = NULL;

    // 리스트가 비어있으면 첫 노드가 됨
    if (*head == NULL) {
        *head = newNode;
        printf("새로운 주식이 추가되었습니다.\n.\n");
        return;
    }

    // 리스트 마지막까지 이동
    node_type* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 마지막 노드에 연결
    temp->next = newNode;

    printf("새 주식이 리스트에 추가되었습니다.\n");
}
void add_stock() {

}
void charge_calculate() {

}
void all_sell() {

}