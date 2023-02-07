#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 10000

//***********모든 케이스 통과************
int main() {
	char str[LINE_LENGTH];
	scanf("%s", str);
	int tempIndex = 0; int maxIndex = 0;
	int tempVal = 0; int maxVal = 0;
	int count = 0;
	char mo[5] = { 'a','e','i','o','u' };

	// count = 0일때 자음인지 모음인지 , count > 0 일때 자음인지 모음인지 판별
	for (int i = 0; i < strlen(str); i++) {
		//자음이 처음 시작할때
		if (count == 0) {
			bool isSame = false;
			for (int j = 0; j < 5; j++) {
				if (str[i] == mo[j]) { isSame = true; break; }//모음일때, 그냥 stop
			}
			if (!isSame) { tempIndex = i; count++; }; //자음이라면
		}
		else if (count > 0) {
			//자음이 끝났을때, 현재가 모음일때
			bool isSame = false;
			for (int j = 0; j < 5; j++) {
				if (str[i] == mo[j]) { isSame = true; break; }
			}
			if (isSame) {
				if (count > maxVal) {
					maxVal = count;
					maxIndex = tempIndex;
				}
				count = 0;
				tempIndex = 0;
			}
			//자음이 안끝났을때, 앞에도 자음 && 현재도 자음
			bool isSame1 = false; bool isSame2 = false;
			for (int j = 0; j < 5; j++) {
				if (str[i - 1] == mo[j]) { isSame1 = true; break; }
			}
			for (int j = 0; j < 5; j++) {
				if (str[i] == mo[j]) { isSame2 = true; break; }
			}
			if (!isSame1 && !isSame2) count++;

		}
	}
	for (int i = 0; i < maxVal; i++) {
		printf("%c", str[maxIndex++]);
	}

	return 0;
}