#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100

//***********모든 케이스 통과************
#pragma warning (disable: 4996)
#include <stdio.h>


int data[40][120] = { 0 };
int black = 1, white = 2;
bool finish = false;

int n;

int whiteWidCount = 0, blackWidCount = 0;
//대각선이 끝까지 위로 갔을때 [0,j]를 기준으로 count하기 때문에 
//행은 n*2, 열은 n*3만큼의 공간이 확보되어야 한다. 
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

	//수평으로 5개인지 검사
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

//수평 검사 함수
void widCheck(int i, int j) {
	//*****흰색*****
	if (data[i][j] == white) {
		//처음 시작
		if (whiteWidCount == 0) {
			whiteWidCount++;
		}
		//앞이 해당색깔 && 자신도 해당 색깔
		else if (data[i][j - 1] == white && data[i][j] == white) {
			whiteWidCount++;
			if (whiteWidCount == 5) { printf("white"); finish = true; return; }
		}
	}
	else {
		whiteWidCount = 0;
	}

	//*****검은색*****
	if (data[i][j] == black) {
		//처음 시작
		if (blackWidCount == 0) {
			blackWidCount++;
		}
		//앞이 해당색깔 && 자신도 해당 색깔
		else if (data[i][j - 1] == black && data[i][j] == black) {
			blackWidCount++;
			if (blackWidCount == 5) { printf("black"); finish = true; return; }
		}
	}
	else {
		blackWidCount = 0;
	}
}

//수직 검사 함수, 모든 열에 대해 동시에 각각의 colCount 실행
void colCheck(int i, int j) {
	//*****흰색*****
	if (data[i][j] == white) {
		//처음 시작
		if (whiteColCountArr[j] == 0) {
			whiteColCountArr[j]++;
			//printf("data[%d][%d] = whitecolCountArr[%d]: %d\n", i, j, j, whiteColCountArr[j]);
		}
		//앞이 해당색깔 && 자신도 해당 색깔
		else if (data[i - 1][j] == white) {
			whiteColCountArr[j]++;
			//printf("data[%d][%d] = whitecolCountArr[%d]: %d\n", i, j, j,whiteColCountArr[j]);
			if (whiteColCountArr[j] == 5) { printf("white"); finish = true; return; }
		}
	}
	//다른 색깔 또는 0
	else {
		whiteColCountArr[j] = 0;
	}

	//*****검은색*****
	if (data[i][j] == black) {
		//처음 시작
		if (blackColCountArr[j] == 0) {
			blackColCountArr[j]++;
			//printf("data[%d][%d] = black, blackcolCount: %d\n", i, j, blackColCountArr[j]);
		}
		//앞이 해당색깔 && 자신도 해당 색깔
		else if (data[i - 1][j] == black) {
			blackColCountArr[j]++;
			//printf("data[%d][%d] = black, blackcolCount: %d\n", i, j, blackColCountArr[j]);
			if (blackColCountArr[j] == 5) { printf("black"); finish = true; return; }
		}
	}
	//다른 색깔 또는 0
	else {
		blackColCountArr[j] = 0;
	}
}

//대각선 검사 함수, 모든 대각선에 대해 동시에 각각의 diaCount 실행
void diaCheck(int i, int j) {
	//*****흰색*****
	if (data[i][j] == white) {
		//처음 시작(오,위 방향)
		if (whiteLeftDiaCountArr[i + j] == 0) {
			whiteLeftDiaCountArr[i + j]++;
		}
		//이미 존재
		else if (data[i - 1][j + 1] == white) {
			whiteLeftDiaCountArr[i + j]++;
			if (whiteLeftDiaCountArr[i + j] == 5) { printf("white"); finish = true; return; }
		}

		//처음 시작(왼, 위 방향)
		if (whiteRightDiaCountArr[j - i] == 0) {
			whiteRightDiaCountArr[j - i]++;
		}
		//이미 존재
		else if (data[i - 1][j - 1] == white) {
			whiteRightDiaCountArr[j - i]++;
			if (whiteRightDiaCountArr[j - i] == 5) { printf("white"); finish = true; return; }
		}
	}
	//다른 색깔 또는 0
	else {
		whiteLeftDiaCountArr[i + j] = 0;
		whiteRightDiaCountArr[j - i] = 0;
	}

	//*****검은색*****
	if (data[i][j] == black) {
		//처음 시작(오,위 방향)
		if (blackLeftDiaCountArr[i + j] == 0) {
			blackLeftDiaCountArr[i + j]++;
		}
		//이미 존재
		else if (data[i - 1][j + 1] == black) {
			blackLeftDiaCountArr[i + j]++;
			if (blackLeftDiaCountArr[i + j] == 5) { printf("black"); finish = true; return; }
		}

		//처음 시작(왼, 위 방향)
		if (blackRightDiaCountArr[j - i] == 0) {
			blackRightDiaCountArr[j - i]++;
		}
		//이미 존재
		else if (data[i - 1][j - 1] == black) {
			blackRightDiaCountArr[j - i]++;
			if (blackRightDiaCountArr[j - i] == 5) { printf("black"); finish = true; return; }
		}
	}
	//다른 색깔 또는 0
	else {
		blackLeftDiaCountArr[i + j] = 0;
		blackRightDiaCountArr[j - i] = 0;
	}
}