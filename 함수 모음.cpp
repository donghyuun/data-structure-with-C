#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>//isspace, atoi...
#include <stdlib.h>
#include <math.h>
//strdup 꼭 까먹지 말자

//*************내장 함수 사용법*************
//fscanf, 단어 하나씩 읽어올때, 문자는 %s 를 %c 로 바꾸면 됨
char* str[100];
char line[100];
FILE* fp = fopen("harry.txt", "r");
while (fscanf(fp, "%s", word) != EOF) {
	str[i++] = strdup(word);
}
//fprint, 잘 쓸일 없음, but 파일에 넣을 수 있는 수식 다양
//대부분은 fputs 만으로 처리가능, fputs을 먼저쓰자
fprintf(fp, "%d", 10);
fprintf(fp, " ");
fprintf(fp, "%s", table[i][j]);

//fputs, 문자열 저장
// ex) 저장된 파일에서는 한 줄에 하나의 단어와 
//그 단어에 대한 설명을 탭 문자로 구분하여 저장
//예1)
FILE * fp2 = fopen("sorted_dict.txt", "w");
for (int i = 0; i < n; i++) {
	fputs(words[i], fp2);
	fputs("\t", fp2);
	fputs(strs[i], fp2);
	fputs("\n", fp2);
}
//예2)
FILE* fp2 = fopen("output.txt", "w");

for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		fputs(str[i][j], fp2);
		for (int k = 0; k < (maxCol[j] - strlen(str[i][j])); k++) {
			fputs(" ", fp2);
		}
		fputs(" ", fp2);
	}
	fputs("\n", fp2);
}
//fgets, 문장 저장
//개행문자('\n')까지 읽으므로 마지막 줄 제외하고 개행문자 제거
while (fgets(line, max, fp) != NULL) {
	if (line[strlen(line) - 1] == '\n') {
		line[strlen(line) - 1] = '\0';
	}
	printf("%s\n", line);
}

//getchar(), 공백 포함하여 문자열 입력받기(프롬프트 창에서)
while (1) {
	char command[100];
	int ch = 0, j = 0;
	while ((ch = getchar()) != '\n') {
		command[j++] = ch;
	}
	command[j] = '\0';

	printf("%s\n", command);
}
//atoi, 문자를 숫자로 바꿔준다
//"slice 0 1 1 2" 문자열이 command 에 들어있을 때
else if (strcmp(strtok(command, " "), "slice") == 0) {
int x = atoi(strtok(NULL, " "));
int p = atoi(strtok(NULL, " "));
int y = atoi(strtok(NULL, " "));
int q = atoi(strtok(NULL, " "));
		}
//*****************버블 정렬******************
//문자열을 숫자배열로 바꾸면 숫자배열 정렬 가능

