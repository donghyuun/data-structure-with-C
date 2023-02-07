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

//구조체 변수로 배열 포인터르 가지는 구조체 선언(이걸 가리키는게 Stack 임)
struct queue_type {
	Node* front; //연결리스트, Position 형 포인터
	Node* rear;
	int size;
};

typedef struct queue_type* Queue;
Queue create();
void enqueue(Queue q, Position cur, int dir);
Link dequeue(Queue q);
bool is_empty(Queue q);
Position move_to(Position pos, int dir);

