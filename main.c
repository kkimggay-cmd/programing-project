#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "page.h"
void free_all(node_type* h) //모든 malloc를 free 해주기 위한 함수
{
	node_type* p, * p2; //포인터 두개 선언
	p = h; 

	while (p != NULL) //마지막까지 반복
	{
		p2 = p; //포인터에 temp시키기
		p = p->next; //다른 포인터는 넘어가고
		free(p2);//temp 시킨 포인터는 free
	}
}

int length_list(node_type* h) //리스트의 길이 측정하는 함수
{
	node_type* p; //list 포인터 불러옴
	p = h;
	int count = 0; //수 세는 변수

	while (p != NULL) //마지막까지 반복
	{
		count = count + 1; //후위증가
		p = p->next; //다음 노드로 넘어가기
	}
	return count;
}


int main() {
	int is_list_exsist =0; //list 존재여부 판단하기 위한 변수

	int menu = 0;//메뉴값을 받기 위한 변수
	node_type* head = NULL;
	int list_count= length_list(head);//리스트 갯수를 받아내기 위한 변수

	/* linked list를 응용하기 ->11주차 응용*/
	while (menu != 7) //
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
			else if (menu == 4) {
				add_stock(&head); //주 기능 -> 마이너스 된 가격 매우는 기능
				if (list_count == 1) {
					is_list_exsist = 0;
					list_count = 0;
				}
			}
			else if (menu == 3) {
				delete_stock(&head);
			}
			else if (menu == 5) {
				charge_calculate(&head); //수수료 연산 기능
			}
			else if (menu == 6) { //이익을 본 주식 다 팔면 얼마 이익인지 연산하는 기능
				all_sell(&head);
			}
			else if (menu == 7) { //나가기
				free_all(head);
				return 0;
			}
		}
		else { //list가 없을때
			unexsist_list_page();
			scanf_s("%d", &menu);
			if (menu == 2) { //메뉴 2번만 정상 작동 하므로 2번 먼저 실행하도록 유도시킴
				list_add(&head);
				is_list_exsist=1; //2번이 완료되면 신호 줘서 list가 있는 조건으로 실행
				list_count = 1; //++를 안 쓴 이유? -> no list page가 한번 더 나타났을 때 0 or 1로 나오지 않으면 에러 생길 수 있음
			}
			else if (menu == 7) { //나갔을때 free 해주기
				free_all(head);
				return 0;
			}
			else {//2번 외 다른 선택지를 선택하였을 때
				printf("현재 리스트가 없습니다. 2번을 통해 리스트를 먼저 생성하세요.\n");
			}
		}
	}
	return 0;
}