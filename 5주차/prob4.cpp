#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 100
//*************��� ���̽� ���***************
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
			//line[i] != '\n' XXX!!, '\n' ���� ���ֹ����� 
			//���ڸ��� '\0' ���� �־��⶧���� ������ ���� '\0'��
			//������

			// < �±� ��������, > �±׸��������� ó��
			if (line[i] == '<') {
				while (line[i] != '>') {
					i++;
				}
				i++;
			}
			//�±� �ȸ�������
			else {
				line[j++] = line[i];
				// �� ��� �߿�!!, 
				//���ο� �ε��� �̿��ؼ� �迭�� �� ������ ���!!
				i++;
			}
		}
		line[j] = '\0';//�� �� ������� �� �ڿ� �ι���('\0')�߰�
		fprintf(fp2, "%s\n", line);
	}
	fclose(fp);
	fclose(fp2);

	return 0;

}