#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 100000
#define BUFFER_SIZE 30

//*******�׽�Ʈ ��� ���********

int i = 0, tempLen = 0, realLen = 0;
char* tempArr[CAPACITY];
char* realArr[CAPACITY];

//1. temp �迭�� ���̰� 6�̻��� �ܾ�鸸�� �ߺ��� �����Ͽ� �����Ѵ�.
//2, real �迭�� ���̰� 6�̻��� �ܾ�鸸�� �ߺ��� ������ �� �����Ѵ� 
//3. real �迭�� ������ �����Ѵ�.
//3. ���� for ������ real �迭�� ���Ұ� temp �迭�� ��� �����ϴ��� ã�´�(count)
//	 �̶� ���� for���ȿ��� ������� �ʿ��� printf ���� �����Ѵ�

//1. temp �迭�� ���̰� 6�̻��� �ܾ�鸸�� �ߺ��� �����Ͽ� �����Ѵ�.
void tempload(void) {

	char buf1[BUFFER_SIZE];

	FILE* fp = fopen("harry.txt", "r");
	if (fp == NULL) { printf("Open failed.\n"); return; }

	while (fscanf(fp, "%s", buf1) != EOF) {
		char* temp; bool isTrue = false;
		temp = strdup(buf1);

		//���̰� 6�̻��� ���ڿ��� ����
		if (strlen(temp) >= 6) { tempArr[tempLen] = temp; tempLen++; }
	}
	/*//tempArr ���
	while (tempArr[i] != NULL) {
		printf("tempArr ���: %s \n", tempArr[i]);
		i++;
	}
	*/

	fclose(fp);
}
//2, temp �迭�� �̿��� real �迭�� ���̰� 6�̻��� �ܾ�鸸�� 
//	 �ߺ��� ������ �� �����Ѵ� 
//���
//1. �迭�� ���� for������ ���鼭 �ߺ�
void realload(void) {
	int i = 0; bool isTrue = false;
	while (tempArr[i] != NULL) {
		char* temp = tempArr[i];
		for (int j = 0; j < realLen; j++) {
			//tempArr�� ���Ұ� realArr�� �迭�� ������ ��
			if (strcmp(temp, realArr[j]) == 0) { isTrue = true; break; }
		}
		//���� ���ϸ鼭 ���̰� 6�̻��϶�
		if (!isTrue) { realArr[realLen] = temp; realLen++; }
		i++;
		isTrue = false;
	}
	/*//realArr ���
	int j = 0;
	while (realArr[j] != NULL) {
		printf("realArr ���: %s \n", realArr[j]);
		j++;
	}
	*/
}

//realArr�� ������ ����
void sort(void) {
	char *temp;
	//������ ����
	for (int i = 0; i < realLen - 1; i++) {//j: �迭�� ���� = ���ڿ��� ����
		for (int k = 0; k < realLen - 1 - i; k++) {
			if (strcmp(realArr[k], realArr[k + 1]) > 0) {
				temp = realArr[k];
				realArr[k] = realArr[k + 1];
				realArr[k + 1] = temp;
			}
		}
	}
	
	//������ ���ĵ� realArr��� 
	//int l = 0; while (realArr[l] != NULL) { printf("%s\n", file[l]); l++; }
	
}

void show(void) {
	for (int i = 0; i < realLen; i++) {
		int count = 0;
		for (int j = 0; j < tempLen; j++) {
			if (strcmp(realArr[i], tempArr[j]) == 0) { count++; }
		}
		printf("%s: %d\n", realArr[i], count);
	}
	printf("%d", realLen);
}

int main(void) {

	tempload();
	realload();
	sort();
	show();
	return 0;
}
