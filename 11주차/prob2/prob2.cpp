#pragma warning (disable: 4996)
#include <stdio.h>
#include "stack.h"
#define MAX 100
#define WALL 0
#define PATH 1
#define VISITED 2
#define BACKTRACKED 3

/***********모든 케이스 통과***********/

bool movable(Position pos, int dir, int caseSize);
int data[60][60];

int main(void) {
	//너비우선 탐색(BFS)
	//2자원 배열으로 방문 방법, 이중for문 사용
	//
	//이미지 픽셀 방문 시
	//(방문한 적 없는 경우)
	//큐에 노드삽입 && 현재 픽셀 방문 표시 && count++
	//8방향에 대해 갈 위치 없으면 count 출력(해당 컴포넌트 BFS 탐색 완료)
	//그 다음 배열 원소에 대해 BFS 탐색

	//********DFS랑 다른 점*******
	//DFS 처럼 현재 위치가 매번 이동하는 것이 아니라 dequeue되는 노드가 현재 위치가 된다.

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

		//BFS 탐색
		Queue q = create();//queue_type을 가리키는 포인터
		Position cur;//현재 위치를 나타내는 구조체
		cur.x = 0;
		cur.y = 0;

		//2차원 배열 하나씩 돌면서, 이미 돌았던 원소면 다시 안돔
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				//배열의 각 픽셀에 대해 탐색했었는지 확인 후 탐색 한적 없다면 DFS 시작
				//탐색할 수 있는 픽셀이 아닌 경우(방문했었거나, 벽, 외부인 경우) => 그다음 픽셀로 넘어감
				if (data[j][k] != PATH) continue; 
				else {//새로운 컴포넌트의 첫 시작
					cur.x = j; cur.y = k;
					count = 1;
					enqueue(q, cur, -1);//-1인 경우는 현재 위치 바로 enqueue
					data[cur.x][cur.y] = VISITED;
				}

				//(만약, 컴포넌트의 첫 시작인 경우 시작한 위치를 dequeue하게 됨)
				while (1) {
					Link link = dequeue(q);
					cur.x = link->x; cur.y = link->y;//dequeue 된 노드를 현재 위치로
					bool forwarded = false;//갈 수 있는 길이 있는지 없는지 나타냄

					for (int dir = 0; dir < 8; dir++) {//7개 방향에 대해 갈 수 있는지 검사
						//이동 가능한 경로를 모두 삽입한다. 현재 위치와, dir(방향), size 을 인자로 넘김
						if (movable(cur, dir, size)) {//이동 가능한 경로라면 해당 위치 큐에 삽입
							enqueue(q, cur, dir); count++;
							forwarded = true;
						}
					}

					//큐가 비어, 더 이상 dequeue할 수 없는 경우
					if (is_empty(q)) {
						printf("%d ", count); break;
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
	//이동가능한 경우 해당 위치에 방문표시를 해버린다.
	if (dir == 0) {
		if (data[cur.x - 1][cur.y] == 1) {
			data[cur.x - 1][cur.y] = VISITED;
			return true;
		}
		else return false;
	}
	//동북
	else if (dir == 1) {
		if (data[cur.x - 1][cur.y + 1] == 1) {
			data[cur.x - 1][cur.y + 1] = VISITED;
			return true;
		}
		else return false;
	}
	//동
	else if (dir == 2) {
		if (data[cur.x][cur.y + 1] == 1) {
			data[cur.x][cur.y + 1] = VISITED;
			return true;
		}
		else return false;

	}
	// 동남
	else if (dir == 3) {
		if (data[cur.x + 1][cur.y + 1] == 1) {
			data[cur.x + 1][cur.y + 1] = VISITED;
			return true;
		}
		else return false;
	}
	//남
	else if (dir == 4) {
		if (data[cur.x + 1][cur.y] == 1) {
			data[cur.x + 1][cur.y] = VISITED;
			return true;
		}
		else return false;
	}
	//남서
	else if (dir == 5) {
		if (data[cur.x + 1][cur.y - 1] == 1) {
			data[cur.x + 1][cur.y - 1] = VISITED;
			return true;
		}
		else return false;
	}
	//서
	else if (dir == 6) {
		if (data[cur.x][cur.y - 1] == 1) {
			data[cur.x][cur.y - 1] = VISITED;
			return true;
		}
		else return false;
	}
	//북서
	else if (dir == 7) {
		if (data[cur.x - 1][cur.y - 1] == 1) {
			data[cur.x - 1][cur.y - 1] = VISITED;
			return true;
		}
		else return false;
	}
}
