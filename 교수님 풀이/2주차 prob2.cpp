#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>

int main() {
	char* words[5000];
	int n = 0;
	char buf[40];

	FILE* fp = fopen("harry.txt", "r");

	while (fscanf(fp, "%s", buf) != EOF) {
		bool duplicate = false;
		for (int i = 0;i < n; i++) {
			if (strcmp(buf, words[i]) == 0) {
				duplicate = true;
				break;
			}
		}
		if (!duplicate) {
			//words[n++] = buf; 불가!!
			//words[n++] = strdup(buf); strdup 사용!!
			int j = n - 1;
			while (j >= 0 && strcmp(buf, words[j]) < 0) {
				words[j + 1] = words[j];
				j--;
			}
			words[j + 1] = strdup(buf);
			n++;
		}
	}
	
	fclose(fp);

	//for (int i = 0; i < n; i++) {
	//	printf("%s\n", words[i]);
	//}

	char prefix[40];
	scanf("%s", prefix); 

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (strncmp(prefix, words[i], strlen(prefix)) == 0)
		{
			printf("%s\n", words[i]);
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}
