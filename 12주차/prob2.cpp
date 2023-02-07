#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>

//1. 제일 앞글자 비교
//2. 앞글자가 동일하다면 그다음 문자 비교
//3-1. 그다음 문자가 만약 str1[i] 이 null이라면 -1
//     str2[i]가 null 이라면 1, 둘다 null이라면 0
//3-2. 위의 모든 경우가 아니라면 다시 해당 문자끼리 비교

/*********모든 테스트 케이스 통과*********/
int compare(char* str1, char* str2);
int i = 0;//방법2 용

int main(void) {
	char str1[100];
	char str2[100];

	scanf("%s", str1);
	scanf("%s", str2);

	int result = compare(str1, str2);
	if (result == -1) printf("%s %s", str1, str2);
	else if (result == 0) printf("%s %s", str1, str2);
	else if (result == 1) printf("%s %s", str2, str1);

	return 0;
}

//방법 1. 포인터를 이용해 한글자씩 접근
int compare(char* str1, char* str2) {
	if (*str1 < *str2) { return -1; }
	else if (*str1 > * str2) { return 1; }

	//두 문자가 같은 경우
	else {
		if (*str1 == '\0') { return 0; }
		compare(str1 + 1, str2 + 1);
	}
}
//방법 2. 전역변수 index를 주고 배열처럼 접근
int compare2(char* str1, char* str2) {
	if (str1[i] < str2[i]) { return -1; }
	else if (str1[i] > str2[i]) { return 1; }

	//두 문자가 같은 경우, 다음 문자의 사전식 순서를 비교
	//만약 두 문자 모두 길이가 끝인 경우 
	else {
		if (str1[i] == '\0') return 0;
		i++;
		compare(str1, str2);
	}
}