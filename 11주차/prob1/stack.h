#include <stdbool.h> 

//���ÿ� ���� ����ü ����
typedef int Item;

typedef struct pos {
	int x, y;
} Position;

//����ü ������ �迭 �����͸� ������ ����ü ����(�̰� ����Ű�°� Stack ��)
struct stack_type {
	Position* contents; //�迭, (Item = int Ÿ��)
	int top;
	int size;
};

typedef struct stack_type* Stack;
Stack create();
void push(Stack s, Position cur);
Position pop(Stack s);
bool is_empty(Stack s);
Position move_to(Position pos, int dir);

