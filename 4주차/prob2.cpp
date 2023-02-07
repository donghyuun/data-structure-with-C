#pragma warning(disable: 4996)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//*********모든 케이스 통과********
int main(void) {
	int n = 0;
	int arr[10][10];
	double avgWid[10];
	double avgCol[10];
	double sdWid[10];
	double sdCol[10];

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) { printf("open failed"); return 1; }

	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int val = 0;
			fscanf(fp, "%d", &val);
			arr[i][j] = val;
		}
	}

	//i번째 행 평균
	for (int i = 0; i < n; i++) {
		double avSum = 0;
		//i번째 행 평균
		for (int j = 0; j < n; j++) {
			avSum += arr[i][j];
		}
		avgWid[i] = avSum / n;
		avSum = 0;

		//i번째 열 평균
		for (int j = 0; j < n; j++) {
			avSum += arr[j][i];
		}
		avgCol[i] = avSum / n;
	}

	for (int i = 0; i < n; i++) {
		double sdSum = 0;
		//i번째 행 표준편차
		for (int j = 0; j < n; j++) {
			sdSum += pow((avgWid[i] - arr[i][j]), 2);
		}
		sdWid[i] = sqrt(sdSum / n);
		sdSum = 0;

		for (int j = 0; j < n; j++) {
			sdSum += pow((avgCol[i] - arr[j][i]), 2);
		}
		sdCol[i] = sqrt(sdSum / n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("%.2f %.2f", avgWid[i], sdWid[i]);
		printf("\n");
	}
	for (int j = 0; j < n; j++) {
		printf("%.2f ", avgCol[j]);
	}

	printf("\n");
	for (int k = 0; k < n; k++) {
		printf("%.2f ", sdCol[k]);
	}
}