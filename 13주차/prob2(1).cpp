#pragma warning (disable: 4996)
#include <stdio.h>
#include "stack.h"
#include <math.h>
#define MAX 20

/******모든 테스트 케이스 통과****/
//기존의 문제(출구 있는지 없는지)에서 출구까지 간 경우 count갯수만 증가시키고
//return false를 통해 다시 다른 출구까지의 경로가 있는지 검사한다.
//                  => 훨씬 복잡함!!!!!!!!!!!!
//********다른 방법 사용!!!!!!!!!!!!!!!!!!!!!!!********
//임의로 테스트 케이스를 2개(arr1, arr2) 설정하였습니다.
void find(int x, int y);

int count = 0;
int N = 5;//square 2차원 배열 크기
int arr2[4][4] = { {0,1,1,1},{0,0,0,0}, {0,1,1,0}, {0,0,0,0} };
int arr1[5][5] = { {0,0,0,0,0}, {0,1,0,1,0,}, {0,1,0,1,0}, {0,1,0,1,0},{0,0,0,0,0} };
int main(void) {
	find(0, 0);
	printf("count : %d", count);

	return 0;
}

void find(int x, int y) {
	//printf("현재위치: (%d, %d)\n", x, y);
	if (x == N - 1 && y == N - 1) {
		count++; //목적지 도착한 경우 count++
		//printf("목적지 도착, count 증가\n");
		//목적지는 2로 체크 안해도 되고, 다른 방향으로 찾을 필요도 X
		return;
	}

	arr1[x][y] = 2;//현재 도착한 위치 방문했다고 표시


	//북
	if (x >= 1) {
		if (arr1[x - 1][y] == 0)
		{
			//printf("\"북\"으로 이동\n");
			find(x - 1, y);
		}
	}
	//동
	if (y < N-1) {
		if (arr1[x][y + 1] == 0) {
			//printf("\"동\"으로 이동\n");
			find(x, y + 1);
		}
	}
	//남
	if (x < N-1) {
		if (arr1[x + 1][y] == 0) {
			//printf("\"남\"으로 이동\n");
			find(x + 1, y);
		}
			
	}
	//서
	if (y >= 1) {
		if (arr1[x][y-1] == 0){
			//printf("\"서\"로 이동\n");
			find(x, y-1);
		}
			
	}
	//printf("더 이상 이동할 곳 없음\n");
	arr1[x][y] = 0;
	//4방향 다 검색하고 나면 다시 0으로 변경해주어 다시 검색할
	//수 있도록 해준다.
	//=> 어차피 똑같은 경로로는 다시 올 수 없음 

	return;//만약 시작점에서 4방향으로 모두 탐색 한 후, 다시 시작점으로 오게되면
	//제일 상위함수인 상태이므로 return 시 전체 재귀 종료!
}