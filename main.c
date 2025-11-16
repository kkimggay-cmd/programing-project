#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "page.h"
#include "func.h"
void free_all(node_type* h)
{
	node_type* p, * p2;
	p = h;

	while (p != NULL)
	{
		p2 = p;
		p = p->next;
		free(p2);
	}
}

int length_list(node_type* h)
{
	node_type* p;
	p = h;
	int count = 0;

	while (p != NULL)
	{
		count = count + 1;
		p = p->next;
	}
	return count;
}


int main() {
	int is_list_exsist =0; //list 존재여부 판단하기 위한 변수

	int menu = 0;//메뉴값을 받기 위한 변수
	node_type* head = NULL;
	int list_count= length_list(head);//리스트 갯수를 받아내기 위한 변수

	/* linked list를 응용하기 ->11주차 응용*/
	while (menu != 6) //
	{
		if (is_list_exsist == 1) {//list가 존재한다면
			exsist_list_page(&list_count);//page 펼치기

			scanf_s("%d", &menu);//메뉴값 받기
			if (menu == 1) {
				list_check(head); //리스트 내용 확인하기
			}
			else if (menu == 2) {
				list_add(&head); //리스트 추가하기
				is_list_exsist = 1;
				list_count++;
			}
			else if (menu == 3) {
				add_stock(); //주 기능 -> 마이너스 된 가격 매우는 기능
			}
			else if (menu == 4) {
				charge_calculate(); //수수료 연산 기능
			}
			else if (menu == 5) { //이익을 본 주식 다 팔면 얼마 이익인지 연산하는 기능
				all_sell();
			}
			else if (menu == 6) { //나가기
				free_all(head);
				return 0;
			}
		}
		else { //if와 동일한 코드 list가 없다면
			unexsist_list_page();
			scanf_s("%d", &menu);
			if (menu == 2) {
				list_add(&head);
				is_list_exsist=1;
				list_count = 1;
			}
			else if (menu == 6) {
				free_all(head);
				return 0;
			}
			else {
				printf("현재 리스트가 없습니다. 2번을 통해 리스트를 먼저 생성하세요.\n");
			}
		}
	}
	return 0;
}