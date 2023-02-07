#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARR_LENGTH 200

//<풀이> 
//열린 괄호 일때는 순서 출력 & 스택에 열린 괄호가 나온 순서를 기록
//닫힌괄호 일때는 해당 원소를 스택에서 출력

int main(void) {
	char str[MAX];
	int data[MAX];
	int upperCount = 1;
	scanf("%s", str);

	int i = 0, j = 0;
	while (str[i] != '\0') {
		if (str[i] == '(') {//여는 괄호일때
			printf("%d ", upperCount);
			data[j++] = upperCount++;//스택에 열린 괄호가 나온 순서를 삽입
		}
		else if (str[i] == ')') {//닫는 괄호일때
			printf("%d ", data[j - 1]);//현재 스택 제일 위의 원소를 출력
			j--;//새 원소 삽입할 위치 재조정
		}
		i++;
	}

	return 0;
}