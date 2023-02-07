#include <stdbool.h> 

//스택에 넣을 구조체 정의
typedef int Item;

typedef struct pos {
	int x, y;
} Position;

//구조체 변수로 배열 포인터르 가지는 구조체 선언(이걸 가리키는게 Stack 임)
struct stack_type {
	Position* contents; //배열, (Item = int 타입)
	int top;
	int size;
};

typedef struct stack_type* Stack;
Stack create();
void push(Stack s, Position cur);
Position pop(Stack s);
bool is_empty(Stack s);
Position move_to(Position pos, int dir);

