#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//********�׽�Ʈ ��� ���*********

//1. ���ڿ��� �Է¹޾Ƽ� �ش� ���ĺ����� ������ �迭�� ����
//2. �� ���ڿ��� ���ڰ��� ��(���� �ߺ����� �ʿ� x), ���ڿ� ���� strlen �̿�
// str1 �� ���ĺ��� str2 �� �� �ְ� & str2 �� ���ĺ��� str1 �� �� ����
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
