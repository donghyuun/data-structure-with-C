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

Queue create() {
	Queue q = (Queue)malloc(sizeof(struct queue_type));
	q->front = NULL;
	q->rear = NULL;
	q->size = NULL;
	return q;
}

void enqueue(Queue q, Position cur, int dir) {
	//한번에 여러개의 노드 저장해야 하므로 dir로 구분지어줘야 한다.
	Link newNode = (Link)malloc(sizeof(Node));
	if (dir == -1) { newNode->x = cur.x; newNode->y = cur.y; }//첫 시작은 큐에 그냥 삽입
	//해당 방향의 위치로 변경해서 삽입
	else if (dir == 0) { newNode->x = cur.x - 1; newNode->y = cur.y; }//북
	else if (dir == 1) { newNode->x = cur.x - 1; newNode->y = cur.y + 1; }//동북
	else if (dir == 2) { newNode->x = cur.x; newNode->y = cur.y + 1; }//동
	else if (dir == 3) { newNode->x = cur.x + 1; newNode->y = cur.y + 1; }//남동
	else if (dir == 4) { newNode->x = cur.x + 1; newNode->y = cur.y; }//남
	else if (dir == 5) { newNode->x = cur.x + 1; newNode->y = cur.y - 1; }//남서
	else if (dir == 6) { newNode->x = cur.x; newNode->y = cur.y - 1; }//서
	else if (dir == 7) { newNode->x = cur.x - 1; newNode->y = cur.y - 1; }//북서

	newNode->next = NULL;

	if (q->front == NULL) {//큐가 비어있을때
		q->front = newNode;
		q->rear = newNode;
	}
	else {//비어있지 않다면 제일 뒤에 삽입
		q->rear->next = newNode;
		q->rear = newNode;
	}
	//printf("노드 enqueue: (%d, %d)\n", newNode->x, newNode->y);
}

Link dequeue(Queue q) {
	Link oldNode = q->front;
	q->front = oldNode->next;
	//printf("노드 dequeue: (%d, %d)\n", oldNode->x, oldNode->y);
	return oldNode;
}
bool is_empty(Queue q) {
	if (q->front == NULL) return true;
	return false;
}
