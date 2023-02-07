#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100

//********��� ���̽� ��� �Ϸ�*********


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
		//-> count �� 10 ������ ��� ���Ḯ��Ʈ���� ����
		else if (strcmp(p->word, buf) == 0) {
			p->count++;
			//printf("������ �ܾ�, %d��° �ܾ�\n", num + 1);
			//printf("������ �ܾ� count ���� �Ϸ�\n", num + 1);

		}
		//strcmp(p->word, buf) > 0 �� ���,
		else if (strcmp(p->word, buf) > 0) {
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

	//�ߺ� 10 ���� ����
	num = 0;
	Word* cir = head; Word* back = NULL;
	while (cir != NULL) {
		if (cir->count <= 10) {
			//printf("cir->count�� 10 ������ �ܾ�: %s\n", cir->word);
			if (back == NULL) {//ù��° ����� ���
				//printf("������ ��尡 ù��° ���: %s", cir->word);
				;				head = cir->next;
				cir = cir->next;
				continue; //<=---������ ����
			}
			else {
				back->next = cir->next;
				cir = cir->next;
				continue;//<=---������ ����
			}
		}
		back = cir;
		cir = cir->next;
		num++;
	}
	//cir�� ���Ḯ��Ʈ�� ������ �� ���, 
	//cir �� NULL, back�� ����Ʈ�� ������ ���
	back->next = NULL;

	//*********3���κ�*********
	Word* tmp = head; //�о���⸸ ��
	Word* head2 = NULL; num = 0;//�� ���Ḯ��Ʈ ������ ���
	Word* cir2 = head2; Word* back2 = NULL;//�� ���Ḯ��Ʈ ������ ���
	/*struct word {
		int count;
		struct word* next;
		char* word;
	};*/
	while (tmp != NULL) {//2������ ���� ���Ḯ��Ʈ�� ��带 �ϳ��� ������
		if (num != 0) { tmp = tmp->next; }
		if (tmp == NULL) break;
		//���ο� ��� ����
		Word* t = (Word*)malloc(sizeof(Word));
		t->count = tmp->count;
		t->word = tmp->word;

		if (num == 0) {//��尡 �Ѱ��� ���� ��� => �׳� ����
			//printf("����: %s ����Ѱ��� X\n", t->word);
			t->next = NULL;
			head2 = t;
			num++;
			//printf("�Ϸ�: ����Ѱ��� X\n");
			continue;
		}
		else {//����� ��, �󵵰� ũ�� ������ �;���
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
			//cir2�� ����󵵰� �� ū ���ڿ��� �ٷ� �ڿ� ��ġ
			else if (cir2 == NULL) {
				//���� �ڿ� ����(num = 0 �϶��� �̹� ó������)
				//printf("����: %s ������� & NULL & back2 != NULL\n",t->word);
				back2->next = t;
				t->next = NULL;
				num++;
				//printf("�Ϸ�: ������� & NULL & back2 != NULL\n");
				continue;
			}
			//2-1 NULL X, ����󵵰� ���� �����ϰ� ������ �� ���°�� => �׳� ����
			else if (t->count > cir2->count) {
				//printf("����: %s NULL X, ����� ��ȥ��\n", t->word);
				t->next = cir2;
				back2->next = t;
				num++;
				//printf("�Ϸ�: NULL X, ����� ��ȥ��\n");
				continue;
			}
			//2-2. ����� ������ ���ڿ��� �ִ� ��� => ������ ũ�� ��
			else {
				//���� cir2�� NULL�϶� �Ʒ� while���� ���ǹ��� �����Ű�� ���ǹ��� ���߰�
				//�Ʒ��� �������°� �ƴ϶� �׳� ������ ���� ���α׷��� �����
				//cir2�� NULL�϶� cir2 -> count != t->count��� �Ǵ��ϴ°� �ƴ϶� �׳� ��������
				//=> NULL�� ���� ����ó�� �ʼ�
				while (cir2 != NULL && cir2->count == t->count && strcmp(cir2->word, t->word) < 0) {
					back2 = cir2;
					cir2 = cir2->next;
				}
				//����� ������ ���ڿ��� �� ���� �ڿ� ��ġ or �߰��� ���� => ����ó��
				//printf("����: %s ����� ��ȥ�� X\n", t->word);
				t->next = cir2;
				back2->next = t;
				num++;
				//printf("�Ϸ� : ����� ��ȥ�� X\n");
				continue;
			}
		}
	}

	//���Ḯ��Ʈ ���
	Word *pr = head2;
	while (pr != NULL) {
		printf("%s: %d\n", pr->word, pr->count);
		pr = pr->next;
	}
	printf("%d", num);

	return 0;
}