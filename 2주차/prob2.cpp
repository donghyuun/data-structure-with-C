#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 100000
#define BUFFER_SIZE 30

//********�׽�Ʈ ��� ���*********

int i = 0, j = 0;
char* file[CAPACITY];

//���� �о �迭�� ����
void load(void) {

	char buf1[BUFFER_SIZE];

	FILE* fp = fopen("harry.txt", "r");
	if (fp == NULL) { printf("Open failed.\n"); return; }

	while (fscanf(fp, "%s", buf1) != EOF) {
		char* temp; bool isTrue = false;
		temp = strdup(buf1);
		for (int j = 0; j < i; j++) {
			//������ ��
			//******�߿�******, ���ڿ��� ���Ҷ��� �����ͳ��� ���ϴ� �����
			//temp == file[j] �� �ϴ°� �ƴ϶� strcmp �Լ��� �����
			if (strcmp(temp, file[j]) == 0) { isTrue = true; break; }
		}
		//���� ���� ��
		if (!isTrue) { file[i] = temp; i++; }
		isTrue = false;
	}
	//�迭�� ���� ���ϱ�
	while (file[j] != NULL) {
		//printf("%s ", file[j]);
		j++;
	}

	fclose(fp);
}
//�о�ͼ� ����� �迭 ���������� �ٲ�, ���� ���� �̿��ϸ� �ɵ�
//������ ���� strcmp �Լ� �̿�
//strcmp(str1, str2), result > 0�̸� str1>str2, < 0 �̸� str1<str2, 0�̸� ����

void sort(void) {
	char* temp;
	//������ ����
	for (int i = 0; i < j - 1; i++) {//j: �迭�� ���� = ���ڿ��� ����
		for (int k = 0; k < j - 1 - i; k++) {
			if (strcmp(file[k], file[k + 1]) > 0) {
				temp = file[k];
				file[k] = file[k + 1];
				file[k + 1] = temp;
			}
		}
	}
	int l = 0;
	//while (file[l] != NULL) { printf("%s\n", file[l]); l++; }

}

void show(void) {
	int count = 0;
	char str[30];
	char temp[30] = "";
	//printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%s", str);
	//�Է¹��� ���ڿ��� ���� ���ϱ�
	int len = strlen(str);
	//printf("�Է¹��� ���ڿ��� ����: %d\n", len);
	int i = 0;

	//�迭 ���鼭 �ش� �ܾ ���ξ�� ������ �ִ� ���ڿ� ���

	while (file[i] != NULL) {
		strncpy(temp, file[i], len * sizeof(char));
		//printf("%s\n", temp);
		if (strcmp(str, temp) == 0) { printf("%s\n", file[i]); count++; }
		i++;
	}
	printf("%d", count);

}

int main(void) {

	load();
	sort();
	show();
	return 0;
}
