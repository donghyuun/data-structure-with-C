#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100

 
struct node {
	char* data;

	struct node* next;
};

typedef struct node Node;
Node* head = NULL;

int main() {
	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;
	
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;

	//�Ʊ��ϱ� q����, �ǹ̾���
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node* p = head;
	//���� ����Ʈ ����Ҷ�
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}

/*
�Ǿտ� ���ο� ��� ����

	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;

	//�Ʊ��ϱ� q����, �ǹ̾���
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node* p = head;
	//���� ����Ʈ ����Ҷ�
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
*/