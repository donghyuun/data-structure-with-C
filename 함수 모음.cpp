#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>//isspace, atoi...
#include <stdlib.h>
#include <math.h>
//strdup �� ����� ����

//*************���� �Լ� ����*************
//fscanf, �ܾ� �ϳ��� �о�ö�, ���ڴ� %s �� %c �� �ٲٸ� ��
char* str[100];
char line[100];
FILE* fp = fopen("harry.txt", "r");
while (fscanf(fp, "%s", word) != EOF) {
	str[i++] = strdup(word);
}
//fprint, �� ���� ����, but ���Ͽ� ���� �� �ִ� ���� �پ�
//��κ��� fputs ������ ó������, fputs�� ��������
fprintf(fp, "%d", 10);
fprintf(fp, " ");
fprintf(fp, "%s", table[i][j]);

//fputs, ���ڿ� ����
// ex) ����� ���Ͽ����� �� �ٿ� �ϳ��� �ܾ�� 
//�� �ܾ ���� ������ �� ���ڷ� �����Ͽ� ����
//��1)
FILE * fp2 = fopen("sorted_dict.txt", "w");
for (int i = 0; i < n; i++) {
	fputs(words[i], fp2);
	fputs("\t", fp2);
	fputs(strs[i], fp2);
	fputs("\n", fp2);
}
//��2)
FILE* fp2 = fopen("output.txt", "w");

for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		fputs(str[i][j], fp2);
		for (int k = 0; k < (maxCol[j] - strlen(str[i][j])); k++) {
			fputs(" ", fp2);
		}
		fputs(" ", fp2);
	}
	fputs("\n", fp2);
}
//fgets, ���� ����
//���๮��('\n')���� �����Ƿ� ������ �� �����ϰ� ���๮�� ����
while (fgets(line, max, fp) != NULL) {
	if (line[strlen(line) - 1] == '\n') {
		line[strlen(line) - 1] = '\0';
	}
	printf("%s\n", line);
}

//getchar(), ���� �����Ͽ� ���ڿ� �Է¹ޱ�(������Ʈ â����)
while (1) {
	char command[100];
	int ch = 0, j = 0;
	while ((ch = getchar()) != '\n') {
		command[j++] = ch;
	}
	command[j] = '\0';

	printf("%s\n", command);
}
//atoi, ���ڸ� ���ڷ� �ٲ��ش�
//"slice 0 1 1 2" ���ڿ��� command �� ������� ��
else if (strcmp(strtok(command, " "), "slice") == 0) {
int x = atoi(strtok(NULL, " "));
int p = atoi(strtok(NULL, " "));
int y = atoi(strtok(NULL, " "));
int q = atoi(strtok(NULL, " "));
		}
//*****************���� ����******************
//���ڿ��� ���ڹ迭�� �ٲٸ� ���ڹ迭 ���� ����

