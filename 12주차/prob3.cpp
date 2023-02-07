#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#define MAX 100

//3번
//1. data[begin] + data[end] > k 이면 => --end 하고 다시 재귀
//2. data[begin] + data[end] < k 이면 => ++begin 하고 다시 재귀
//3. data[begin] + data[end] == k 이면 => ++begin, --end, 횟수 + 1
//   하고 다시 재귀

//*******테스트 케이스 모두 통과*********/
void rec(int front, int rear, int k);
int rec2(int front, int rear, int k);
int data[MAX];
int count = 0;//rec 함수용 전역변수

int main(void) {
	int num = 0;
	int k = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &k);

	int result = rec2(0, num - 1, k);//<방법 2>
	//<방법 1>
	//rec(0, num -1, k);
	//printf("%d", count);
	printf("%d", result);

	return 0;
}


//방법2. 내부에서 자체적으로 갯수를 count 하여 return; 
//교수님 피셜, 이게 더 깔끔함
int rec2(int front, int rear, int k) {
	//빠져나올 경우
	if (front >= rear) return 0;

	int sum = data[front] + data[rear];
	if (sum > k) return 0 + rec2(front, rear - 1, k);//rear-- 사용불가!! 대신 --rear 사용!!!
	else if (sum < k) return 0 + rec2(front + 1, rear, k);
	else return 1 + rec2(front + 1, rear - 1, k);
}


//방법1. 외부에서 전역변수로 선언된 count를 사용
void rec(int front, int rear, int k) {
	//종료 시점<----이거 주의하기
	if (front >= rear) return;//front < rear 일때 return XXXX!!!!

	int sum = data[front] + data[rear];
	//k보다 크면 rear 한칸 앞으로
	if (sum > k) { rear -= 1; }
	//k보다 작으면 front 한칸 뒤로
	else if (sum < k) { front += 1; }
	//같으면 rear 한칸 앞으로 & front 한칸 뒤로
	else {
		count++;
		rear -= 1;
		front += 1;
	}
	rec(front, rear, k);
}

