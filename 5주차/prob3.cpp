#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100

//***********��� ���̽� ���************
#pragma warning (disable: 4996)
#include <stdio.h>


int data[40][120] = { 0 };
int black = 1, white = 2;
bool finish = false;

int n;

int whiteWidCount = 0, blackWidCount = 0;
//�밢���� ������ ���� ������ [0,j]�� �������� count�ϱ� ������ 
//���� n*2, ���� n*3��ŭ�� ������ Ȯ���Ǿ�� �Ѵ�. 
int whiteLeftDiaCountArr[120] = { 0 }, whiteRightDiaCountArr[120] = { 0 };
int blackLeftDiaCountArr[120] = { 0 }, blackRightDiaCountArr[120] = { 0 };
int whiteColCountArr[120] = { 0 }, blackColCountArr[120] = { 0 };


void widCheck(int i, int j);
void colCheck(int i, int j);
void diaCheck(int i, int j);

int main()
{
	FILE* fp = fopen("board.txt", "r");
	if (fp == NULL) { printf("open failed"); }

	fscanf(fp, "%d ", &n);
	printf("%d\n", n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &data[i+n][j+n*2]);
			//printf("%d ", data[i*2][j*3]);
		}
		//printf("\n");
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", data[i+n][j+n*2]);
		}
		printf("\n");
	}

	//�������� 5������ �˻�
	for (int i = n; i < n*2; i++) {
		whiteWidCount = 0, blackWidCount = 0;
		for (int j = n; j < n*3; j++) {
			widCheck(i, j);
			colCheck(i, j);
			diaCheck(i, j);
		}
	}
	if (!finish) { printf("Not Finished"); }

	return 0;
}

//���� �˻� �Լ�
void widCheck(int i, int j) {
	//*****���*****
	if (data[i][j] == white) {
		//ó�� ����
		if (whiteWidCount == 0) {
			whiteWidCount++;
		}
		//���� �ش���� && �ڽŵ� �ش� ����
		else if (data[i][j - 1] == white && data[i][j] == white) {
			whiteWidCount++;
			if (whiteWidCount == 5) { printf("white"); finish = true; return; }
		}
	}
	else {
		whiteWidCount = 0;
	}

	//*****������*****
	if (data[i][j] == black) {
		//ó�� ����
		if (blackWidCount == 0) {
			blackWidCount++;
		}
		//���� �ش���� && �ڽŵ� �ش� ����
		else if (data[i][j - 1] == black && data[i][j] == black) {
			blackWidCount++;
			if (blackWidCount == 5) { printf("black"); finish = true; return; }
		}
	}
	else {
		blackWidCount = 0;
	}
}

//���� �˻� �Լ�, ��� ���� ���� ���ÿ� ������ colCount ����
void colCheck(int i, int j) {
	//*****���*****
	if (data[i][j] == white) {
		//ó�� ����
		if (whiteColCountArr[j] == 0) {
			whiteColCountArr[j]++;
			//printf("data[%d][%d] = whitecolCountArr[%d]: %d\n", i, j, j, whiteColCountArr[j]);
		}
		//���� �ش���� && �ڽŵ� �ش� ����
		else if (data[i - 1][j] == white) {
			whiteColCountArr[j]++;
			//printf("data[%d][%d] = whitecolCountArr[%d]: %d\n", i, j, j,whiteColCountArr[j]);
			if (whiteColCountArr[j] == 5) { printf("white"); finish = true; return; }
		}
	}
	//�ٸ� ���� �Ǵ� 0
	else {
		whiteColCountArr[j] = 0;
	}

	//*****������*****
	if (data[i][j] == black) {
		//ó�� ����
		if (blackColCountArr[j] == 0) {
			blackColCountArr[j]++;
			//printf("data[%d][%d] = black, blackcolCount: %d\n", i, j, blackColCountArr[j]);
		}
		//���� �ش���� && �ڽŵ� �ش� ����
		else if (data[i - 1][j] == black) {
			blackColCountArr[j]++;
			//printf("data[%d][%d] = black, blackcolCount: %d\n", i, j, blackColCountArr[j]);
			if (blackColCountArr[j] == 5) { printf("black"); finish = true; return; }
		}
	}
	//�ٸ� ���� �Ǵ� 0
	else {
		blackColCountArr[j] = 0;
	}
}

//�밢�� �˻� �Լ�, ��� �밢���� ���� ���ÿ� ������ diaCount ����
void diaCheck(int i, int j) {
	//*****���*****
	if (data[i][j] == white) {
		//ó�� ����(��,�� ����)
		if (whiteLeftDiaCountArr[i + j] == 0) {
			whiteLeftDiaCountArr[i + j]++;
		}
		//�̹� ����
		else if (data[i - 1][j + 1] == white) {
			whiteLeftDiaCountArr[i + j]++;
			if (whiteLeftDiaCountArr[i + j] == 5) { printf("white"); finish = true; return; }
		}

		//ó�� ����(��, �� ����)
		if (whiteRightDiaCountArr[j - i] == 0) {
			whiteRightDiaCountArr[j - i]++;
		}
		//�̹� ����
		else if (data[i - 1][j - 1] == white) {
			whiteRightDiaCountArr[j - i]++;
			if (whiteRightDiaCountArr[j - i] == 5) { printf("white"); finish = true; return; }
		}
	}
	//�ٸ� ���� �Ǵ� 0
	else {
		whiteLeftDiaCountArr[i + j] = 0;
		whiteRightDiaCountArr[j - i] = 0;
	}

	//*****������*****
	if (data[i][j] == black) {
		//ó�� ����(��,�� ����)
		if (blackLeftDiaCountArr[i + j] == 0) {
			blackLeftDiaCountArr[i + j]++;
		}
		//�̹� ����
		else if (data[i - 1][j + 1] == black) {
			blackLeftDiaCountArr[i + j]++;
			if (blackLeftDiaCountArr[i + j] == 5) { printf("black"); finish = true; return; }
		}

		//ó�� ����(��, �� ����)
		if (blackRightDiaCountArr[j - i] == 0) {
			blackRightDiaCountArr[j - i]++;
		}
		//�̹� ����
		else if (data[i - 1][j - 1] == black) {
			blackRightDiaCountArr[j - i]++;
			if (blackRightDiaCountArr[j - i] == 5) { printf("black"); finish = true; return; }
		}
	}
	//�ٸ� ���� �Ǵ� 0
	else {
		blackLeftDiaCountArr[i + j] = 0;
		blackRightDiaCountArr[j - i] = 0;
	}
}