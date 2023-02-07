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
		else if (strcmp(p->word, buf) > 0) {
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

	//*********3번부분*********
	Word* tmp = head; //읽어오기만 함
	Word* head2 = NULL; num = 0;//새 연결리스트 생성에 사용
	Word* cir2 = head2; Word* back2 = NULL;//새 연결리스트 생성에 사용
	/*struct word {
		int count;
		struct word* next;
		char* word;
	};*/
	while (tmp != NULL) {//2번에서 만든 연결리스트의 노드를 하나씩 가져옴
		if (num != 0) { tmp = tmp->next; }
		if (tmp == NULL) break;
		//새로운 노드 생성
		Word* t = (Word*)malloc(sizeof(Word));
		t->count = tmp->count;
		t->word = tmp->word;

		if (num == 0) {//노드가 한개도 없을 경우 => 그냥 삽입
			//printf("시작: %s 노드한개도 X\n", t->word);
			t->next = NULL;
			head2 = t;
			num++;
			//printf("완료: 노드한개도 X\n");
			continue;
		}
		else {//등장빈도 비교, 빈도가 크면 앞으로 와야함
			cir2 = head2; back2 = NULL;
			while (cir2 != NULL && cir2->count > t->count) {
				//printf("(%d %d) ", cir2->count, t->count);
				back2 = cir2;
				cir2 = cir2->next;
			}
			if (back2 == NULL) {
				t->next = cir2;
				head2 = t;
				num++;
				continue;
			}
			//cir2가 등장빈도가 더 큰 문자열의 바로 뒤에 위치
			else if (cir2 == NULL) {
				//제일 뒤에 삽입(num = 0 일때는 이미 처리했음)
				//printf("시작: %s 노드존재 & NULL & back2 != NULL\n",t->word);
				back2->next = t;
				t->next = NULL;
				num++;
				//printf("완료: 노드존재 & NULL & back2 != NULL\n");
				continue;
			}
			//2-1 NULL X, 등장빈도가 나를 제외하고 동일한 게 없는경우 => 그냥 삽입
			else if (t->count > cir2->count) {
				//printf("시작: %s NULL X, 등장빈도 나혼자\n", t->word);
				t->next = cir2;
				back2->next = t;
				num++;
				//printf("완료: NULL X, 등장빈도 나혼자\n");
				continue;
			}
			//2-2. 등장빈도 동일한 문자열이 있는 경우 => 사전식 크기 비교
			else {
				//만약 cir2가 NULL일때 아래 while문의 조건문을 실행시키면 조건문이 멈추고
				//아래로 내려오는게 아니라 그냥 에러가 나서 프로그램이 멈춘다
				//cir2가 NULL일때 cir2 -> count != t->count라고 판단하는게 아니라 그냥 에러가남
				//=> NULL에 대한 예외처리 필수
				while (cir2 != NULL && cir2->count == t->count && strcmp(cir2->word, t->word) < 0) {
					back2 = cir2;
					cir2 = cir2->next;
				}
				//등장빈도 동일한 문자열들 중 제일 뒤에 위치 or 중간에 삽입 => 동일처리
				//printf("시작: %s 등장빈도 나혼자 X\n", t->word);
				t->next = cir2;
				back2->next = t;
				num++;
				//printf("완료 : 등장빈도 나혼자 X\n");
				continue;
			}
		}
	}

	//연결리스트 출력
	Word *pr = head2;
	while (pr != NULL) {
		printf("%s: %d\n", pr->word, pr->count);
		pr = pr->next;
	}
	printf("%d", num);

	return 0;
}