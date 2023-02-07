#pragma warning (disable: 4996)
#include <stdio.h>
#include "stack.h"
#include <math.h>
#define MAX 20

//응용 n-queen문제(과제)
//크기가 N x N 배열에 N-queen의 가능한 모든 해의 갯수를 출력
//이때 N 은 1~15 케이스에 대해 각각 수행하라
int count = 0;//해당 배열에 가능한 모든 해의 갯수
int N = 1;
bool queens(int level);
bool promising(int level);

int cols[MAX];//cols[level] <= 해당 level 에 놓인 말의 열번호(***1부터 시작***)

int main() {
	for (int i = 1; i <= 15; i++) {//N 이 1~15까지이므로 15번 반복해야 함
		for (int j = 1; j <= N; j++) {//해당 배열이 사용하기 위해 cols배열 초기화!!
			cols[j] = 0;
		}
		count = 0; //해당 배열의 가능한 모든 해의 갯수도 초기화!!

		for (int k = 1; k <= N; k++) {
			cols[1] = k;//level 1의 k 열에 
			queens(1);
		}
		N++;
		printf("%d\n", count);
	}
}

bool queens(int level) {//현재 level 에 놓은 말과 1~ level - 1  에 놓인 말이 충돌하는지 확인 & 충돌하지 않으면 다음 레벨에 말 놓고 다시 queens 함수 재귀호출 
	//printf("현재 level: %d\n", level);
	if (!promising(level))//1 ~ level - 1 번째의 말들과 충돌하지 않는지
		return false;
	//충돌하지 않았다고 확인된 상태
	//1) level 이 N일때, 즉 정상적으로 N번째까지 말이 다 놓였을때
	else if (level == N) {
		count++;//해의 갯수 증가
		return true;
	}
	//2) level 이 N이 아닐때, 다시 다음 레벨에 말을 놓은 다음 재귀함수 호출
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;//level + 1 레벨의 i열에 말을 놓은 다음
		if (queens(level + 1))//다시 해당 위치에 말을 놓을 수 있는지 검사
			return false;
		//중요!!!,만약 queens(level + 1)가 false 라면 다음 방향에 대해 검사하게 됨
		//=> 이 문제에선, queens(level + 1)가 true 임에도 false를 리턴하여
		//   전체의 모든 경우를 따지게 되면서 
		//   가능한 모든 해의 갯수를 count 하게 된다!!!!!
	}
	return false;//N번째까지 말이 놓이는 경우가 한번도 없는 경우, queens함수의 반환값이 false가 됨
}

// 1 ~ level-1 번째(레벨)의 말들과 충돌하지 않았는지 검사
bool promising(int level) {
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])//같은 열 일때
			return false;
		else if (level - i == abs(cols[level] - cols[i]))//대각선으로 충돌할때(Math.abs X, abs O)
			return false;
	}
	return true;//(level 이 1이면 그냥 return true)
}


}

//기본 n-queen 문제(강의자료)
//크기가 N x N 배열에 대해 첫번째 말이 놓여져 있을때,
//레벨 1의 해당 열로부터 시작한 N-Queen 성립 가능성 판단
//=> 열의 갯수만큼 레벨1 & 해당 열에서 시작한 경로의 n-queen 해가 존재하는지 나타냄
//ex) N = 4 인, 즉 4 x 4 배열의 경우 No Yes Yes No
int count = 0;
int N = 5;//예제
bool queens(int level);
bool promising(int level);

int cols[MAX];//cols[level] <= 해당 level 에 놓인 말의 열번호

int main() {
	for (int i = 1; i <= N; i++) {//Level 1에 N개의 위치에 말을 놓음
		cols[1] = i;//첫번째 말의 열 위치설정(1 ~ N) = 말을 놓음
		if (queens(1)) printf("Yes"); //그에 따른 재귀 함수 호출의 결과(level 1부터 시작)
		else printf("No");
	}
}

bool queens(int level) {//현재 level 에 놓은 말과 1~ level - 1  에 놓인 말이 충돌하는지 확인 & 충돌하지 않으면 다음 레벨에 말 놓고 다시 queens 함수 재귀호출
	//printf("현재 level: %d\n", level);
	if (!promising(level))//1 ~ level - 1 번째의 말들과 충돌하지 않는지
		return false;
	//충돌하지 않았다고 확인된 상태
	//1) level 이 N일때, 즉 정상적으로 N번째까지 말이 다 놓였을때
	else if (level == N)
		return true;
	//2) level 이 N이 아닐때, 다시 다음 레벨에 말을 놓은 다음 재귀함수 호출
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;//level + 1 레벨의 i열에 말을 놓은 다음
		if (queens(level + 1))//다시 해당 위치에 말을 놓을 수 있는지 검사
			return true;
		//중요!!!,만약 queens(level + 1)가 false 라면 다음 방향에 대해 검사하게 됨
	}
	return false;//N번째까지 말이 놓이는 경우가 한번도 없는 경우, queens함수의 반환값이 false가 됨
}

// 1 ~ level-1 번째(레벨)의 말들과 충돌하지 않았는지 검사
bool promising(int level) {
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])//같은 열 일때
			return false;
		else if (level - i == abs(cols[level] - cols[i]))//대각선으로 충돌할때(Math.abs X, abs O)
			return false;
	}
	return true;//(level 이 1이면 그냥 return true)
}