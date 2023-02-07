#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>

/********모든 테스트 케이스 통과******/
bool is_palindrome(int front, int rear, char str[]);

int main(void) {
	char str[MAX];
	int len;
	scanf("%s", str);//<-------문자열 받을때 %s 로 받아야한다!!!!! %d 로 문자열 받을 수 없음!!!!
	len = strlen(str);//문자열 길이

	bool result = is_palindrome(0, len - 1, str);//첫 인덱스, 마지막 인덱스, 문자열 시작 주소 넘김
	if (result) { printf("Yes"); }
	else { printf("No"); }

	return 0;
}

bool is_palindrome(int front, int rear, char str[]){
	//성공인 경우
	if (front == rear) return true;//문자열 길이 홀수일때, 정중앙에서 만남
	else if (rear + 1 == front) return true;//문자열 길이 짝수라면, 엇갈리게 됨

	//두 글자가 다른 경우
	if (str[front] != str[rear]) {
		return false;
	}
	//두 글자가 같은 경우
	//앞에것은 뒤로 한칸, 뒤에것은 앞으로 한칸 당겨서 비교
	else {
		is_palindrome(front + 1, rear - 1, str);
	}
}