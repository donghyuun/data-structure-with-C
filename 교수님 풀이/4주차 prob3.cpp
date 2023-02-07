#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 10000
char* words[MAX];
char* exp[MAX];
int n = 0;

void compress(char* str);

int main() {
	int m, n;

	char* table[10][10];

	char line[MAX];
	FILE* fp = fopen("table.txt", "r");

	fscanf(fp, "%d %d ", &m, &n);
	for (int i = 0; i < m; i++) {
		fgets(line, MAX, fp);
		if (line[strlen(line) - 1] == '\n')//마지막 문장은 개행문자 없으므로 바꾸면 안됨
			line[strlen(line) - 1] = '\0';//개행문자까지 읽어서 포함하므로
		//printf("%s\n", line);

		char* p = strtok(line, "&");
		table[i][0] = strdup(p);
		for (int j = 1; j < n; j++) {
			p = strtok(NULL, "&");
			table[i][j] = strdup(p);
		}
	}
	fclose(fp);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			compress(table[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%s(%d):", table[i][j], strlen(table[i][j]));
		}
		printf("\n");
	}
	printf("\n");

	int colwidth[10];
	for (int j = 0; j < n; j++) {
		colwidth[j] = strlen(table[0][j]);
		for (int i = 1; i < m; i++) {
			if (strlen(table[i][j]) > colwidth[j]) {
				colwidth[j] = strlen(table[i][j]);
			}
		}
	}

	for (int j = 0; j < n; j++) {
		printf("%d ", colwidth[j]);
	}
	printf("\n");

	FILE* of = fopen("output.txt", "w");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(of, "%s", table[i][j]);
			for (int k = 0; k <= colwidth[j] - strlen(table[i][j]); k++) {
				fprintf(of, " ");
			}
		}
		fprintf(of, "\n");
	}
	fclose(of);

	return 0;
}
void compress(char* str) {
	int s = 0;//남길 문자를 저장할 인덱스
	for (int i = 0; i < strlen(str); i++) {
		if (!isspace(str[i]) ||
			i > 0 && !isspace(str[i - 1])) {//if str[i] should survive
			str[s++] = str[i];
		}
	}
	if (s > 0 && isspace(str[s - 1]))//마지막에 공백이 살아있을 수도 있음
		str[s - 1] = '\0';//이런것들을 볼때 s가 0이 될 수도 있다는 생각 해야함
	else str[s] = '\0';//마지막이 문자로 채워져 있는 경우
}