#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define INIT_CAPACITY 3000

int offset[8][2] = { {-1,0},{-1, 1}, {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

//현재 위치(cur)를 받아서 이동한 위치를 반환
Position move_to(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[dir][1];
	//printf("위치 이동: (%d, %d)\n", next.x, next.y);
	return next;
}

Stack create() {
	//stack_type을 가리키는 구조체 포인터 선언& 동시에 구조체도 생성됨
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) printf("error founded!");
	
	//중요!!!, 구조체를 가질 수 있는 동적할당된 스택공간을 배열처럼 사용가능
	s->contents = (Position*)malloc(INIT_CAPACITY * sizeof(Position));//stack_type의 Item형 배열 포인터에 스택들어갈 공간 할당
	if (s->contents == NULL) {
		free(s);
	}
	s->top = -1;//초기값
	s->size = INIT_CAPACITY;//스택의 (최대)크기
	return s;
}

void push(Stack s, Position cur) {
	s->top++;
	s->contents[s->top] = cur;
}

Position pop(Stack s) {
	return s->contents[s->top--];
}
bool is_empty(Stack s) {
	if (s->top > -1) return false;
	return true;
}
