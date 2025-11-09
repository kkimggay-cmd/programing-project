#include <stdio.h>
typedef struct Node { //리스트에 추가를 위한 노드 정의
    int data;
    struct Node* next;
} Node;

Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    // 배열 → 연결 리스트 변환 함수
    Node* arrayToLinkedList(int arr[], int size) {
        if (size == 0) return NULL;

        Node* head = NULL, * tail = NULL;

        for (int i = 0; i < size; i++) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = arr[i];
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode; // 첫 노드가 head
                tail = newNode;
            }
            else {
                tail->next = newNode; // 끝에 새 노드 연결
                tail = newNode;
            }
        }

        return head;
    }

void list_check() {

}
void list_add() {

}
void add_stock() {

}
void charge_calculate() {

}
void all_sell() {

}