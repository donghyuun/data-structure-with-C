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

Queue create() {
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	q->front = NULL;
	q->rear = NULL;
	q->size = NULL;
	return q;
}

void enqueue(Queue q, Position cur, int dir) {
	//�ѹ��� �������� ��� �����ؾ� �ϹǷ� dir�� ����������� �Ѵ�.
	Link newNode = (Link)malloc(sizeof(Node));
	if (dir == -1) { newNode->x = cur.x; newNode->y = cur.y; }//ù ������ ť�� �׳� ����
	//�ش� ������ ��ġ�� �����ؼ� ����
	else if (dir == 0) { newNode->x = cur.x - 1; newNode->y = cur.y; }//��
	else if (dir == 1) { newNode->x = cur.x - 1; newNode->y = cur.y + 1; }//����
	else if (dir == 2) { newNode->x = cur.x; newNode->y = cur.y + 1; }//��
	else if (dir == 3) { newNode->x = cur.x + 1; newNode->y = cur.y + 1; }//����
	else if (dir == 4) { newNode->x = cur.x + 1; newNode->y = cur.y; }//��
	else if (dir == 5) { newNode->x = cur.x + 1; newNode->y = cur.y - 1; }//����
	else if (dir == 6) { newNode->x = cur.x; newNode->y = cur.y - 1; }//��
	else if (dir == 7) { newNode->x = cur.x - 1; newNode->y = cur.y - 1; }//�ϼ�

	newNode->next = NULL;

	if (q->front == NULL) {//ť�� ���������
		q->front = newNode;
		q->rear = newNode;
	}
	else {//������� �ʴٸ� ���� �ڿ� ����
		q->rear->next = newNode;
		q->rear = newNode;
	}
	//printf("��� enqueue: (%d, %d)\n", newNode->x, newNode->y);
}

Link dequeue(Queue q) {
	Link oldNode = q->front;
	q->front = oldNode->next;
	//printf("��� dequeue: (%d, %d)\n", oldNode->x, oldNode->y);
	return oldNode;
}
bool is_empty(Queue q) {
	if (q->front == NULL) return true;
	return false;
}
