#include <stdio.h>
#include <stdlib.h>
#include "page.h"

void list_check(node_type** head) {
    node_type* p = *head;
    printf("\n");
    printf("\n");
    while (p != NULL)
    {
        printf("\n");
        printf("\n");
        printf("주식 no.%d\n", p ->data.index);
        printf("주식 이름:%s\n", p->data.stock_name);
        printf("주식의 현재가:%d\n", p->data.now_price);
        printf("주식의 과거가:%d\n", p->data.past_price);
        printf("주식의 수:%d\n", p->data.stock_count);
        printf("\n");
        printf("\n");
        p = p->next;
    }
    printf("\n");
    printf("\n");
}
void list_add(node_type** head)
{
    node_type* newNode = malloc(sizeof(node_type));
    //리스트가 비어 있으면 여기서 head 초기화 후 종료
    if (!newNode) {
        printf("메모리 할당 실패\n");
        return;
    }
    int idx = 1;
    node_type* t = *head;
    while (t != NULL) {
        idx++;
        t = t->next;
    }
    newNode->data.index = idx;
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
void delete_stock(node_type** head) {
    int dex;
    node_type* p = *head;
    node_type* prev = NULL;
    printf("\n");
    printf("\n");
    printf("제거할 주식의 번호을 알려주세요:");
    scanf_s("%d", &dex);
    printf("\n");
    printf("\n");

    // 1) 첫 번째 노드 삭제
    if (p->data.index == dex) {
        *head = p->next;
        free(p);
        printf("번호 %d 번 주식이 삭제되었습니다.\n", dex);
        return;
    }

    // 2) 나머지 노드 삭제
    while (p != NULL) {
        if (p->data.index == dex) {
            prev->next = p->next;  // 이전 노드가 다음 노드를 가리키게 함
            free(p);
            printf("번호 %d 번 주식이 삭제되었습니다.\n", dex);
            return;
        }
        prev = p;
        p = p->next;
    }

    printf("해당 번호의 주식은 존재하지 않습니다.\n");
}

void add_stock(node_type** head) {
    node_type* p;
    p = *head;
    int dex;
    int add_count;
    int new_price;
    printf("\n");
    printf("\n");
    printf("추가 매수 할 주식의 번호을 알려주세요:");
    scanf_s("%d", &dex);
    printf("\n");
    printf("\n");
    while (p != NULL) {

        if (p->data.index == dex) {

            int add_count;
            int buy_price;

            printf("추가 매수할 수량을 입력하세요: ");
            scanf_s("%d", &add_count);

            printf("추가 매수 가격(1주 가격)을 입력하세요: ");
            scanf_s("%d", &buy_price);

            // 계산 시작
            int old_total = p->data.past_price * p->data.stock_count;
            int add_total = buy_price * add_count;
            int new_count = p->data.stock_count + add_count;
            double new_avg = (double)(old_total + add_total) / new_count;

            int old_loss = (p->data.past_price - p->data.now_price) * p->data.stock_count;
            int new_loss = (new_avg - p->data.now_price) * new_count;
            double reduced_loss = (double)old_loss - (double)new_loss;

            printf("\n===== 물타기 결과 =====\n");
            printf("기존 매입 단가: %d원\n", p->data.past_price);
            printf("추가 매수 단가: %d원\n", buy_price);
            printf("기존 보유 수량: %d주\n", p->data.stock_count);
            printf("추가 매수 수량: %d주\n\n", add_count);

            printf("새 평균 단가: %.2f원\n", new_avg);
            printf("기존 손실: %d원\n", old_loss);
            printf("새로운 손실: %.2f원\n", (double)new_loss);
            printf("손실 감소량: %.2f원\n", reduced_loss);

            printf("======================\n\n");

            return;
        }

        p = p->next;
    }

    printf("해당 번호의 주식이 존재하지 않습니다.\n");

}
void charge_calculate(node_type** head) {
    /* 수수료 = 0.0035  (0.35%)
       거래세 = 0.0023  (0.23%)     매도 시만
       */
    node_type* p;
    p = *head;
    int dex;
    printf("\n");
    printf("\n");
    printf("세금을 계산할 주식의 번호을 알려주세요:");
    scanf_s("%d", &dex);
    printf("\n");
    printf("\n");

    while (p != NULL) {

        if (p->data.index == dex) {

            int now_price = p->data.now_price; //포인터를 사용하지 않은 이유? ->immutable로 사용하기 위해
            int count = p->data.stock_count;

            double sell_total = (double)now_price * count;     // 매도 금액
            double fee = sell_total * 0.0035;                  // 0.35% 증권사 수수료
            double tax = sell_total * 0.0023;                  // 0.23% 거래세
            double real_income = sell_total - fee - tax;

            printf("\n========== 수수료 / 거래세 계산 결과 ==========\n");
            printf("주식 번호: %d\n", p->data.index);
            printf("주식 이름: %s\n", p->data.stock_name);
            printf("현재 가격: %d원\n", now_price);
            printf("보유 수량: %d주\n", count);
            printf("----------------------------------------------\n");
            printf("총 매도 금액: %.2f원\n", sell_total);
            printf("증권사 수수료(0.35%%): %.2f원\n", fee);
            printf("거래세(0.23%%): %.2f원\n", tax);
            printf("----------------------------------------------\n");
            printf("실제로 받는 금액: %.2f원\n", real_income);
            printf("==============================================\n\n");

            return;
        }

        p = p->next;
    }

    printf("해당 번호의 주식이 존재하지 않습니다.\n");
}
void all_sell(node_type** head) {
    node_type* p;
    p = *head;
    int total = 0;
    while (p != NULL) {
        if (p->data.past_price < p->data.now_price) //현재가가 더 클때만 연산하기
        {
            total += (p->data.now_price - p->data.past_price); //합산
        }
        p = p->next;//다음 노드로 넘어가기
    }
    printf("\n");
    printf("\n");
    printf("이익 본 것을 다 팔면 %d 원입니다\n.",total);
    printf("\n");
    printf("\n");
}