//뒤에서부터 비교하는 버블소트
void str_bsort1(char s[]) {
	for (int i = strlen(s) - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (s[j] > s[j + 1]) {
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}

//앞에서부터 비교하는 버블소트(그냥 이거 쓰자)
void str_bsort2(char s[]) {
	for (int i = 0; i < strlen(s) - 1; i++) {
		for (int j = 0; j < strlen(s) - 1 - i; j++) {
			if (s[j] > s[j + 1]) {
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}

void num_bsort(int data[], num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (data[j] > data[j + 1]) {
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}


//****************중복 제거*******************

//문자열 문자 중복 제거(압축 방법 사용)
void str_compress(char s[]) {
	int j = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			//i = 0 이거나 i != 0 이면서 s[i] != s[i - 1] => 생존(남김)
			s[j++] = s[i];//앞쪽으로 압축
		}
	}//여기까지만 하면 앞축된 문자들뒤로 원래있던 문자들도 존재

	//따라서 문자열의 끝을 알리는 '\0'를 넣어줘야 함
	s[j] = '\0';
}
//문자열의 사전식 정렬 & 중복제거 
//=> str_bsort2 & str_compress 방법 함께 사용

//숫자 배열 중복 제거
//1. 기존 배열(data1)을 돌면서 그 값이 새 배열에 있는지 확인(2중 for문)
//2. 없으면 새 배열(data2)에 추가, 있으면 기존 배열의 다음 원소로 이동
void num_compress(int data1[], int data2[], int num) {
	int k = 0; bool isSame = false;
	for (int i = 0; i < num; i++) {
		//새 배열에 기존 배열의 원소가 존재하는지 검사
		for (int j = 0; j < k; j++) {
			if (data1[i] == data2[j]) {
				isSame = true; break;
			}
		}
		//새배열에 기존 원소가 존재하지 않으면 새 배열에 추가
		if (!isSame) {
			data2[k++] = data1[i];
		}
		//isSame 이 true 일 수도 있으므로 반드시 원래의 false값으로 바꿔줘야 한다
		isSame = false;
	}
}

//*********문자열(문자열 포인터 배열X)의 문자의 사전식 정렬 & 중복제거 *********
//=> bsort & compress 방법 함께 사용

//**********숫자 배열의 중복 검사 & insertion sort******
int data[100];
int n = 0;
int temp = 0;
while (1) {
	scanf("%d", &temp);
	if (temp == -1) { return 0; }
	//중복 검사
	bool duplicate = false;
	for (int i = 0; i < n; i++) {
		if (data[i] == temp) {
			printf("duplicate\n");
			duplicate = true;
			break;
		}
	}
	if (duplicate) { continue; }

	int j = n - 1;
	while (j >= 0 && data[j] > temp) {
		data[j + 1] = data[j];
		j--;
	}
	data[j + 1] = temp;
	n++;
	for (int i = 0; i < n;i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
}
//*********문자열의 불필요한 공백 제거(압축 방법 사용)************
//기존의 문자열의 앞으로 앞축시킨다, 새 배열을 만들어서 하지 않는다
//맨 앞, 맨 뒤의 공백과 중간에 2개이상에 공백이 있을 경우 공백제거
void compress(char* str) {
	/*지역변수를 사용해서 새 배열을 만들고 그 배열을 리턴할 순 없음
	char tmp[1000];
	return tmp;*/
	int i = 0; int j = 0;
	while (str[i] != '\0') {//NULL('\0') 문자 만나면 멈춤
		//제일 앞의 문자가 공백일때
		if (i == 0 && str[i] == ' ') {
			i++;
			//printf("A");
			continue;
		}
		//앞이 공백이면서 자신도 공백일때
		else if (str[i - 1] == ' ' && str[i] == ' ') {
			//자기 뒤의 문자 앞으로 가져옴<--XXXXX!!!!
			//그냥 저장을 안하면 됨
			i++;
			//printf("B");
			continue;
		}
		str[j] = str[i++];
		j++;
		//printf("C");
	}
	//i 는 지금 널문자의 위치에 있음
	if (j > 0 && str[i - 1] == ' ') {
		str[j - 1] = '\0';
	}
	else {
		str[j] = '\0';
	}
}


//************포인터 배열**************

//문자열 읽어오면서 동시에 중복확인 & 사전식정렬(insertion sort)사용
//insertion sort는 숫자에도 사용될 수 있음
char* str[10000];
int n = 0;
char word[100];
FILE* fp = fopen("harry.txt", "r");
while (fscanf(fp, "%s", word) != EOF) {
	//중복 확인
	bool duplicate = false;
	for (int i = 0; i < n; i++) {
		if (strcmp(str[i], word) == 0) {
			duplicate = true;
			break;
		}
	}
	if (duplicate) { continue; }

	int j = n - 1;
	while (j >= 0 && strcmp(str[j], word) > 0) {
		str[j + 1] = str[j];
		j--;
	}
	//j = 0 이거나 word가 사전식으로 더 클때 멈춤
	str[j + 1] = strdup(word);//strdup필수!!
	n++;
}
}
//*********숫자 배열에 중복 안되게 숫자 하나씩 삽입*******
//=>배열에 해당 숫자가 이미 존재하는지 확인하고 
//없으면 insertion sort or 제일 뒤에 넣고 버블소트 돌림

//insertion sort 하기 어려워 보이는건 빠르게 버블소트 사용하자

//***********가장 큰 값을 선택해 맨 뒤의 원소와 교환하는 정렬 방법*******
//for 문 설정 일반적이지 않음 참고
int num = 0;
int data[100];
scanf("%d", &num);
for (int i = 0; i < num; i++) {
	scanf("%d", &data[i]);
}

int max = 0, maxIndex = 0;
for (int i = num - 1; i > 0; i--) {
	max = 0; maxIndex = 0;//다시 초기화 해줘야 한다
	for (int j = 0; j <= i; j++) {
		if (data[j] > max) {
			max = data[j];
			maxIndex = j;
		}
	}
	int temp = data[i];
	//printf("data[%d]: %d\n", i, data[i]);
	data[i] = max;
	//printf("%d", data[i]);
	data[maxIndex] = temp;
}
