#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 200
//********�׽�Ʈ ��� ���*********


//for���� int i ���� � ���� �������� ��������
//���δ�� 0, 1������ �����ϸ� �ȵ�
void Sort(int* arr, int len) {
	for (int i = len - 1; i > 0; i--) {
		int maxValue = arr[0]; int maxIndex = 0;
		for (int j = 0; j <= i; j++) {
			if (arr[j] >= maxValue) {
				maxValue = arr[j];
				maxIndex = j;
			}
			//���� ������ ���ҿ� �ִ밪 ���Ҹ� ��ȯ
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