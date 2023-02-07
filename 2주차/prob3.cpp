#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 100000
#define BUFFER_SIZE 30

//*******테스트 모두 통과********

int i = 0, tempLen = 0, realLen = 0;
char* tempArr[CAPACITY];
char* realArr[CAPACITY];

//1. temp 배열에 길이가 6이상인 단어들만을 중복을 포함하여 저장한다.
//2, real 배열에 길이가 6이상인 단어들만을 중복을 제거한 후 저장한다 
//3. real 배열을 사전식 정렬한다.
//3. 이중 for 문으로 real 배열의 원소가 temp 배열에 몇번 등장하는지 찾는다(count)
//	 이때 이중 for문안에서 결과문에 필요한 printf 문을 실행한다

//1. temp 배열에 길이가 6이상인 단어들만을 중복을 포함하여 저장한다.
void tempload(void) {

	char buf1[BUFFER_SIZE];

	FILE* fp = fopen("harry.txt", "r");
	if (fp == NULL) { printf("Open failed.\n"); return; }

	while (fscanf(fp, "%s", buf1) != EOF) {
		char* temp; bool isTrue = false;
		temp = strdup(buf1);

		//길이가 6이상인 문자열만 저장
		if (strlen(temp) >= 6) { tempArr[tempLen] = temp; tempLen++; }
	}
	/*//tempArr 출력
	while (tempArr[i] != NULL) {
		printf("tempArr 출력: %s \n", tempArr[i]);
		i++;
	}
	*/

	fclose(fp);
}
//2, temp 배열을 이용해 real 배열에 길이가 6이상인 단어들만을 
//	 중복을 제거한 후 저장한다 
//방법
//1. 배열을 이중 for문으로 돌면서 중복
void realload(void) {
	int i = 0; bool isTrue = false;
	while (tempArr[i] != NULL) {
		char* temp = tempArr[i];
		for (int j = 0; j < realLen; j++) {
			//tempArr의 원소가 realArr의 배열에 존재할 때
			if (strcmp(temp, realArr[j]) == 0) { isTrue = true; break; }
		}
		//존재 안하면서 길이가 6이상일때
		if (!isTrue) { realArr[realLen] = temp; realLen++; }
		i++;
		isTrue = false;
	}
	/*//realArr 출력
	int j = 0;
	while (realArr[j] != NULL) {
		printf("realArr 출력: %s \n", realArr[j]);
		j++;
	}
	*/
}

//realArr를 사전식 정렬
void sort(void) {
	char *temp;
	//사전식 정렬
	for (int i = 0; i < realLen - 1; i++) {//j: 배열의 길이 = 문자열의 개수
		for (int k = 0; k < realLen - 1 - i; k++) {
			if (strcmp(realArr[k], realArr[k + 1]) > 0) {
				temp = realArr[k];
				realArr[k] = realArr[k + 1];
				realArr[k + 1] = temp;
			}
		}
	}
	
	//사전식 정렬된 realArr출력 
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
