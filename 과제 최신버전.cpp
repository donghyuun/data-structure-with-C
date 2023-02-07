#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>// atoi, isspace ...
#define MAX 1000

//5주차 3번 함수 선언
//int data[20][20];
//bool check(int x, int y, int num) {
//	//check four directions, sw, s, se,e
//	int mystone = data[x][y];
//	//서남쪽
//	//data[x+1][y-1] data[x+2][y-2] data[x+3][y-3] data[x+4][y-4] 
//	int d = 1;
//	while (d < 5 && x + d < num && y - d >= 0) {
//		if (data[x + d][y - d] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//
//	//남쪽
//	d = 1;
//	while (d < 5 && x + d < num ) {
//		if (data[x + d][y] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//	//남동쪽
//	d = 1;
//	while (d < 5 && x + d < num && y + d >= 0) {
//		if (data[x + d][y + d] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//	//동쪽
//	d = 1;
//	while (d < 5 && y + d >= 0) {
//		if (data[x][y + d] != mystone)
//			break;
//		d++;
//	}
//	if (d == 5) { return true; }
//	
//
//	return false;
//}
//4주차 3번 함수 선언
//void compress(char *str) {
//	/*지역변수를 사용해서 새 배열을 만들고 그 배열을 리턴할 순 없음
//	char tmp[1000];
//	return tmp;*/
//	int i = 0; int j = 0;
//	while (str[i] != '\0') {//NULL('\0') 문자 만나면 멈춤
//		//제일 앞의 문자가 공백일때
//		if (i == 0 && str[i] == ' ') {
//			i++;
//			//printf("A");
//			continue;
//		} 
//		//앞이 공백이면서 자신도 공백일때
//		else if (str[i - 1] == ' ' && str[i] == ' ') {
//			//자기 뒤의 문자 앞으로 가져옴<--XXXXX!!!!
//			//그냥 저장을 안하면 됨
//			i++;
//			//printf("B");
//			continue;
//		}
//		str[j] = str[i++];
//		j++;
//		//printf("C");
//	}
//	//i 는 지금 널문자의 위치에 있음
//	if (j > 0 && str[i - 1] == ' ') {
//		str[j-1] = '\0';
//	}
//	else {
//		str[j] = '\0';
//	}
//}

