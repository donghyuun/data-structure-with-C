#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX_POLYS 100

Polynomial* create_polynomial_instance(char name);
Term* create_term_instance();

struct term {
	int coef;//계수
	int expo;//차수(지수)
	struct term* next;
};
typedef struct term Term;

typedef struct polynomial {
	char name;//다항식 이름 f,g,...
	Term* first;//첫번째 항의 주소
	int size = 0;//항의 개수
	int expo;//차수(지수)
}Polynomial;

Polynomial* polys[MAX_POLYS];
//polys 는 다항식들에 대한 포인터배열
//배열의 원소가 Polynomial 타입의 값을 가리키는 포인터
int n = 0;//저장된 다항식의 개수

Term* create_term_instance() {
	//Term 타입의 구조체를 동적할당하고 포인터가 가리키게 함
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;// 포인터의 값 반환(= 만든 구조체의 주소)
 }

Polynomial* create_polynomial_instance(char name) {
	//Polynomial 구조체를 동적할당하고 포인터가 가리키게 함
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;// 포인터의 값 반환(= 만든 구조체의 주소)
}

void add_term(int c, int e, Polynomial* poly) {
	if (c == 0)return;

	Term* p = poly->first, * q = NULL;
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}
	if (p != NULL && p->expo == e) {//동일한 차수의 항 존재
		p->coef += c;//계수를 더해준다
		if (p->coef == 0) {//더했더니 계수가 0이 되는 경우
			if (q == NULL)//해당 항이 첫번째 노드인 경우
				poly->first = p->next;//첫번째 노드 삭제
			else
				q->next = p->next;
		}
		poly->size--;
		free(p);//불필요해진 노드 free시킴 
	}

	//동일한 차수의 항 존재 X
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	if (q == NULL) {//최고차항인 경우
		term->next = poly->first;
		poly->first=term->next;
	}
	else {
		term->next = p;
		q->next = term;
	}
	poly->size++;
	
	return;
}

int eval(Polynomial* poly, int x) {//다항식의 값을 계산하는 함수
	int result = 0;
	Term* t = poly->first;
	while (t != NULL) {
		result += evalll(t, x);
		t = t->next;
	}
	return result;
}

int evalll(Term* term, int x) {
	int result = term->coef;//c
	for (int i = 0; i < term->expo; i++) {//term->expo = e
		result *= x;
	}
	return result;
}

void  print_poly(Polynomial* p) {
	printf("%c = ", p->name);
	Term* t = p->first;
	while (t != NULL) {
		print_term(t);
		printf("+");
		t = t->next;
	}
}
void print_term(Term* pTerm) {
	printf("%dx^%d", pTerm->coef, pTerm->expo);
	//..나머지는 과제
}