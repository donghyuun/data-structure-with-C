#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>// atoi, isspace ...
#define MAX 1000

//5���� 3�� �Լ� ����
//int data[20][20];
//bool check(int x, int y, int num) {
//	//check four directions, sw, s, se,e
//	int mystone = data[x][y];
//	//������
//	//data[x+1][y-1] data[x+2][y-2] data[x+3][y-3] data[x+4][y-4] 
//	int d = 1;
//	while (d < 5 && x + d < num && y - d >= 0) {
//		if (data[x + d][y - d] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//
//	//����
//	d = 1;
//	while (d < 5 && x + d < num ) {
//		if (data[x + d][y] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//	//������
//	d = 1;
//	while (d < 5 && x + d < num && y + d >= 0) {
//		if (data[x + d][y + d] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//	//����
//	d = 1;
//	while (d < 5 && y + d >= 0) {
//		if (data[x][y + d] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//	
//
//	return false;
//}
//4���� 3�� �Լ� ����
//void compress(char *str) {
//	/*���������� ����ؼ� �� �迭�� ����� �� �迭�� ������ �� ����
//	char tmp[1000];
//	return tmp;*/
//	int i = 0; int j = 0;
//	while (str[i] != '\0') {//NULL('\0') ���� ������ ����
//		//���� ���� ���ڰ� �����϶�
//		if (i == 0 && str[i] == ' ') {
//			i++;
//			//printf("A");
//			continue;
//		} 
//		//���� �����̸鼭 �ڽŵ� �����϶�
//		else if (str[i - 1] == ' ' && str[i] == ' ') {
//			//�ڱ� ���� ���� ������ ������<--XXXXX!!!!
//			//�׳� ������ ���ϸ� ��
//			i++;
//			//printf("B");
//			continue;
//		}
//		str[j] = str[i++];
//		j++;
//		//printf("C");
//	}
//	//i �� ���� �ι����� ��ġ�� ����
//	if (j > 0 && str[i - 1] == ' ') {
//		str[j-1] = '\0';
//	}
//	else {
//		str[j] = '\0';
//	}
//}

