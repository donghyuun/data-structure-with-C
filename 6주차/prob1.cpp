#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100

//********��� ���̽� ��� �Ϸ�**********
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
		//printf("�ܾ� �о�� %s\n", buf);
		Word* p = head; Word* q = NULL;
		while (p != NULL && strcmp(p->word, buf) < 0) {
			//p->word�� buf���� ���������� ���� ���
			q = p;
			p = p->next;
		}
		//p�� NULL �̰ų� p->word�� ���������� buf���� ���ų� ū ���
		Word* t = (Word*)malloc(sizeof(Word));

		if (p == NULL) {
			if (q == NULL) {//��尡 �Ѱ��� ����X
				//printf("���� �տ� ����, %d��° �ܾ�\n", num+1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = NULL;

				head = t;
				num++;
				//printf("���� �տ� ���� �Ϸ�\n");
			}
			else {//buf �� ���������� ���� �� ����
				//printf("���� �ڿ� ����, %d��° �ܾ�\n", num + 1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = NULL;
;				
				q->next = t;
				num++;
				//printf("���� �ڿ� ���� �Ϸ�\n");
				//printf("q�� word: %s\n", q->word);
			}
		}
		//������ �ܾ ������ ���
		else if (strcmp(p->word, buf) == 0) {
			p->count++;
			//printf("������ �ܾ�, %d��° �ܾ�\n", num + 1);
			//printf("������ �ܾ� count ���� �Ϸ�\n", num + 1);
			
		}
		//strcmp(p->word, buf) > 0 �� ���,
		else if(strcmp(p->word,buf)>0){
			if (q == NULL) {//��尡 �̹������ϸ鼭 ���� �պκп� ����
				//printf("��� �̹� ���� & ���� �տ� ����, %d��° �ܾ�\n", num + 1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = head;
				head = t;
				num++;
			}
			else {//��尡 �̹� �����ϸ鼭 �߰��� ����
				//printf("�߰�����, %d��° �ܾ�\n", num + 1);
				t->count = 1;
				t->word = strdup(buf);
				t->next = q->next;
				q->next = t;
				num++;
			}
			//printf("�߰����� �Ϸ�\n");
		}
	}

	//���Ḯ��Ʈ ���
	Word *pr = head;
	while (pr != NULL) {
		printf("%s: %d\n", pr->word, pr->count);
		pr = pr->next;
	}
	printf("%d", num);

	return 0;
}