#pragma warning(disable: 4996)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//*********모든 케이스 통과*********
int main(void) {
	int n = 0, count = 0;
	int arr[100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) count++;
		}
	}

	printf("%d", count);

	return 0;
}
