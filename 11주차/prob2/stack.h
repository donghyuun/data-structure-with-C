#include <stdbool.h> 

typedef int Item;

typedef struct pos {
	int x, y;
} Position;

typedef struct node {
	int x, y;
	struct node* next;
} Node;
typedef Node* Link;

//����ü ������ �迭 �����͸� ������ ����ü ����(�̰� ����Ű�°� Stack ��)
struct queue_type {
	Node* front; //���Ḯ��Ʈ, Position �� ������
	Node* rear;
	int size;
};

typedef struct queue_type* Queue;
Queue create();
void enqueue(Queue q, Position cur, int dir);
Link dequeue(Queue q);
bool is_empty(Queue q);
Position move_to(Position pos, int dir);