int main(void) {
	
	//************6주차 2번************
	//char word[100];
	//int n = 0;
	//FILE* fp = fopen("harry.txt", "r");

	//struct term {
	//	int count;
	//	struct term* next;
	//	char* words;
	//};
	//typedef struct term Term;
	//Term* head = NULL;
	//Term* front = head; Term* back = NULL;
	//while (fscanf(fp, "%s", word) != EOF) {
	//	front = head; back = NULL;
	//	Term* t = (Term*)malloc(sizeof(Term));
	//	while (front != NULL && strcmp(front->words, word) < 0) {
	//		back = front;
	//		front = front->next;
	//	}
	//	//front = NULL 이거나 사전식으로 같거나 작은 상태
	//	if (front == NULL) {
	//		if (back == NULL) {//노드 한개도 없음
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			head = t;
	//			n++;
	//		}
	//		else {
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//	//front != NULL인 상태, 뭐든 가리키고 있음
	//	//동일 문자일때
	//	else if (strcmp(front->words, word) == 0) {
	//		front->count++;
	//	}
	//	//사전식으로 내가 더 작은 경우
	//	else if (strcmp(front->words, word) > 0) {
	//		//제일 앞에 삽입될 경우
	//		if (back == NULL) {
	//			t->next = head;
	//			t->words = strdup(word);
	//			t->count = 1;
	//			head = t;
	//			n++;
	//		}
	//		//중간에 삽입될 경우
	//		else {
	//			t->next = front;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//}

	//front = head; back = NULL; n = 0;
	//while (front != NULL) {
	//	if (front->count <= 10) {
	//		if (back == NULL) {
	//			front = front->next;
	//		}
	//		else {
	//			back->next = front->next;
	//			front = front->next;
	//		}
	//	}
	//	else {
	//		back = front;
	//		front = front->next;
	//		n++;
	//	}
	//}

	//Term* p = head;
	//while (p != NULL) {
	//	printf("%s: %d\n", p->words, p->count);
	//	p = p->next;
	//}
	//printf("%d", n);



	//************6주차 1번************
	//char word[100];
	//int n = 0;
	//FILE* fp = fopen("harry.txt", "r");

	//struct term {
	//	int count;
	//	struct term* next;
	//	char* words;
	//};
	//typedef struct term Term;
	//Term* head = NULL;
	//Term* front = head; Term* back = NULL;
	//while (fscanf(fp, "%s", word) != EOF) {
	//	front = head; back = NULL;
	//	Term* t = (Term*)malloc(sizeof(Term));
	//	while (front != NULL && strcmp(front->words, word) < 0) {
	//		back = front;
	//		front = front->next;
	//	}
	//	//front = NULL 이거나 사전식으로 같거나 작은 상태
	//	if (front == NULL) {
	//		if (back == NULL) {//노드 한개도 없음
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			head = t;
	//			n++;
	//		}
	//		else {
	//			t->next = NULL;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//	//front != NULL인 상태, 뭐든 가리키고 있음
	//	//동일 문자일때
	//	else if (strcmp(front->words, word) == 0) {
	//		front->count++;
	//	}
	//	//사전식으로 내가 더 작은 경우
	//	else if (strcmp(front->words, word) > 0) {
	//		//제일 앞에 삽입될 경우
	//		if (back == NULL) {
	//			t->next = head;
	//			t->words = strdup(word);
	//			t->count = 1;
	//			head = t;
	//			n++;
	//		}
	//		//중간에 삽입될 경우
	//		else {
	//			t->next = front;
	//			t->count = 1;
	//			t->words = strdup(word);
	//			back->next = t;
	//			n++;
	//		}
	//	}
	//}
	//Term* p = head;
	//while (p != NULL) {
	//	printf("%s: %d\n", p->words, p->count);
	//	p = p->next;
	//}
	//printf("%d", n);

//***********5주차 3번*********
	//FILE* fp = fopen("board.txt", "r");
	//int num = 0;
	//fscanf(fp, "%d ", &num);
	//printf("%d\n", num);

	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		fscanf(fp, "%d ", &data[i][j]);
	//	}
	//}
	//
	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		if (data[i][j] == 0)
	//			continue;
	//		//check if board[i][j] is an end of 5-consecutive smae stone
	//		if (check(i, j, num)) {//오목이 만족된다면
	//			if (data[i][j] == 1) {
	//				printf("black");
	//			}
	//			else {
	//				printf("white");
	//			}
	//			return 0;
	//		}
	//	}
	//}
	//printf("not finished");
	//return 0;

;

//***********5주차 2번*********
	/*int num = 0;
	int data[200][200];
	FILE* fp = fopen("data.mat", "r");
	fscanf(fp, "%d ", &num);
	printf("%d\n", num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			fscanf(fp, "%d", &data[i][j]);
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	
	while (1) {
		char command[100];
		int ch = 0, j = 0;
		printf("$ ");
		while ((ch = getchar()) != '\n') {
			command[j++] = ch;
		}
		command[j] = '\0';

		if (strcmp(command, "show") == 0) {
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num; j++) {
					printf("%d ", data[i][j]);
				}
				printf("\n");
			}
		}
		else if (strcmp(command, "exit") == 0) {
			return 0;
		}
		else if (strcmp(strtok(command, " "), "slice") == 0) {
			int x = atoi(strtok(NULL, " "));
			int p = atoi(strtok(NULL, " "));
			int y = atoi(strtok(NULL, " "));
			int q = atoi(strtok(NULL, " "));

			for (int i = x; i < num; i += p) {
				for (int j = y; j < num; j += q) {
					printf("%d ", data[i][j]);
				}
				printf("\n");
			}
		}
	}*/

//***********5주차 1번*********
	//char str[300];
	//int count = 0;
	//int maxCount = 0, index = 0, maxIndex = 0;
	//scanf("%s", str);
	// /*모음 종류 a i u e o*/
	////1. 모음이 나옴 & count = 0 이면 그때부터 count++ & 인덱스 저장
	////2. 모음이 나옴 & coutn > 0 인경우 그냥 count++
	////3. 모음이 아니면서 count  >0 인경우 maxCount 와 비교하여 
	////더크면 maxCount에 count값과 maxIndex에 시작했던 인덱스를 넣음
	//for (int i = 0; i < strlen(str); i++) {
	//	//모음이 아닌경우(자음인경우)
	//	if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
	//		if (count == 0) {//자음 처음 등장
	//			index = i; count++;
	//		}
	//		//자음이 연속해서 등장하고 있는 경우
	//		else {
	//			count++;
	//		}
	//	}
	//	//모음인 경우-> count 값 따봐야 한다
	//	else {
	//		//자음이 연속해오고 있던 경우
	//		if (count > 0) {// maxCount와 비교
	//			if (count > maxCount) {
	//				maxCount = count;
	//				maxIndex = index;
	//				count = 0;
	//				//index = 0;
	//			}
	//			else {
	//				count = 0;
	//				//index = 0;
	//			}
	//		}
	//		//이전에도 모음이었던 경우
	//		else {
	//			//count = 0;//사실상 필요X
	//			//index = 0;//사실상 필요X
	//		}
	//	}
	//}
	//for (int i = maxIndex; i < maxIndex + maxCount; i++) {
	//	printf("%c", str[i]);
	//}

	//************4주차 3번************
	//main 함수위에 함수따로 선언되어 있음
	//FILE* fp = fopen("table.txt", "r");
	//char* str[20][20];
	//char line[1000];
	//int maxCol[20];
	//char* temp;
	//int i = 0;
	//int m = 0, n = 0; int max = 1000;
	//fscanf(fp, "%d %d ", &m, &n);
	//
	//for (int i = 0; i < m; i++) {
	//	fgets(line, max, fp);
	//	if (line[strlen(line) - 1] == '\n') {
	//		line[strlen(line) - 1] = '\0';
	//	}
	//	char* p = strtok(line, "&");
	//	str[i][0] = strdup(p);
	//	compress(str[i][0]);
	//	if (i == 0) { maxCol[0] = strlen(str[i][0]); }
	//	else if (strlen(str[i][0]) > maxCol[0]) {
	//		maxCol[0] = strlen(str[i][0]);
	//	}

	//	/*printf("%s ", str[i][0]);*/

	//	for (int j = 1; j < n; j++) {
	//		p = strtok(NULL, "&");
	//		str[i][j] = strdup(p);
	//		compress(str[i][j]);
	//		if (i == 0) { maxCol[j] = strlen(str[i][j]); }
	//		else if (strlen(str[i][j]) > maxCol[j]) {
	//			maxCol[j] = strlen(str[i][j]);
	//		}
	//	}
	//}
	//for (int i = 0; i < n; i++) {
	//	printf("%d 열의 최댓값: %d\n", i, maxCol[i]);
	//}
	//FILE* fp2 = fopen("output.txt", "w");

	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		fputs(str[i][j], fp2);
	//		for (int k = 0; k < (maxCol[j] - strlen(str[i][j])); k++) {
	//			fputs(" ", fp2);
	//		}
	//		fputs(" ", fp2);
	//	}
	//	fputs("\n", fp2);
	//}

	////************4주차 2번************
	//int num = 0;
	//FILE* fp = fopen("input.txt", "r");
	//fscanf(fp, "%d ", &num);
	//int data[20][20] = { 0 };
	//float avgRow[20]; float sdRow[20];
	//float avgCol[20]; float sdCol[20];

	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		fscanf(fp, "%d", &data[i][j]);
	//		printf("%d ", data[i][j]);
	//	}
	//	printf("\n");
	//}

	//for (int i = 0; i < num; i++) {
	//	float sumRow = 0; float sumCol = 0;
	//	for (int j = 0; j < num; j++) {
	//		sumRow += data[i][j];
	//		sumCol += data[j][i];
	//	}
	//	avgRow[i] = sumRow / num;
	//	avgCol[i] = sumCol / num;
	//	
	//	printf("%d 행의 평균: %.2lf, %d 열의 평균: %.2lf\n", i, avgRow[i], i, avgCol[i]);
	//}

	//for (int i = 0; i < num; i++) {
	//	float sdSumRow = 0; float sdSumCol = 0;
	//	for (int j = 0; j < num; j++) {
	//		sdSumRow += (avgRow[i] - data[i][j])* (avgRow[i] - data[i][j]);
	//		sdSumCol += (avgCol[i] - data[j][i])*(avgCol[i] - data[j][i]);
	//	}
	//	sdRow[i] = sqrt(sdSumRow / num);
	//	sdCol[i] = sqrt(sdSumCol / num);

	//	printf("%d 행의 표준편차: %.2lf, %d 열의 표준편차: %.2lf\n", i, sdRow[i], i, sdCol[i]);
	//}
	//

	////************4주차 1번************
	//int num = 0;
	//scanf("%d", &num);
	//int data[100];
	////입력 받아 배열에 저장
	//for (int i = 0; i < num; i++) {
	//	scanf("%d", &data[i]);
	//}

	////돌기
	//int count = 0;
	//for (int i = 0; i < num; i++) {
	//	for (int j = i; j < num; j++) {
	//		if (data[i] > data[j]) count++;
	//	}
	//}
	//printf("%d", count);

	//return 0;


	////************3주차 3번************
	//char* words[10000];
	//char* strs[10000];
	//int n = 0;
	//FILE* fp = fopen("shuffled_dict.txt", "r");
	//if (fp == NULL) {
	//	printf("open failed\n"); return 0;
	//}
	//int count = 0;
	//char line[500];
	//while ((fgets(line, MAX, fp) != NULL)) {
	//	if (line[strlen(line) - 1] == '\n') {
	//		line[strlen(line) - 1] = '\0';
	//	}
	//	if (strlen(line) <= 0) continue;//예외처리
	//	
	//	words[n] = strdup(strtok(line, "\t"));
	//	strs[n] = strdup(strtok(NULL, "\t"));
	//	//printf("%s %s\n", words[n ], strs[n]);
	//	n++;
	//}

	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = 0; j < n - 1 - i; j++) {
	//		if (strcmp(words[j], words[j + 1]) > 0) {
	//			char* temp;
	//			temp = words[j];
	//			words[j] = words[j+1];
	//			words[j + 1] = temp;

	//			temp = strs[j];
	//			strs[j] = strs[j + 1];
	//			strs[j + 1] = temp;
	//		}
	//	}
	//}
	//FILE* fp2 = fopen("sorted_dict.txt", "w");
	//for (int i = 0; i < n; i++) {
	//	fputs(words[i], fp2);
	//	fputs("\t", fp2);
	//	fputs(strs[i], fp2);
	//	fputs("\n", fp2);
	//}
	//return 0;

	////************3주차 2번************
	//int num = 0;
	//scanf("%d", &num);
	//int n = 0;
	//int ftemp = 0;
	//int btemp = 0;
	//int front[100];
	//int back[100];
	//for (int i = 0; i < num; i++) {
	//	scanf("%d %d", &front[i], &back[i]);
	//}

	////버블정렬
	//for (int i = 0; i < num - 1; i++) {
	//	for (int j = 0; j < num - 1 - i; j++) {
	//		if (front[j] > front[j + 1]) {
	//			int temp = 0;
	//			temp = front[j];
	//			front[j] = front[j + 1];
	//			front[j + 1] = temp;

	//			temp = back[j];
	//			back[j] = back[j + 1];
	//			back[j + 1] = temp;
	//		}
	//		else if (front[j] == front[j + 1]) {
	//			if (back[j] > back[j + 1]) {
	//				int temp = 0;
	//				temp = front[j];
	//				front[j] = front[j + 1];
	//				front[j + 1] = temp;

	//				temp = back[j];
	//				back[j] = back[j + 1];
	//				back[j + 1] = temp;
	//			}
	//		}
	//	}
	//}

	//for (int i = 0; i < num; i++) {
	//	printf("%d %d\n", front[i], back[i]);
	//}



	////************3주차 1번************
	//int num = 0;
	//int data[100];
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	scanf("%d", &data[i]);
	//}

	//int max = 0, maxIndex = 0;
	//for (int i = num - 1; i > 0; i--) {
	//	max = 0; maxIndex = 0;//다시 초기화 해줘야 한다
	//	for (int j = 0; j <= i; j++) {
	//		if (data[j] > max) { 
	//			max = data[j];
	//			maxIndex = j;
	//		}
	//	}
	//	int temp = data[i];
	//	//printf("data[%d]: %d\n", i, data[i]);
	//	data[i] = max;
	//	//printf("%d", data[i]);
	//	data[maxIndex] = temp;
	//}

	//for (int i = 0; i < num; i++) {
	//	printf("%d ", data[i]);
	//}


	////************2주차 3번************
//char* str[10000];
//int count[10000] = { 0 };
//int n = 0;
//char word[100];
//FILE* fp = fopen("harry.txt", "r");
//while (fscanf(fp, "%s ", word) != EOF) {
//	//중복 확인
//	bool duplicate = false;
//	for (int i = 0; i < n; i++) {
//		if (strcmp(str[i], word) == 0) {
//			duplicate = true;
//			count[i]++;
//			break;
//		}
//	}
//	if (duplicate) { continue; }
//
//
//	//insertion sort를 이용한 사전식 정렬
//	int j = n - 1;
//	while (j >= 0 && strcmp(str[j], word) > 0) {
//		str[j + 1] = str[j];
//		count[j + 1] = count[j];
//		j--;
//	}
//	//j = 0 이거나 word가 사전식으로 더 클때 멈춤
//	str[j + 1] = strdup(word);
//	count[j + 1] = 1;
//	n++;
//}
//for (int i = 0; i < n; i++) {
//	printf("%s: %d\n", str[i], count[i]);
//}
//printf("%d", n);


    ////**********2주차 2번************
	//char* str[10000];
	//int n = 0;
	//char word[100];
	//FILE* fp = fopen("harry.txt", "r");
	//while (fscanf(fp, "%s", word) != EOF) {
	//	//중복 확인
	//	bool duplicate = false;
	//	for (int i = 0; i < n; i++) {
	//		if (strcmp(str[i], word) == 0) { 
	//			duplicate = true;
	//			break;
	//		}
	//	}
	//	if (duplicate) { continue; }
	//	
	//	int j = n - 1;
	//	while (j > 0 && strcmp(str[j], word) > 0) {
	//		str[j + 1] = str[j];
	//		j--;
	//	}
	//	//j = 0 이거나 word가 사전식으로 더 클때 멈춤
	//	str[j + 1] = strdup(word);
	//	n++;
	//}
	//printf("%d", n);
	//for (int i = 0; i < n; i++) {
	//	printf("%s\n", str[i]);
	//}


	////************2주차 1번************

	//char str1[100];
	//char str2[100];

	//scanf("%s", str1);
 //   scanf("%s", str2);
	//bool isSame = false;
	////서로 서로 2중 for문을 2개 사용하여 돌아준다
	//for (int i = 0; i < strlen(str1); i++) {
	//	isSame = false;
	//	for (int j = 0; j < strlen(str2); j++) {
	//		if (str1[i] == str2[j]) { isSame = true; break; }
	//	}
	//	if (!isSame) { printf("no"); return 0; }
	//}

	//for (int i = 0; i < strlen(str2); i++) {
	//	isSame = false;
	//	for (int j = 0; j < strlen(str1); j++) {
	//		if (str2[i] == str1[j]) { isSame = true; break; }
	//	}
	//	if (!isSame) { printf("no"); return 0; }
	//}

	//printf("yes");

	//아래는 잘못된 풀이, 중복 제거할 필요도 없고, 새 배열을 굳이 안만들어도
	//됨!!!!!!!!!!!!!!!!!11

	//char temp[100];
	////초기 배열의 temp 는 쓰레기값이다. 사용하지 않도록 주의!!!!!!!!!!
	////printf("temp 초기의 length : %d", strlen(temp));
	//bool isSame = false;

	////동일한 문자집합으로 구성되었는지 검사
	////1. 첫번째 문자열의 각 원소를 중복을 제거하여 새로운 배열에 삽입
	////2. 두번째 문자열을 돌면서 원소가 새로운 배열에 존재하는지 확인

	//scanf("%s", str1);
	//scanf("%s", str2);

	////중복 제거하여 새 배열에 삽입
	//int k = 0;
	//for (int i = 0; i < strlen(str1); i++) {
	//	for (int j = 0; j < k; j++) {
	//		if (str1[i] == temp[j]) {
	//			isSame = true; break;
	//		}
	//	}
	//	if (!isSame) {
	//		temp[k++] = str1[i];
	//	}
	//	//isSame 이 true 일 수도 있음
	//	isSame = false;
	//}

	//for (int i = 0; i < k; i++) {
	//	//문자 출력할때 "%d" 말고 "%c"써야함!!!!!!!!!!!!
	//	printf("%c ", temp[i]);
	//}

	//for (int i = 0; i < strlen(str2); i++) {
	//	isSame = false;
	//	printf("strlen(str2) ");
	//	for (int j = 0; j < k; j++) {
	//		if (str2[i] == temp[j]) {
	//			isSame = true; break;
	//		}
	//	}
	//	if (!isSame) { printf("no"); return 0; }
	//}

	//printf("yes");


	////************1주차 7번************
	////버블 소트사용, 길이 먼저 비교, 길이 같으면 사전식 순서 비교
	//int num = 0;
	//char line[100];
	//char* str[30];
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	scanf("%s", line);//포인터에 저장
	//	str[i] = strdup(line);//!!!읽어와서 저장할때 strdup사용
	//}

	//for (int i = 0; i < num - 1 ; i++) {
	//	for (int j = 0; j < num - 1 - i; j++) {
	//		if (strlen(str[j]) > strlen(str[j + 1])) {
	//			char* temp;
	//			temp = str[j];
	//			str[j] = str[j + 1];
	//			str[j + 1] = temp;
	//		}
	//		else if (strlen(str[j]) == strlen(str[j + 1])) {
	//			if (strcmp(str[j], str[j + 1]) > 0) {
	//				char* temp;
	//				temp = str[j];
	//				str[j] = str[j + 1];
	//				str[j + 1] = temp;
	//			}
	//		}
	//	}
	//}
	//for (int i = 0; i < num; i++) {
	//	printf("%s\n", str[i]);
	//}

	//************1주차 5번************
	////오름차순 & 중복제거
	////1. 오름차순
	////2. 중복되지 않은 값을 새 배열에 추가
	//int num = 0; int data1[200]; int data2[200];
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	scanf("%d", &data1[i]);
	//}
	////오름차순 정렬
	//for (int i = 0; i < num - 1; i++) {
	//	for (int j = 0; j < num - 1 - i; j++) {
	//		if (data1[j] > data1[j + 1]) {
	//			int temp = data1[j];
	//			data1[j] = data1[j + 1];
	//			data1[j + 1] = temp;
	//		}
	//	}
	//}

	////for (int i = 0; i < num; i++) {
	////	  printf("%d ", data1[i]);
	////}

	////중복 제거
	////1. 기존 배열을 돌면서 그 값이 새 배열에 있는지 확인(2중 for문)
	////2. 없으며 새 배열에 추가, 있으면 기존 배열의 다음 원소로 이동
	//int k = 0; bool isSame = false;
	//for (int i = 0; i < num; i++) {
	//	//새 배열에 기존 배열의 원소가 존재하는지 검사
	//	for (int j = 0; j < k; j++) {
	//		if (data1[i] == data2[j]) {
	//			isSame = true; break;
	//		}
	//	}
	//	//새배열에 기존 원소가 존재하지 않으면 새 배열에 추가
	//	if(!isSame) {
	//		data2[k++] = data1[i];
	//	}
	//	//isSame 이 true 일 수도 있으므로 반드시 원래의 false값으로 바꿔줘야 한다
	//	isSame = false;
	//}
	//
	//printf("%d: ", k);
	//for (int i = 0; i < k;i++) {
	//	printf("%d ", data2[i]);
	//}








	//************1주차 4번************
	//int num = 0; int data[200]; int min = 0; int compare;
	//int minNum = 0;
	//scanf("%d", &num);
	//
	////입력받은 순서대로 배열에 저장
	//for (int i = 0; i < num; i++) {
	// scanf("%d", &data[i]);
	//}
	//scanf("%d", &compare);

	////절댓값 비교 => 배열 원소값에서 compare 뺀 값을 절댓값으로
	//for (int i = 0; i < num; i++) {
	// //차이를 절댓값으로 만듦
	// int temp = data[i] - compare;
	// if (temp < 0) temp = temp * -1;

	// if (i == 0) {
	// min = temp; minNum = data[i];
	// }
	// else {
	// if (temp < min) { min = temp; minNum = data[i]; }
	// }
	//}

	//printf("%d", minNum);


	//************1주차 3번************
//int data[100];
//int n = 0;
//int temp = 0;
//while (1) {
//	scanf("%d", &temp);
//	if (temp == -1) { return 0; }
//	//중복 검사
//	bool duplicate = false;
//	for (int i = 0; i < n; i++) {
//		if (data[i] == temp) {
//			printf("duplicate\n");
//			duplicate = true;
//			break;
//		}
//	}
//	if (duplicate) { continue; }
//
//	int j = n - 1;
//	while (j >= 0 && data[j] > temp) {
//		data[j + 1] = data[j];
//		j--;
//	}
//	data[j + 1] = temp;
//	n++;
//	for (int i = 0; i < n;i++) {
//		printf("%d ", data[i]);
//	}
//	printf("\n");
}



	//************1주차 2번************
	//int num = 0;
	//int data[100];
	//int min1 = 0, min2 = 0;
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	// scanf("%d", &data[i]);
	// //i = 0 일때 => 비교x
	// if (i == 0) { min1 = data[i]; min2 = data[i]; }
	// //먼저 가장 작은값과 비교 -> 그다음 작은 값과 비교
	// //1. 가장 작은값보다 작을때 => min1을 min2로 옮기고 min1자리에 넣음
	// else {
	// if (data[i] < min1) {
	// min2 = min1;
	// min1 = data[i];
	// }
	// else if (data[i] < min2) {
	// min2 = data[i];
	// }
	// }
	//}
	//printf("%d %d", min1, min2);



	/*************1주차 1번************
	int num = 0;
	scanf("%d", &num);

	while (1) {
	if (num < 2) {
	printf("0"); break;
	}
	else {
	num = num / 2;
	printf("%d ", num);
	}
	}

	return 0;*/
}