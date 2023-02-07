#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int num;
	int h;
	struct node* next;
};
typedef node Node;
typedef Node* Link;
/***********모든 테스트 케이스 통과*********/
int main(void) {
	double start, end;
	start = (double)clock() / CLOCKS_PER_SEC;

	FILE* fp = fopen("input.txt", "r");
	int totalCase = 0;
	unsigned long long sum = 0, num = 0;
	fscanf(fp, "%d ", &totalCase);
	for (int i = 0; i < totalCase; i++) {
		Link head = NULL;
		sum = 0;

		fscanf(fp, "%d", &num);
		//printf("num: %d\n",num);

		for (int j = 0; j < num; j++) {
			int val = 0;
			fscanf(fp, "%d", &val);
			//노드 생성 및 기본 설정
			Link newNode = (Link)malloc(sizeof(Node));
			newNode->h = 0;
			newNode->num = val;
			newNode->next = NULL;

			//1. 노드가 한개도 없을때 => 그냥 노드 삽입
			if (head == NULL) {
				head = newNode;
			}
			//2. 노드가 한개 이상 존재할때
			else {
				//2-1 head가 가리키는 노드의 num이 나보다 작을때
				//head 가 가리키는 노드의  h값 + 1을 삽입할 노드의 h에 더한다
				//더해주고 해당 기존 노드 삭제(free)
				while (head != NULL && head->num <= val) {
					Link oldNode = head;
					newNode->h = (newNode->h) + (oldNode->h) + 1 ;
					head = head->next;
					free(oldNode);
				}
				
				newNode -> next = head;
				head = newNode;
				
			}
			sum += newNode->h;
		}
		printf("%d\n", sum%1000000);
	}
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("Elapsed Time :%.3lf\n", (end - start));
}
