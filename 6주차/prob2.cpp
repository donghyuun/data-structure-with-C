#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100

//********모든 케이스 통과 완료*********
char buf[100];
int main() {
	FILE* fp = fopen("harry.txt", "r");
	int num = 0;

	struct word {
		int count;
		struct word* next;
		char* word;
	};
	typedef struct word Word;
	Word* head = NULL;

	while (fscanf(fp, "%s", buf) != EOF) {
		//printf("단어 읽어옴 %s\n", buf);
		Word* p = head; Word* q = NULL;
		while (p != NULL && strcmp(p->word, buf) < 0) {
			//p->word가 buf보다 사전식으로 작은 경우
			q = p;
			p = p->next;
		}
		//p가 NULL 이거나 p->word가 사전식으로 buf보다 같거나 큰 경우
		Word* t = (Word*)malloc(sizeof(Word));

		if (p == NULL) {
			if (q == NULL) {//노드가 한개도 존재X
				//printf("제일 앞에 삽입, %d번째 단어\n", num+1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = NULL;

				head = t;
				num++;
				//printf("제일 앞에 삽입 완료\n");
			}
			else {//buf 가 사전식으로 제일 뒤 삽입
				//printf("제일 뒤에 삽입, %d번째 단어\n", num + 1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = NULL;
;				
				q->next = t;
				num++;
				//printf("제일 뒤에 삽입 완료\n");
				//printf("q의 word: %s\n", q->word);
			}
		}
		//동일한 단어가 존재할 경우 
		//-> count 가 10 이하일 경우 연결리스트에서 제거
		else if (strcmp(p->word, buf) == 0) {
			p->count++;
			//printf("동일한 단어, %d번째 단어\n", num + 1);
			//printf("동일한 단어 count 증가 완료\n", num + 1);
			
		}
		//strcmp(p->word, buf) > 0 인 경우,
		else if(strcmp(p->word,buf)>0){
			if (q == NULL) {//노드가 이미존재하면서 제일 앞부분에 삽입
				//printf("노드 이미 존재 & 제일 앞에 삽입, %d번째 단어\n", num + 1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = head;
				head = t;
				num++;
			}
			else {//노드가 이미 존재하면서 중간에 삽입
				//printf("중간삽입, %d번째 단어\n", num + 1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = q->next;
				q->next = t;
				num++;
			}
			//printf("중간삽입 완료\n");
		}
	}

	//중복 10 이하 제거
	num = 0;
	Word* cir = head; Word* back = NULL;
	while (cir != NULL) {
		if (cir->count <= 10) {
			//printf("cir->count가 10 이하인 단어: %s\n", cir->word);
			if (back == NULL) {//첫번째 노드인 경우
				//printf("삭제할 노드가 첫번째 노드: %s", cir->word);
;				head = cir->next;
				cir = cir->next;
				continue; //<=---빼먹지 말자
			}
			else {
				back->next = cir->next;
				cir = cir->next;
				continue;//<=---빼먹지 말자
			}
		}
		back = cir;
		cir = cir->next;
		num++;
	}
	//cir이 연결리스트의 끝까지 간 경우, 
	//cir 은 NULL, back은 리스트의 마지막 노드
	back->next = NULL;

	//연결리스트 출력
	Word *pr = head;
	while (pr != NULL) {
		printf("%s: %d\n", pr->word, pr->count);
		pr = pr->next;
	}
	printf("%d", num);

	return 0;
}