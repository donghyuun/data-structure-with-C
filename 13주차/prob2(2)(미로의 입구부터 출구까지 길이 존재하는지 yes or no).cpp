#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

//입력받은 N * N 배열에서 미로의 입구부터 출구까지 
//갈 수 있는 길이 존재하는지 yes, no 로 출력
#define VISITED 2
#define BACKTRACKED 3

bool rec(int x, int y);
bool findPath(int x, int y, int dir);
int x_move_to(int x, int dir);
int y_move_to(int y, int dir);

int N;
int data[MAX][MAX];
int main(void) {
	FILE* fp = fopen("input2.txt", "r");
	fscanf(fp, "%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(fp, "%d", &data[i][j]);
		}
	}
	printf("(0 0)시작\n");
	if (rec(0, 0)) { printf("Yes"); }
	else printf("No");
}

bool rec(int x, int y) {//현재 위치가 x, y라고 가정
	//(x,y)로부터 갈 수 있는 방향을 찾아, 그 위치로 이동 & 다시 재귀 함수 호출

	data[x][y] = VISITED;//방문했다고 표시

	if (x == N - 1 && y == N - 1) {//출구인지 검사;
		return true;
	}

	bool isForwarded = false;//더 이상 갈 곳이 없는 경우에 false.
	for (int dir = 0; dir < 4; dir++) {
		if (findPath(x, y, dir)) {//dir 방향으로 갈 수 있다면
			isForwarded = true;
			//(x,y)를 해당 위치로 이동
			x = x_move_to(x, dir);
			y = y_move_to(y, dir);
			printf("(%d %d)로 이동\n", x, y);
			//이동한 위치에 대해 다시 재귀함수 호출
			if (rec(x, y)) {
				return true;//쭉쭉쭉 내려오면서 return true 가 된다
			}
		}
	}

	//4방향 모두 갈 곳이 없다면 이전 위치로 돌아간다.
	if (!isForwarded) {
		data[x][y] = BACKTRACKED;
		return false;
	}
}

int x_move_to(int x, int dir) {
	if (dir == 0) return x - 1;
	else if (dir == 1) return x;
	else if (dir == 2) return x + 1;
	else return x;
}
int y_move_to(int y, int dir) {
	if (dir == 0) return y;
	else if (dir == 1) return y + 1;
	else if (dir == 2) return y;
	else return y - 1;
}


//dir 방향에 대해 (x,y)가 갈 수 있는지 판단
bool findPath(int x, int y, int dir) {
	//dir = 0 이면 북쪽
	if (dir == 0) {
		if (x > 0 && data[x - 1][y] == 0) return true;//최소 1행 이상이어야 함
		return false;
	}
	//dir = 1 이면 동쪽
	if (dir == 1) {
		if (y < N - 1 && data[x][y + 1] == 0) return true;
		return false;
	}
	//dir = 2 이면 남쪽
	if (dir == 2) {
		if (x < N - 1 && data[x + 1][y] == 0) return true;
		return false;
	}
	//dir = 3 이면 서쪽
	if (dir == 3) {
		if (y > 0 && data[x][y - 1] == 0) return true;
		return false;
	}
}