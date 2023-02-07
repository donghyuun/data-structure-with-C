#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100
//*************모든 케이스 통과***************
char line[500];

int main() {

	FILE* fp = fopen("sample.html", "r");
	FILE* fp2 = fopen("sample.txt", "w");
	int index = 0;
	while (fgets(line, LINE_LENGTH, fp) != NULL) {
		if (line[strlen(line) - 1] == '\n') {
			line[strlen(line) - 1] = '\0';
		}
		int i = 0; int j = 0;
		while (line[i] != '\0') {
			//line[i] != '\n' XXX!!, '\n' 문자 없애버리고 
			//그자리에 '\0' 문자 넣었기때문에 문장의 끝을 '\0'로
			//봐야함

			// < 태그 만났을때, > 태그만날때까지 처리
			if (line[i] == '<') {
				while (line[i] != '>') {
					i++;
				}
				i++;
			}
			//태그 안만났을때
			else {
				line[j++] = line[i];
				// 이 방법 중요!!, 
				//새로운 인덱스 이용해서 배열의 값 앞으로 당김!!
				i++;
			}
		}
		line[j] = '\0';//값 다 당겼으면 그 뒤에 널문자('\0')추가
		fprintf(fp2, "%s\n", line);
	}
	fclose(fp);
	fclose(fp2);

	return 0;

}