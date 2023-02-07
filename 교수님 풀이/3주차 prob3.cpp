#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 1000
#define MAX 10000
char* words[MAX];
char* exp[MAX];
int n = 0;

int main() {

	char line[LINE_LENGTH];
	FILE* fp = fopen("shuffled_dict.txt", "r");

	while (fgets(line, LINE_LENGTH, fp) != NULL) {
		//�������ٿ��� ���๮�� ���� ���� �־
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		//���๮�ڸ� ������쿡 �������� �ʴ´�
		if (strlen(line) <= 0)
			continue;

		char *p = strtok(line, "\t");//�ܾ�

		//insertion sort, �޾ƿ��鼭 ����!!
		int j = n - 1;
		while (j >= 0 && strcmp(words[j], p) > 0) {
			words[j + 1] = words[j];
			exp[j + 1] = exp[j];
			j--;
		}
		words[j + 1] = strdup(p);
		p = strtok(NULL, "\t");//����
		exp[j+1] = strdup(p);
		n++;
	}

	for (int i = 0; i < n; i++)
		printf("%s: %s\n", words[i], exp[i]);

	fclose(fp);

	return 0;
}