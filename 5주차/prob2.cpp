#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100

//***********모든 케이스 통과************
int main() {
	int max = 200;
	int maxWid[10];
	int maxCol[10];
	int minWid[10];
	int minCol[10];
	char line[200];
	int data[100][100];
	int n = 0;

	FILE* fp = fopen("data.mat", "r");
	if (fp == NULL) printf("open faied");
	fscanf(fp, "%d ", &n);

	//행렬 읽어와 저장
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &data[i][j]);
			//행의 최대,최소
			if (j == 0) {
				maxWid[i] = data[i][0]; minWid[i] = data[i][0];
			}
			else if (j > 0) {
				if (data[i][j] > maxWid[i]) {
					maxWid[i] = data[i][j];
				}
				if (data[i][j] < minWid[i]) {
					minWid[i] = data[i][j];
				}
			}
			//열의 최대,최소
			if (i == 0) {
				maxCol[j] = data[0][j]; minCol[j] = data[0][j];
			}
			else if (i > 0) {
				if (data[i][j] > maxCol[j]) {
					maxCol[j] = data[i][j];
				}
				if (data[i][j] < minCol[j]) {
					minCol[j] = data[i][j];

				}
			}
		}
	}

	while (1) {
		int ch = 0, i = 0;
		printf("$ ");
		while ((ch = getchar()) != '\n') {
			line[i++] = ch;
		}
		line[i] = '\0';

		if (strcmp(line, "exit") == 0) {
			break;
		}
		//show => 행렬 출력
		else if (strcmp(line, "show") == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d ", data[i][j]);
				}
				printf("\n");
			}
		}
		//colmax
		else if (strcmp(line, "colmax") == 0) {
			for (int i = 0; i < n;i++) {
				printf("%d ", maxCol[i]);
			}
			printf("\n");
		}
		//colmin
		else if (strcmp(line, "colmin") == 0) {
			for (int i = 0; i < n;i++) {
				printf("%d ", minCol[i]);
			}
			printf("\n");
		}
		//rowmax
		else if (strcmp(line, "rowmax") == 0) {
			for (int i = 0; i < n;i++) {
				printf("%d ", maxWid[i]);
			}
			printf("\n");
		}
		//rowmin
		else if (strcmp(line, "rowmin") == 0) {
			for (int i = 0; i < n;i++) {
				printf("%d ", minWid[i]);
			}
			printf("\n");
		}
		else if (strcmp(strtok(line, " "), "slice") == 0) {
			//문자를 정수로 바꿔준다
			int x = atoi(strtok(NULL, " "));
			int p = atoi(strtok(NULL, " "));
			int y = atoi(strtok(NULL, " "));
			int q = atoi(strtok(NULL, " "));
			
			for (int i = x; i < n; i = i + p) {
				for (int j = y; j < n; j = j + q) {
					printf("%d ", data[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}