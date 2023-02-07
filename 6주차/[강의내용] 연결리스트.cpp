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
	int coef;//���
	int expo;//����(����)
	struct term* next;
};
typedef struct term Term;

typedef struct polynomial {
	char name;//���׽� �̸� f,g,...
	Term* first;//ù��° ���� �ּ�
	int size = 0;//���� ����
	int expo;//����(����)
}Polynomial;

Polynomial* polys[MAX_POLYS];
//polys �� ���׽ĵ鿡 ���� �����͹迭
//�迭�� ���Ұ� Polynomial Ÿ���� ���� ����Ű�� ������
int n = 0;//����� ���׽��� ����

Term* create_term_instance() {
	//Term Ÿ���� ����ü�� �����Ҵ��ϰ� �����Ͱ� ����Ű�� ��
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	return t;// �������� �� ��ȯ(= ���� ����ü�� �ּ�)
 }

Polynomial* create_polynomial_instance(char name) {
	//Polynomial ����ü�� �����Ҵ��ϰ� �����Ͱ� ����Ű�� ��
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;// �������� �� ��ȯ(= ���� ����ü�� �ּ�)
}

void add_term(int c, int e, Polynomial* poly) {
	if (c == 0)return;

	Term* p = poly->first, * q = NULL;
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}
	if (p != NULL && p->expo == e) {//������ ������ �� ����
		p->coef += c;//����� �����ش�
		if (p->coef == 0) {//���ߴ��� ����� 0�� �Ǵ� ���
			if (q == NULL)//�ش� ���� ù��° ����� ���
				poly->first = p->next;//ù��° ��� ����
			else
				q->next = p->next;
		}
		poly->size--;
		free(p);//���ʿ����� ��� free��Ŵ 
	}

	//������ ������ �� ���� X
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	if (q == NULL) {//�ְ������� ���
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

int eval(Polynomial* poly, int x) {//���׽��� ���� ����ϴ� �Լ�
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
	//..�������� ����
}