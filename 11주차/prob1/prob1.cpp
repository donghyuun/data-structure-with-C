#pragma warning (disable: 4996)
#include <stdio.h>
#include "stack.h"
#define MAX 100
#define WALL 0
#define PATH 1
#define VISITED 2
#define BACKTRACKED 3

/***********모든 케이스 통과***********/
//스택에 구조체를 넣을때 해당 구조체 타입을 가리키는 포인터에게 동적할당으로 공간을 부여하여
//배열 처럼 사용할 수 있다.
bool movable(Position pos, int dir, int caseSize);
int data[60][60];

int main(void) {
	//깊이우선 탐색(DFS)
	//2자원 배열으로 방문 방법, 이중for문 사용
	//
	//이미지 픽셀 방문 시
	//(방문한 적 없는 경우)
	//스택에 현재 위치 push & 해당 위치로 이동한 후, 해당 픽셀 방문 표시 & count++
	//7방향에 대해 갈 위치 없으면 스택에서 pop해서 왔던 위치로 돌아감
	//돌아온 위치가 제일 처음 DFS 시작한 위치이면서 스택이 빈 경우 count 출력 & 초기화

	int num = 0;
	int size = 0;

	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &num);//케이스 갯수

	for (int i = 0; i < num; i++) {//케이스 갯수만큼 반복
		fscanf(fp, "%d", &size);//배열 사이즈(크기: size * size )
		int count = 0;
		//배열 원소들 입력받음
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size;j++) {
				fscanf(fp, "%d", &data[i][j]);
				//printf("%d", data[i][j]);
			}
			//printf("\n");
		}

		Stack s = create();//stack_type 을 가리키는 포인터
		Position cur;//현재 위치를 나타내는 구조체
		cur.x = 0;
		cur.y = 0;

		//2차원 배열 하나씩 돌면서, 이미 돌았던 원소면 다시 안돔
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {

				if (data[j][k] != PATH) continue; //갈 수 있는 길이 아닌 경우
				else {//갈 수 있는 길인 경우 => 해당 노드로 이동(현재 위치 변경)
					cur.x = j; cur.y = k;
					count = 1;
				}

				while (1) {
					data[cur.x][cur.y] = VISITED;//방문했다고 표시
					bool forwarded = false;//갈 수 있는 길이 있는지 없는지 나타냄

					for (int dir = 0; dir < 8; dir++) {//7개 방향에 대해 갈 수 있는지 검사
						if (movable(cur, dir, size)) {//갈 수 있으면
							push(s, cur);//스택에 현재 위치를 나타내는 구조체 삽입한 후
							cur = move_to(cur, dir);//해당 방향으로 현재위치 변경
													//빠져나오기 전까지 while문 안에서 계속 돌게 됨
							forwarded = true;
							count++;
							break;
						}
					}

					//7개 방향중 갈 수 있는 곳이 한곳도 없을때
					if (!forwarded) {
						data[cur.x][cur.y] = BACKTRACKED;
						//여기로 돌아왔는데 갈 곳이 없고 스택이 비어서 더 이상 돌아갈 곳이 없는경우
						if (is_empty(s)) { printf("%d ", count); break; }
						cur = pop(s); //이전 위치로 돌아옴(스택의 가장 위에 있는 위치를 빼면서
									  //해당 위치로 내가 이동함
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}

bool movable(Position cur, int dir, int caseSize) {
	//dir 0이면 북, 1이면 동북 , 2면 동, 3이면 동남, 4면 남, 5면 남서, 6이면 서, 7이면 북서
	//북
	if (dir == 0) {
		if (data[cur.x - 1][cur.y] == 1)return true;
		else return false;
	}
	//동북
	else if (dir == 1) {
		if (data[cur.x - 1][cur.y + 1] == 1)return true;
		else return false;
	}
	//동
	else if (dir == 2) {
		if (data[cur.x][cur.y + 1] == 1)return true;
		else return false;

	}
	// 동남
	else if (dir == 3) {
		if (data[cur.x + 1][cur.y + 1] == 1)return true;
		else return false;
	}
	//남
	else if (dir == 4) {
		if (data[cur.x + 1][cur.y] == 1)return true;
		else return false;
	}
	//남서
	else if (dir == 5) {
		if (data[cur.x + 1][cur.y - 1] == 1)return true;
		else return false;
	}
	//서
	else if (dir == 6) {
		if (data[cur.x][cur.y - 1] == 1)return true;
		else return false;
	}
	//북서
	else if (dir == 7) {
		if (data[cur.x - 1][cur.y - 1] == 1)return true;
		else return false;
	}
}