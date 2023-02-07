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

	//아까우니까 q재사용, 의미없음
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node* p = head;
	//연결 리스트 출력할때
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}

/*
맨앞에 새로운 노드 삽입

	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuesday";
	head->next = NULL;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;

	//아까우니까 q재사용, 의미없음
	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node* p = head;
	//연결 리스트 출력할때
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
*/