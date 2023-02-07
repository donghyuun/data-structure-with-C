#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 200
//********�׽�Ʈ ��� ���*********

void bubbleSort(int* arr1, int* arr2, int len) {
	for (int i = 0; i < len - 1; i++) { //O
		for (int j = 0; j < len - 1 - i; j++) {//O
			//���� ���Ұ� ���� ���Һ��� Ŭ��
			if (arr1[j] > arr1[j + 1]) {
				int temp1 = arr1[j + 1];
				arr1[j + 1] = arr1[j];
				arr1[j] = temp1;

				int temp2 = arr2[j + 1];
				arr2[j + 1] = arr2[j];
				arr2[j] = temp2;
			}
			//���� ���ҿ� ���� ������ ���� ������
			else if (arr1[j] == arr1[j + 1]) {
				//�ش� �ε����� �����Ǵ� arr2 �� ���Ҹ� ��
				if (arr2[j] > arr2[j + 1]) {
					int temp1 = arr1[j + 1];
					arr1[j + 1] = arr1[j];
					arr1[j] = temp1;

					int temp2 = arr2[j + 1];
					arr2[j + 1] = arr2[j];
					arr2[j] = temp2;
				}
			}
		}
	}
}

int main(void) {
	int num = 0;
	int arr1[BUFFER_SIZE];
	int arr2[BUFFER_SIZE];


	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &arr1[i], &arr2[i]);
	}
	bubbleSort(arr1, arr2, num);

	for (int j = 0; j < num; j++) {
		printf("%d %d\n", arr1[j], arr2[j]);
	}
	return 0;
}