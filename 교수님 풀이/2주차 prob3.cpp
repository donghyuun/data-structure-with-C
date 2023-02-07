#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>

int main() {
	char* words[5000];
	int counter[5000] = { 0 };//��� ���� 0���� �ʱ�ȭ
	int n = 0;
	char buf[40];

	FILE* fp = fopen("harry.txt", "r");

	while (fscanf(fp, "%s", buf) != EOF) {
		if (strlen(buf) < 6)
			continue;

		bool duplicate = false;
		for (int i = 0;i < n; i++) {
			if (strcmp(buf, words[i]) == 0) {
				duplicate = true;
				counter[i]++;
				break;
			}
		}
		if (!duplicate) {
			int j = n - 1;
			while (j >= 0 && strcmp(buf, words[j]) < 0) {
				words[j + 1] = words[j];
				counter[j + 1] = counter[j];//counter�� ��Ʈ�� �ڷ� ����
				j--;
			}
			words[j + 1] = strdup(buf);//words[j+1] = buf; �Ұ�!!
			counter[j + 1] = 1;
			n++;
		}
	}

	fclose(fp);


	for (int i = 0; i < n; i++) {
		printf("%s: %d\n", words[i], counter[i]);
	}
	printf("%d\n", n);
	return 0;
}
