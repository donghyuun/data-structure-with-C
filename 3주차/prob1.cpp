#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 200
//********테스트 모두 통과*********


//for문의 int i 값에 어떤 값이 들어가야할지 생각하자
//무턱대고 0, 1등으로 시작하면 안됨
void Sort(int* arr, int len) {
	for (int i = len - 1; i > 0; i--) {
		int maxValue = arr[0]; int maxIndex = 0;
		for (int j = 0; j <= i; j++) {
			if (arr[j] >= maxValue) {
				maxValue = arr[j];
				maxIndex = j;
			}
			//제일 마지막 원소와 최대값 원소를 교환
			int temp = arr[maxIndex];
			arr[maxIndex] = arr[i];
			arr[i] = temp;
		}
	}
}

int main(void) {
	int arr[100];
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	Sort(arr, num);

	for (int j = 0; j < num; j++) {
		printf("%d ", arr[j]);
	}
	return 0;
}