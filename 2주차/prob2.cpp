#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 100000
#define BUFFER_SIZE 30

//********테스트 모두 통과*********

int i = 0, j = 0;
char* file[CAPACITY];

//파일 읽어서 배열에 저장
void load(void) {

	char buf1[BUFFER_SIZE];

	FILE* fp = fopen("harry.txt", "r");
	if (fp == NULL) { printf("Open failed.\n"); return; }

	while (fscanf(fp, "%s", buf1) != EOF) {
		char* temp; bool isTrue = false;
		temp = strdup(buf1);
		for (int j = 0; j < i; j++) {
			//존재할 때
			//******중요******, 문자열을 비교할때는 포인터끼리 비교하는 방법인
			//temp == file[j] 로 하는게 아니라 strcmp 함수를 써야함
			if (strcmp(temp, file[j]) == 0) { isTrue = true; break; }
		}
		//존재 안할 때
		if (!isTrue) { file[i] = temp; i++; }
		isTrue = false;
	}
	//배열의 길이 구하기
	while (file[j] != NULL) {
		//printf("%s ", file[j]);
		j++;
	}

	fclose(fp);
}
//읽어와서 저장된 배열 사전식으로 바꿈, 버블 정렬 이용하면 될듯
//사전식 정렬 strcmp 함수 이용
//strcmp(str1, str2), result > 0이면 str1>str2, < 0 이면 str1<str2, 0이면 같음

void sort(void) {
	char* temp;
	//사전식 정렬
	for (int i = 0; i < j - 1; i++) {//j: 배열의 길이 = 문자열의 개수
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
	//printf("문자열을 입력하시오: ");
	scanf("%s", str);
	//입력받은 문자열의 길이 구하기
	int len = strlen(str);
	//printf("입력받은 문자열의 길이: %d\n", len);
	int i = 0;

	//배열 돌면서 해당 단어를 접두어로 가지고 있는 문자열 출력

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
