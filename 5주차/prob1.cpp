#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE_LENGTH 1000
#define MAX 10000

//***********��� ���̽� ���************
int main() {
	char str[LINE_LENGTH];
	scanf("%s", str);
	int tempIndex = 0; int maxIndex = 0;
	int tempVal = 0; int maxVal = 0;
	int count = 0;
	char mo[5] = { 'a','e','i','o','u' };

	// count = 0�϶� �������� �������� , count > 0 �϶� �������� �������� �Ǻ�
	for (int i = 0; i < strlen(str); i++) {
		//������ ó�� �����Ҷ�
		if (count == 0) {
			bool isSame = false;
			for (int j = 0; j < 5; j++) {
				if (str[i] == mo[j]) { isSame = true; break; }//�����϶�, �׳� stop
			}
			if (!isSame) { tempIndex = i; count++; }; //�����̶��
		}
		else if (count > 0) {
			//������ ��������, ���簡 �����϶�
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
			//������ �ȳ�������, �տ��� ���� && ���絵 ����
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