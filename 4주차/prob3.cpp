#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_LENGTH 300


//*********�߰� ���� ���� ���� �׽�Ʈ ���***********
//but, �ܼ�â���� ���������� ���̺� ���� �����Ǵµ�, txt ���Ͽ�����
//�빮�ڿ� �ҹ����� ���ڰ����� Ʋ�� �� ��߳��°� �����ϴ�.
//�Ʒ��� �ܼ�â ��� �ڵ尡 �ֽ��ϴ�!
char* trim(char* str);

int main(void) {
	char str[BUFFER_LENGTH];
	char* strArr[10][10];
	int max[10];
	int m = 0, n = 0;
	FILE* fp = fopen("table.txt", "r");
	fscanf(fp, "%d %d ", &m, &n);

	//max �迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		max[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		fgets(str, BUFFER_LENGTH, fp);

		char* temp = strdup(trim(strtok(str, "&")));
		strArr[i][0] = temp;

		if (i == 0) max[0] = strlen(temp);
		else if (i > 0) {
			if (strlen(temp) > max[0]) {
				max[0] = strlen(temp);
			}
		}

		for (int j = 1; j < n; j++) {
			temp = strdup(trim((strtok(NULL, "&"))));
			if (j == n - 1) temp[strlen(temp) - 1] = '\0';

			if (strlen(temp) > max[j]) {
				max[j] = strlen(temp);
			}
			strArr[i][j] = temp;
		}
	}

	//******�ܼ�â ��� �ڵ�******
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%s ", strArr[i][j]);
			if (max[j] > strlen(strArr[i][j])) {
				for (int k = 0; k < max[j] - strlen(strArr[i][j]); k++) {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	*/
	//******************************

	FILE* fp2 = fopen("ouput.txt", "w");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fputs(strArr[i][j], fp2);
			if (max[j] > strlen(strArr[i][j])) {
				for (int k = 0; k < max[j] - strlen(strArr[i][j]); k++) {
					fputs(" ", fp2);
				}
			}
			fputs(" ", fp2);
		}
		fputs("\n", fp2);
	}

	fclose(fp2);

	return 0;
}


char* trim(char* str) {
	char* end, * stp, * endp;
	int i = 0, len;

	stp = str;//�յ� ���� ���� �̵���
	end = str + strlen(str) - 1;
	endp = end;//�յ� ���� ���� �̵���

	while (stp <= end && isspace(*stp)) stp++;
	while (endp >= stp && isspace(*endp)) endp--;


	len = (endp < stp) ? 0 : (endp - stp) + 1;
	stp[len] = '\0';

	int count = 0;

	return stp;
}
