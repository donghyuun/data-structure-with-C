#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
//중요한 점!!!!
//배열안의 어떤 값을 탐색할때 해당 배열이 오름차순으로 정렬되어 있다면
//앞에서 부터 비교하는게 좋은지, 뒤에서 부터 비교하는게 좋은지
//배열을 전부 돌아야 하는지, 일부만 돌면 되는지 생각한다!!

//*******모든 테스트 케이스 통과**********/
/**************배열이 오름차순으로 정렬되어 있는 경우를 순환으로 구현****************/
int floor(int* data, int begin, int end, int k);
int celling(int* data, int begin, int end, int k);
int data[1100];

int main(void) {
	
	int num, k;
	scanf("%d", &num);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &k);

	printf("%d\n", floor(0, num - 1, k));
	printf("%d\n", celling(0, num - 1, k));

	return 0;
}

//floor함수 =>  k보다 작거나 같으면서 가장 큰 정수 반환
//뒤에서 앞으로 가면서 k보다 작거나 같은 값 있으면 바로 출력
int floor(int front, int rear, int k) {
	//rear가 front 보다 앞으로 갔을때 => 해당 하는 값이 존재X 이므로 - 1 반환 
	if (rear == front - 1) return -1;

	if (data[rear] <= k) return data[rear];
	else floor(front, rear - 1, k);
}

//celling 함수 => k보다 크거나 같으면서 가장 작은 정수 반환
//앞에서 뒤로 가면서 k보다 크거나 같은 수 있으면 바로 출력
int celling(int front, int rear, int k) {
	//front가 rear 보다 뒤로 갔을때 => 해당 하는 값이 존재X 이므로 -1 반환
	if (front == rear + 1) return -1;

	if (data[front] >= k) return data[front];
	else celling(front + 1, rear, k);
}







//*********배열이 오름차순으로 정렬되어 있지 않은 경우를 순환으로 구현할 경우*********
//#define MAX 100
int floor(int len, int index, int maxIndex, int k);
int celling(int len, int index, int minValue, int k);
int data[MAX];

int main(void) {
	int num = 0;
	int k = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &data[i]);
	}
	scanf("%d", &k);

	//주의!! 전체 길이를 넘겨줄때 num을 넘겨줘야지 
	//num - 1(마지막 인덱스 번호)을 넘겨주면 안된다!!
	int maxValue = floor(num, 0, -1, k);//전체 길이, 첫 index, 초기 maxValue, k
	int minValue = celling(num, 0, -1, k);//전체 길이, 첫 index, 초기 minValue, k

	printf("%d\n%d", maxValue, minValue);

	return 0;
}

//floor함수 =>  k보다 작거나 같으면서 가장 큰 정수 반환
//int 로 해서 maxValue 반환하도록, 초기값은 -1
int floor(int len, int index, int maxValue, int k) {
	//maxIndex 는 가장 작거나 같으면서 가장 큰 값, 초기값은 -1

	//****빠져나올 경우**** => 마지막 index인 경우
	if (index == len - 1) {
		//마지막 인덱스의 값이 k보다 작거나 같을때
		if (data[index] <= k) {
			//마지막 인덱스의 값이 maxValue 보다 클때
			if (data[index] > maxValue) {
				//amxValue 를 마지막 인덱스의 값으로 변경
				maxValue = data[index];
			}
		}

		return maxValue;
	}

	//마지막 인덱스가 아닌 경우

	//해당 인덱스의 값이 k보다 같거나 작을때
	if (data[index] <= k) {
		//처음 조건을 만족할때!!! => 비교군이 없으므로 해당 값을 maxValue 로 설정
		if (maxValue == -1) {
			maxValue = data[index];
		}
		else {//처음이 아닐때(비교군 존재)
			if (data[index] > maxValue) {
				maxValue = data[index];
			}
		}
	}

	floor(len, index + 1, maxValue, k);
}


//celling 함수 => k보다 크거나 같으면서 가장 작은 정수 반환
//int 로 해서 minValue 반환하도록, 초기값은 -1
int celling(int len, int index, int minValue, int k) {
	//배열 길이, 현재 index, 현재 minValue, k

	//****빠져나올 구멍**** => 마지막 index 인 경우
	if (index == len - 1) {
		//마지막 인덱스의 값이 k보다 크거나 같은 경우
		if (data[index] >= k) {
			//해당 값이 minValue 보다 작은 경우
			if (data[index] < minValue) {
				minValue = data[index];
			}
		}

		return minValue;
	}

	//마지막 인덱스가 아닌 경우

	//해당 인덱스의 값이 k보다 크거나 같을때
	if (data[index] >= k) {
		//처음 조건을 만족할때!!! => 비교군이 없으므로 해당 값을 minValue로 설정
		if (minValue == -1) {
			minValue = data[index];
		}
		//처음이 아닐때(비교군 존재)
		else {
			if (data[index] < minValue) {
				minValue = data[index];
			}
		}
	}

	celling(len, index + 1, minValue, k);
}