//�ڿ������� ���ϴ� �����Ʈ
void str_bsort1(char s[]) {
	for (int i = strlen(s) - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (s[j] > s[j + 1]) {
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}

//�տ������� ���ϴ� �����Ʈ(�׳� �̰� ����)
void str_bsort2(char s[]) {
	for (int i = 0; i < strlen(s) - 1; i++) {
		for (int j = 0; j < strlen(s) - 1 - i; j++) {
			if (s[j] > s[j + 1]) {
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}

void num_bsort(int data[], num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (data[j] > data[j + 1]) {
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}


//****************�ߺ� ����*******************

//���ڿ� ���� �ߺ� ����(���� ��� ���)
void str_compress(char s[]) {
	int j = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			//i = 0 �̰ų� i != 0 �̸鼭 s[i] != s[i - 1] => ����(����)
			s[j++] = s[i];//�������� ����
		}
	}//��������� �ϸ� ����� ���ڵ�ڷ� �����ִ� ���ڵ鵵 ����

	//���� ���ڿ��� ���� �˸��� '\0'�� �־���� ��
	s[j] = '\0';
}
//���ڿ��� ������ ���� & �ߺ����� 
//=> str_bsort2 & str_compress ��� �Բ� ���

//���� �迭 �ߺ� ����
//1. ���� �迭(data1)�� ���鼭 �� ���� �� �迭�� �ִ��� Ȯ��(2�� for��)
//2. ������ �� �迭(data2)�� �߰�, ������ ���� �迭�� ���� ���ҷ� �̵�
void num_compress(int data1[], int data2[], int num) {
	int k = 0; bool isSame = false;
	for (int i = 0; i < num; i++) {
		//�� �迭�� ���� �迭�� ���Ұ� �����ϴ��� �˻�
		for (int j = 0; j < k; j++) {
			if (data1[i] == data2[j]) {
				isSame = true; break;
			}
		}
		//���迭�� ���� ���Ұ� �������� ������ �� �迭�� �߰�
		if (!isSame) {
			data2[k++] = data1[i];
		}
		//isSame �� true �� ���� �����Ƿ� �ݵ�� ������ false������ �ٲ���� �Ѵ�
		isSame = false;
	}
}

//*********���ڿ�(���ڿ� ������ �迭X)�� ������ ������ ���� & �ߺ����� *********
//=> bsort & compress ��� �Բ� ���

//**********���� �迭�� �ߺ� �˻� & insertion sort******
int data[100];
int n = 0;
int temp = 0;
while (1) {
	scanf("%d", &temp);
	if (temp == -1) { return 0; }
	//�ߺ� �˻�
	bool duplicate = false;
	for (int i = 0; i < n; i++) {
		if (data[i] == temp) {
			printf("duplicate\n");
			duplicate = true;
			break;
		}
	}
	if (duplicate) { continue; }

	int j = n - 1;
	while (j >= 0 && data[j] > temp) {
		data[j + 1] = data[j];
		j--;
	}
	data[j + 1] = temp;
	n++;
	for (int i = 0; i < n;i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
//*********���ڿ��� ���ʿ��� ���� ����(���� ��� ���)************
//������ ���ڿ��� ������ �����Ų��, �� �迭�� ���� ���� �ʴ´�
//�� ��, �� ���� ����� �߰��� 2���̻� ������ ���� ��� ��������
void compress(char* str) {
	/*���������� ����ؼ� �� �迭�� ����� �� �迭�� ������ �� ����
	char tmp[1000];
	return tmp;*/
	int i = 0; int j = 0;
	while (str[i] != '\0') {//NULL('\0') ���� ������ ����
		//���� ���� ���ڰ� �����϶�
		if (i == 0 && str[i] == ' ') {
			i++;
			//printf("A");
			continue;
		}
		//���� �����̸鼭 �ڽŵ� �����϶�
		else if (str[i - 1] == ' ' && str[i] == ' ') {
			//�ڱ� ���� ���� ������ ������<--XXXXX!!!!
			//�׳� ������ ���ϸ� ��
			i++;
			//printf("B");
			continue;
		}
		str[j] = str[i++];
		j++;
		//printf("C");
	}
	//i �� ���� �ι����� ��ġ�� ����
	if (j > 0 && str[i - 1] == ' ') {
		str[j - 1] = '\0';
	}
	else {
		str[j] = '\0';
	}
}


//************������ �迭**************

//���ڿ� �о���鼭 ���ÿ� �ߺ�Ȯ�� & ����������(insertion sort)���
//insertion sort�� ���ڿ��� ���� �� ����
char* str[10000];
int n = 0;
char word[100];
FILE* fp = fopen("harry.txt", "r");
while (fscanf(fp, "%s", word) != EOF) {
	//�ߺ� Ȯ��
	bool duplicate = false;
	for (int i = 0; i < n; i++) {
		if (strcmp(str[i], word) == 0) {
			duplicate = true;
			break;
		}
	}
	if (duplicate) { continue; }

	int j = n - 1;
	while (j >= 0 && strcmp(str[j], word) > 0) {
		str[j + 1] = str[j];
		j--;
	}
	//j = 0 �̰ų� word�� ���������� �� Ŭ�� ����
	str[j + 1] = strdup(word);//strdup�ʼ�!!
	n++;
}
}
//*********���� �迭�� �ߺ� �ȵǰ� ���� �ϳ��� ����*******
//=>�迭�� �ش� ���ڰ� �̹� �����ϴ��� Ȯ���ϰ� 
//������ insertion sort or ���� �ڿ� �ְ� �����Ʈ ����

//insertion sort �ϱ� ����� ���̴°� ������ �����Ʈ �������

//***********���� ū ���� ������ �� ���� ���ҿ� ��ȯ�ϴ� ���� ���*******
//for �� ���� �Ϲ������� ���� ����
int num = 0;
int data[100];
scanf("%d", &num);
for (int i = 0; i < num; i++) {
	scanf("%d", &data[i]);
}

int max = 0, maxIndex = 0;
for (int i = num - 1; i > 0; i--) {
	max = 0; maxIndex = 0;//�ٽ� �ʱ�ȭ ����� �Ѵ�
	for (int j = 0; j <= i; j++) {
		if (data[j] > max) {
			max = data[j];
			maxIndex = j;
		}
	}
	int temp = data[i];
	//printf("data[%d]: %d\n", i, data[i]);
	data[i] = max;
	//printf("%d", data[i]);
	data[maxIndex] = temp;
}
