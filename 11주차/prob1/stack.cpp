#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define INIT_CAPACITY 3000

int offset[8][2] = { {-1,0},{-1, 1}, {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

//���� ��ġ(cur)�� �޾Ƽ� �̵��� ��ġ�� ��ȯ
Position move_to(Position pos, int dir) {
	Position next;
	next.x = pos.x + offset[dir][0];
	next.y = pos.y + offset[dir][1];
	//printf("��ġ �̵�: (%d, %d)\n", next.x, next.y);
	return next;
}

Stack create() {
	//stack_type�� ����Ű�� ����ü ������ ����& ���ÿ� ����ü�� ������
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL) printf("error founded!");
	
	//�߿�!!!, ����ü�� ���� �� �ִ� �����Ҵ�� ���ð����� �迭ó�� ��밡��
	s->contents = (Position*)malloc(INIT_CAPACITY * sizeof(Position));//stack_type�� Item�� �迭 �����Ϳ� ���õ� ���� �Ҵ�
	if (s->contents == NULL) {
		free(s);
	}
	s->top = -1;//�ʱⰪ
	s->size = INIT_CAPACITY;//������ (�ִ�)ũ��
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
