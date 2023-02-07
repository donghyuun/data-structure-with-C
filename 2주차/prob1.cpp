#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//********테스트 모두 통과*********

//1. 문자열을 입력받아서 해당 알파벳들을 각각의 배열에 저장
//2. 두 문자열의 문자값을 비교(굳이 중복제거 필요 x), 문자열 길이 strlen 이용
// str1 의 알파벳이 str2 에 다 있고 & str2 의 알파벳이 str1 에 다 있음
int main(void) {
	char str1[100]; char str2[100];

	scanf_s("%s", str1, sizeof(str1));
	scanf_s("%s", str2, sizeof(str2));

	for (int i = 0; i < strlen(str1); i++) {
		bool true1 = false;
		for (int j = 0; j < strlen(str2); j++) {
			if (str1[i] == str2[j]) true1 = true;
		}
		if (!true1) { printf("no"); return 0; }
		true1 = false;
	}

	for (int i = 0; i < strlen(str2); i++) {
		bool true2 = false;
		for (int j = 0; j < strlen(str1); j++) {
			if (str2[j] == str1[i]) true2 = true;
		}
		if (!true2) { printf("no"); return 0; }
		true2 = false;
	}

	printf("yes");


	return 0;
}