int main(void) {
	
	//************6���� 2��************
	//char word[100];
	//int n = 0;
	//FILE* fp = fopen("harry.txt", "r");

	//struct term {
	//	int count;
	//	struct term* next;
	//	char* words;
	//};
	//typedef struct term Term;
	//Term* head = NULL;
	//Term* front = head; Term* back = NULL;
	//while (fscanf(fp, "%s", word) != EOF) {
	//	front = head; back = NULL;
	//	Term* t = (Term*)malloc(sizeof(Term));
	//	while (front != NULL && strcmp(front->words, word) < 0) {
	//		back = front;
	//		front = front->next;
	//	}
	//	//front = NULL �̰ų� ���������� ���ų� ���� ����
	//	if (front == NULL) {
	//		if (back == NULL) {//��� �Ѱ��� ����
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			head = t;
	//			n++;
	//		}
	//		else {
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//	//front != NULL�� ����, ���� ����Ű�� ����
	//	//���� �����϶�
	//	else if (strcmp(front->words, word) == 0) {
	//		front->count++;
	//	}
	//	//���������� ���� �� ���� ���
	//	else if (strcmp(front->words, word) > 0) {
	//		//���� �տ� ���Ե� ���
	//		if (back == NULL) {
	//			t->next = head;
	//			t->words = strdup(word);
	//			t->count = 1;
	//			head = t;
	//			n++;
	//		}
	//		//�߰��� ���Ե� ���
	//		else {
	//			t->next = front;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//}

	//front = head; back = NULL; n = 0;
	//while (front != NULL) {
	//	if (front->count <= 10) {
	//		if (back == NULL) {
	//			front = front->next;
	//		}
	//		else {
	//			back->next = front->next;
	//			front = front->next;
	//		}
	//	}
	//	else {
	//		back = front;
	//		front = front->next;
	//		n++;
	//	}
	//}

	//Term* p = head;
	//while (p != NULL) {
	//	printf("%s: %d\n", p->words, p->count);
	//	p = p->next;
	//}
	//printf("%d", n);



	//************6���� 1��************
	//char word[100];
	//int n = 0;
	//FILE* fp = fopen("harry.txt", "r");

	//struct term {
	//	int count;
	//	struct term* next;
	//	char* words;
	//};
	//typedef struct term Term;
	//Term* head = NULL;
	//Term* front = head; Term* back = NULL;
	//while (fscanf(fp, "%s", word) != EOF) {
	//	front = head; back = NULL;
	//	Term* t = (Term*)malloc(sizeof(Term));
	//	while (front != NULL && strcmp(front->words, word) < 0) {
	//		back = front;
	//		front = front->next;
	//	}
	//	//front = NULL �̰ų� ���������� ���ų� ���� ����
	//	if (front == NULL) {
	//		if (back == NULL) {//��� �Ѱ��� ����
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			head = t;
	//			n++;
	//		}
	//		else {
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//	//front != NULL�� ����, ���� ����Ű�� ����
	//	//���� �����϶�
	//	else if (strcmp(front->words, word) == 0) {
	//		front->count++;
	//	}
	//	//���������� ���� �� ���� ���
	//	else if (strcmp(front->words, word) > 0) {
	//		//���� �տ� ���Ե� ���
	//		if (back == NULL) {
	//			t->next = head;
	//			t->words = strdup(word);
	//			t->count = 1;
	//			head = t;
	//			n++;
	//		}
	//		//�߰��� ���Ե� ���
	//		else {
	//			t->next = front;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//}
	//Term* p = head;
	//while (p != NULL) {
	//	printf("%s: %d\n", p->words, p->count);
	//	p = p->next;
	//}
	//printf("%d", n);

//***********5���� 3��*********
	//FILE* fp = fopen("board.txt", "r");
	//int num = 0;
	//fscanf(fp, "%d ", &num);
	//printf("%d\n", num);

	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		fscanf(fp, "%d ", &data[i][j]);
	//	}
	//}
	//
	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		if (data[i][j] == 0)
	//			continue;
	//		//check if board[i][j] is an end of 5-consecutive smae stone
	//		if (check(i, j, num)) {//������ �����ȴٸ�
	//			if (data[i][j] == 1) {
	//				printf("black");
	//			}
	//			else {
	//				printf("white");
	//			}
	//			return 0;
	//		}
	//	}
	//}
	//printf("not finished");
	//return 0;

;

//***********5���� 2��*********
	/*int num = 0;
	int data[200][200];
	FILE* fp = fopen("data.mat", "r");
	fscanf(fp, "%d ", &num);
	printf("%d\n", num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			fscanf(fp, "%d", &data[i][j]);
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	
	while (1) {
		char command[100];
		int ch = 0, j = 0;
		printf("$ ");
		while ((ch = getchar()) != '\n') {
			command[j++] = ch;
		}
		command[j] = '\0';

		if (strcmp(command, "show") == 0) {
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num; j++) {
					printf("%d ", data[i][j]);
				}
				printf("\n");
			}
		}
		else if (strcmp(command, "exit") == 0) {
			return 0;
		}
		else if (strcmp(strtok(command, " "), "slice") == 0) {
			int x = atoi(strtok(NULL, " "));
			int p = atoi(strtok(NULL, " "));
			int y = atoi(strtok(NULL, " "));
			int q = atoi(strtok(NULL, " "));

			for (int i = x; i < num; i += p) {
				for (int j = y; j < num; j += q) {
					printf("%d ", data[i][j]);
				}
				printf("\n");
			}
		}
	}*/

//***********5���� 1��*********
	//char str[300];
	//int count = 0;
	//int maxCount = 0, index = 0, maxIndex = 0;
	//scanf("%s", str);
	// /*���� ���� a i u e o*/
	////1. ������ ���� & count = 0 �̸� �׶����� count++ & �ε��� ����
	////2. ������ ���� & coutn > 0 �ΰ�� �׳� count++
	////3. ������ �ƴϸ鼭 count  >0 �ΰ�� maxCount �� ���Ͽ� 
	////��ũ�� maxCount�� count���� maxIndex�� �����ߴ� �ε����� ����
	//for (int i = 0; i < strlen(str); i++) {
	//	//������ �ƴѰ��(�����ΰ��)
	//	if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
	//		if (count == 0) {//���� ó�� ����
	//			index = i; count++;
	//		}
	//		//������ �����ؼ� �����ϰ� �ִ� ���
	//		else {
	//			count++;
	//		}
	//	}
	//	//������ ���-> count �� ������ �Ѵ�
	//	else {
	//		//������ �����ؿ��� �ִ� ���
	//		if (count > 0) {// maxCount�� ��
	//			if (count > maxCount) {
	//				maxCount = count;
	//				maxIndex = index;
	//				count = 0;
	//				//index = 0;
	//			}
	//			else {
	//				count = 0;
	//				//index = 0;
	//			}
	//		}
	//		//�������� �����̾��� ���
	//		else {
	//			//count = 0;//��ǻ� �ʿ�X
	//			//index = 0;//��ǻ� �ʿ�X
	//		}
	//	}
	//}
	//for (int i = maxIndex; i < maxIndex + maxCount; i++) {
	//	printf("%c", str[i]);
	//}

	//************4���� 3��************
	//main �Լ����� �Լ����� ����Ǿ� ����
	//FILE* fp = fopen("table.txt", "r");
	//char* str[20][20];
	//char line[1000];
	//int maxCol[20];
	//char* temp;
	//int i = 0;
	//int m = 0, n = 0; int max = 1000;
	//fscanf(fp, "%d %d ", &m, &n);
	//
	//for (int i = 0; i < m; i++) {
	//	fgets(line, max, fp);
	//	if (line[strlen(line) - 1] == '\n') {
	//		line[strlen(line) - 1] = '\0';
	//	}
	//	char* p = strtok(line, "&");
	//	str[i][0] = strdup(p);
	//	compress(str[i][0]);
	//	if (i == 0) { maxCol[0] = strlen(str[i][0]); }
	//	else if (strlen(str[i][0]) > maxCol[0]) {
	//		maxCol[0] = strlen(str[i][0]);
	//	}

	//	/*printf("%s ", str[i][0]);*/

	//	for (int j = 1; j < n; j++) {
	//		p = strtok(NULL, "&");
	//		str[i][j] = strdup(p);
	//		compress(str[i][j]);
	//		if (i == 0) { maxCol[j] = strlen(str[i][j]); }
	//		else if (strlen(str[i][j]) > maxCol[j]) {
	//			maxCol[j] = strlen(str[i][j]);
	//		}
	//	}
	//}
	//for (int i = 0; i < n; i++) {
	//	printf("%d ���� �ִ�: %d\n", i, maxCol[i]);
	//}
	//FILE* fp2 = fopen("output.txt", "w");

	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		fputs(str[i][j], fp2);
	//		for (int k = 0; k < (maxCol[j] - strlen(str[i][j])); k++) {
	//			fputs(" ", fp2);
	//		}
	//		fputs(" ", fp2);
	//	}
	//	fputs("\n", fp2);
	//}

	////************4���� 2��************
	//int num = 0;
	//FILE* fp = fopen("input.txt", "r");
	//fscanf(fp, "%d ", &num);
	//int data[20][20] = { 0 };
	//float avgRow[20]; float sdRow[20];
	//float avgCol[20]; float sdCol[20];

	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		fscanf(fp, "%d", &data[i][j]);
	//		printf("%d ", data[i][j]);
	//	}
	//	printf("\n");
	//}

	//for (int i = 0; i < num; i++) {
	//	float sumRow = 0; float sumCol = 0;
	//	for (int j = 0; j < num; j++) {
	//		sumRow += data[i][j];
	//		sumCol += data[j][i];
	//	}
	//	avgRow[i] = sumRow / num;
	//	avgCol[i] = sumCol / num;
	//	
	//	printf("%d ���� ���: %.2lf, %d ���� ���: %.2lf\n", i, avgRow[i], i, avgCol[i]);
	//}

	//for (int i = 0; i < num; i++) {
	//	float sdSumRow = 0; float sdSumCol = 0;
	//	for (int j = 0; j < num; j++) {
	//		sdSumRow += (avgRow[i] - data[i][j])* (avgRow[i] - data[i][j]);
	//		sdSumCol += (avgCol[i] - data[j][i])*(avgCol[i] - data[j][i]);
	//	}
	//	sdRow[i] = sqrt(sdSumRow / num);
	//	sdCol[i] = sqrt(sdSumCol / num);

	//	printf("%d ���� ǥ������: %.2lf, %d ���� ǥ������: %.2lf\n", i, sdRow[i], i, sdCol[i]);
	//}
	//

	////************4���� 1��************
	//int num = 0;
	//scanf("%d", &num);
	//int data[100];
	////�Է� �޾� �迭�� ����
	//for (int i = 0; i < num; i++) {
	//	scanf("%d", &data[i]);
	//}

	////����
	//int count = 0;
	//for (int i = 0; i < num; i++) {
	//	for (int j = i; j < num; j++) {
	//		if (data[i] > data[j]) count++;
	//	}
	//}
	//printf("%d", count);

	//return 0;


	////************3���� 3��************
	//char* words[10000];
	//char* strs[10000];
	//int n = 0;
	//FILE* fp = fopen("shuffled_dict.txt", "r");
	//if (fp == NULL) {
	//	printf("open failed\n"); return 0;
	//}
	//int count = 0;
	//char line[500];
	//while ((fgets(line, MAX, fp) != NULL)) {
	//	if (line[strlen(line) - 1] == '\n') {
	//		line[strlen(line) - 1] = '\0';
	//	}
	//	if (strlen(line) <= 0) continue;//����ó��
	//	
	//	words[n] = strdup(strtok(line, "\t"));
	//	strs[n] = strdup(strtok(NULL, "\t"));
	//	//printf("%s %s\n", words[n ], strs[n]);
	//	n++;
	//}

	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = 0; j < n - 1 - i; j++) {
	//		if (strcmp(words[j], words[j + 1]) > 0) {
	//			char* temp;
	//			temp = words[j];
	//			words[j] = words[j+1];
	//			words[j + 1] = temp;

	//			temp = strs[j];
	//			strs[j] = strs[j + 1];
	//			strs[j + 1] = temp;
	//		}
	//	}
	//}
	//FILE* fp2 = fopen("sorted_dict.txt", "w");
	//for (int i = 0; i < n; i++) {
	//	fputs(words[i], fp2);
	//	fputs("\t", fp2);
	//	fputs(strs[i], fp2);
	//	fputs("\n", fp2);
	//}
	//return 0;

	////************3���� 2��************
	//int num = 0;
	//scanf("%d", &num);
	//int n = 0;
	//int ftemp = 0;
	//int btemp = 0;
	//int front[100];
	//int back[100];
	//for (int i = 0; i < num; i++) {
	//	scanf("%d %d", &front[i], &back[i]);
	//}

	////��������
	//for (int i = 0; i < num - 1; i++) {
	//	for (int j = 0; j < num - 1 - i; j++) {
	//		if (front[j] > front[j + 1]) {
	//			int temp = 0;
	//			temp = front[j];
	//			front[j] = front[j + 1];
	//			front[j + 1] = temp;

	//			temp = back[j];
	//			back[j] = back[j + 1];
	//			back[j + 1] = temp;
	//		}
	//		else if (front[j] == front[j + 1]) {
	//			if (back[j] > back[j + 1]) {
	//				int temp = 0;
	//				temp = front[j];
	//				front[j] = front[j + 1];
	//				front[j + 1] = temp;

	//				temp = back[j];
	//				back[j] = back[j + 1];
	//				back[j + 1] = temp;
	//			}
	//		}
	//	}
	//}

	//for (int i = 0; i < num; i++) {
	//	printf("%d %d\n", front[i], back[i]);
	//}



	////************3���� 1��************
	//int num = 0;
	//int data[100];
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	scanf("%d", &data[i]);
	//}

	//int max = 0, maxIndex = 0;
	//for (int i = num - 1; i > 0; i--) {
	//	max = 0; maxIndex = 0;//�ٽ� �ʱ�ȭ ����� �Ѵ�
	//	for (int j = 0; j <= i; j++) {
	//		if (data[j] > max) { 
	//			max = data[j];
	//			maxIndex = j;
	//		}
	//	}
	//	int temp = data[i];
	//	//printf("data[%d]: %d\n", i, data[i]);
	//	data[i] = max;
	//	//printf("%d", data[i]);
	//	data[maxIndex] = temp;
	//}

	//for (int i = 0; i < num; i++) {
	//	printf("%d ", data[i]);
	//}


	////************2���� 3��************
//char* str[10000];
//int count[10000] = { 0 };
//int n = 0;
//char word[100];
//FILE* fp = fopen("harry.txt", "r");
//while (fscanf(fp, "%s ", word) != EOF) {
//	//�ߺ� Ȯ��
//	bool duplicate = false;
//	for (int i = 0; i < n; i++) {
//		if (strcmp(str[i], word) == 0) {
//			duplicate = true;
//			count[i]++;
//			break;
//		}
//	}
//	if (duplicate) { continue; }
//
//
//	//insertion sort�� �̿��� ������ ����
//	int j = n - 1;
//	while (j >= 0 && strcmp(str[j], word) > 0) {
//		str[j + 1] = str[j];
//		count[j + 1] = count[j];
//		j--;
//	}
//	//j = 0 �̰ų� word�� ���������� �� Ŭ�� ����
//	str[j + 1] = strdup(word);
//	count[j + 1] = 1;
//	n++;
//}
//for (int i = 0; i < n; i++) {
//	printf("%s: %d\n", str[i], count[i]);
//}
//printf("%d", n);


    ////**********2���� 2��************
	//char* str[10000];
	//int n = 0;
	//char word[100];
	//FILE* fp = fopen("harry.txt", "r");
	//while (fscanf(fp, "%s", word) != EOF) {
	//	//�ߺ� Ȯ��
	//	bool duplicate = false;
	//	for (int i = 0; i < n; i++) {
	//		if (strcmp(str[i], word) == 0) { 
	//			duplicate = true;
	//			break;
	//		}
	//	}
	//	if (duplicate) { continue; }
	//	
	//	int j = n - 1;
	//	while (j > 0 && strcmp(str[j], word) > 0) {
	//		str[j + 1] = str[j];
	//		j--;
	//	}
	//	//j = 0 �̰ų� word�� ���������� �� Ŭ�� ����
	//	str[j + 1] = strdup(word);
	//	n++;
	//}
	//printf("%d", n);
	//for (int i = 0; i < n; i++) {
	//	printf("%s\n", str[i]);
	//}


	////************2���� 1��************

	//char str1[100];
	//char str2[100];

	//scanf("%s", str1);
 //   scanf("%s", str2);
	//bool isSame = false;
	////���� ���� 2�� for���� 2�� ����Ͽ� �����ش�
	//for (int i = 0; i < strlen(str1); i++) {
	//	isSame = false;
	//	for (int j = 0; j < strlen(str2); j++) {
	//		if (str1[i] == str2[j]) { isSame = true; break; }
	//	}
	//	if (!isSame) { printf("no"); return 0; }
	//}

	//for (int i = 0; i < strlen(str2); i++) {
	//	isSame = false;
	//	for (int j = 0; j < strlen(str1); j++) {
	//		if (str2[i] == str1[j]) { isSame = true; break; }
	//	}
	//	if (!isSame) { printf("no"); return 0; }
	//}

	//printf("yes");

	//�Ʒ��� �߸��� Ǯ��, �ߺ� ������ �ʿ䵵 ����, �� �迭�� ���� �ȸ���
	//��!!!!!!!!!!!!!!!!!11

	//char temp[100];
	////�ʱ� �迭�� temp �� �����Ⱚ�̴�. ������� �ʵ��� ����!!!!!!!!!!
	////printf("temp �ʱ��� length : %d", strlen(temp));
	//bool isSame = false;

	////������ ������������ �����Ǿ����� �˻�
	////1. ù��° ���ڿ��� �� ���Ҹ� �ߺ��� �����Ͽ� ���ο� �迭�� ����
	////2. �ι�° ���ڿ��� ���鼭 ���Ұ� ���ο� �迭�� �����ϴ��� Ȯ��

	//scanf("%s", str1);
	//scanf("%s", str2);

	////�ߺ� �����Ͽ� �� �迭�� ����
	//int k = 0;
	//for (int i = 0; i < strlen(str1); i++) {
	//	for (int j = 0; j < k; j++) {
	//		if (str1[i] == temp[j]) {
	//			isSame = true; break;
	//		}
	//	}
	//	if (!isSame) {
	//		temp[k++] = str1[i];
	//	}
	//	//isSame �� true �� ���� ����
	//	isSame = false;
	//}

	//for (int i = 0; i < k; i++) {
	//	//���� ����Ҷ� "%d" ���� "%c"�����!!!!!!!!!!!!
	//	printf("%c ", temp[i]);
	//}

	//for (int i = 0; i < strlen(str2); i++) {
	//	isSame = false;
	//	printf("strlen(str2) ");
	//	for (int j = 0; j < k; j++) {
	//		if (str2[i] == temp[j]) {
	//			isSame = true; break;
	//		}
	//	}
	//	if (!isSame) { printf("no"); return 0; }
	//}

	//printf("yes");


	////************1���� 7��************
	////���� ��Ʈ���, ���� ���� ��, ���� ������ ������ ���� ��
	//int num = 0;
	//char line[100];
	//char* str[30];
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	scanf("%s", line);//�����Ϳ� ����
	//	str[i] = strdup(line);//!!!�о�ͼ� �����Ҷ� strdup���
	//}

	//for (int i = 0; i < num - 1 ; i++) {
	//	for (int j = 0; j < num - 1 - i; j++) {
	//		if (strlen(str[j]) > strlen(str[j + 1])) {
	//			char* temp;
	//			temp = str[j];
	//			str[j] = str[j + 1];
	//			str[j + 1] = temp;
	//		}
	//		else if (strlen(str[j]) == strlen(str[j + 1])) {
	//			if (strcmp(str[j], str[j + 1]) > 0) {
	//				char* temp;
	//				temp = str[j];
	//				str[j] = str[j + 1];
	//				str[j + 1] = temp;
	//			}
	//		}
	//	}
	//}
	//for (int i = 0; i < num; i++) {
	//	printf("%s\n", str[i]);
	//}

	//************1���� 5��************
	////�������� & �ߺ�����
	////1. ��������
	////2. �ߺ����� ���� ���� �� �迭�� �߰�
	//int num = 0; int data1[200]; int data2[200];
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	scanf("%d", &data1[i]);
	//}
	////�������� ����
	//for (int i = 0; i < num - 1; i++) {
	//	for (int j = 0; j < num - 1 - i; j++) {
	//		if (data1[j] > data1[j + 1]) {
	//			int temp = data1[j];
	//			data1[j] = data1[j + 1];
	//			data1[j + 1] = temp;
	//		}
	//	}
	//}

	////for (int i = 0; i < num; i++) {
	////	  printf("%d ", data1[i]);
	////}

	////�ߺ� ����
	////1. ���� �迭�� ���鼭 �� ���� �� �迭�� �ִ��� Ȯ��(2�� for��)
	////2. ������ �� �迭�� �߰�, ������ ���� �迭�� ���� ���ҷ� �̵�
	//int k = 0; bool isSame = false;
	//for (int i = 0; i < num; i++) {
	//	//�� �迭�� ���� �迭�� ���Ұ� �����ϴ��� �˻�
	//	for (int j = 0; j < k; j++) {
	//		if (data1[i] == data2[j]) {
	//			isSame = true; break;
	//		}
	//	}
	//	//���迭�� ���� ���Ұ� �������� ������ �� �迭�� �߰�
	//	if(!isSame) {
	//		data2[k++] = data1[i];
	//	}
	//	//isSame �� true �� ���� �����Ƿ� �ݵ�� ������ false������ �ٲ���� �Ѵ�
	//	isSame = false;
	//}
	//
	//printf("%d: ", k);
	//for (int i = 0; i < k;i++) {
	//	printf("%d ", data2[i]);
	//}








	//************1���� 4��************
	//int num = 0; int data[200]; int min = 0; int compare;
	//int minNum = 0;
	//scanf("%d", &num);
	//
	////�Է¹��� ������� �迭�� ����
	//for (int i = 0; i < num; i++) {
	// scanf("%d", &data[i]);
	//}
	//scanf("%d", &compare);

	////���� �� => �迭 ���Ұ����� compare �� ���� ��������
	//for (int i = 0; i < num; i++) {
	// //���̸� �������� ����
	// int temp = data[i] - compare;
	// if (temp < 0) temp = temp * -1;

	// if (i == 0) {
	// min = temp; minNum = data[i];
	// }
	// else {
	// if (temp < min) { min = temp; minNum = data[i]; }
	// }
	//}

	//printf("%d", minNum);


	//************1���� 3��************
//int data[100];
//int n = 0;
//int temp = 0;
//while (1) {
//	scanf("%d", &temp);
//	if (temp == -1) { return 0; }
//	//�ߺ� �˻�
//	bool duplicate = false;
//	for (int i = 0; i < n; i++) {
//		if (data[i] == temp) {
//			printf("duplicate\n");
//			duplicate = true;
//			break;
//		}
//	}
//	if (duplicate) { continue; }
//
//	int j = n - 1;
//	while (j >= 0 && data[j] > temp) {
//		data[j + 1] = data[j];
//		j--;
//	}
//	data[j + 1] = temp;
//	n++;
//	for (int i = 0; i < n;i++) {
//		printf("%d ", data[i]);
//	}
//	printf("\n");
}



	//************1���� 2��************
	//int num = 0;
	//int data[100];
	//int min1 = 0, min2 = 0;
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	// scanf("%d", &data[i]);
	// //i = 0 �϶� => ��x
	// if (i == 0) { min1 = data[i]; min2 = data[i]; }
	// //���� ���� �������� �� -> �״��� ���� ���� ��
	// //1. ���� ���������� ������ => min1�� min2�� �ű�� min1�ڸ��� ����
	// else {
	// if (data[i] < min1) {
	// min2 = min1;
	// min1 = data[i];
	// }
	// else if (data[i] < min2) {
	// min2 = data[i];
	// }
	// }
	//}
	//printf("%d %d", min1, min2);



	/*************1���� 1��************
	int num = 0;
	scanf("%d", &num);

	while (1) {
	if (num < 2) {
	printf("0"); break;
	}
	else {
	num = num / 2;
	printf("%d ", num);
	}
	}

	return 0;*/
}