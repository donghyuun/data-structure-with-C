#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "string_tools.h"
#include <windows.h>

#define NUM_CHARS 256// 2^8 = 256
#define SIZE_INDEX_TABLE 100
#define BUFFER_LENGTH 200

/******여기서만 호출되는 애들********/
Artist* artist_directory[NUM_CHARS];
SNode* index_directory[SIZE_INDEX_TABLE]; 
int num_index = 0;

Artist* find_artist(char* name);
void insert_node(Artist* ptr_artist, SNode* ptr_snode);
void print_song(Song* ptr_song);
void print_artist(Artist* p);
SNode* find_snode(Artist* ptr_artist, char* title);
void insert_to_index_directory(Song* ptr_song);
void save_artist(Artist* p, FILE* fp);
void save_song(Song* ptr_song, FILE* fp);
void destroy_song(Song* ptr_song);
void remove_snode(Artist* ptr_artist, SNode* ptr_snode);

void initialize()
{
	for (int i = 0; i < NUM_CHARS; i++) {
		artist_directory[i] = NULL;
	} 
	for (int i = 0; i < SIZE_INDEX_TABLE; i++) {
		index_directory[i] = NULL;
	}
}

void load(FILE* fp) {
	char buffer[BUFFER_LENGTH];
	char* name, * title, * path;

	while (1) {//무한 루프
		if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)//라인단위로 입력받음
			break;//데이터의 끝에 도달함

		name = strtok(buffer, "#");
		if (strcmp(name, " ") == 0) //이름이 존재하지 않는다
			name = NULL;
		else
			name = strdup(name);

		title = strtok(NULL, "#");
		if (strcmp(title, " ") == 0) //이름이 존재하지 않는다
			title = NULL;
		else
			title = strdup(title);

		path = strtok(NULL, "#");
		if (strcmp(path, " ") == 0) //이름이 존재하지 않는다
			path = NULL;
		else
			path = strdup(path);
		add_song(name, title, path);
	}
}

void search_song(char* artist, char* title) {
	Artist* ptr_artist = find_artist(artist);
	if (ptr_artist == NULL) {
		printf("No such artist exists.\n");
		return;
	}

	SNode* ptr_snode = find_snode(ptr_artist, title);

	if (ptr_snode != NULL) {
		printf("Found:\n");
		print_song(ptr_snode->song);
	}
	else {
		printf("No such song exists.\n");
		return;
	}
};

SNode* find_snode(Artist* ptr_artist, char* title) {
	SNode* ptr_snode = ptr_artist->head;
	while (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) < 0)//사전식으로 정렬했으므로
		ptr_snode = ptr_snode->next;

	if (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) == 0) {
		return ptr_snode;
	}
	else {
		return NULL;
	}
}

void search_song(char* artist) {
	Artist* ptr_artist = find_artist(artist);
	if (ptr_artist == NULL) {
		printf("No such artist exists.\n");
		return;
	}
	printf("Found:\n");
	print_artist(ptr_artist);

}
Artist* create_artist_instance(char* name) {
	Artist* ptr_artist = (Artist*)malloc(sizeof(Artist));
	ptr_artist->name = name;
	ptr_artist->head = NULL;
	ptr_artist->tail = NULL;
	ptr_artist->next = NULL;

	return ptr_artist;
}

Artist* add_artist(char* name) {
	Artist* ptr_artist = create_artist_instance(name);

	//artist노드를 삽입할 연결리스트의 첫번째 주소
	Artist* p = artist_directory[(unsigned char)name[0]];// first node
	Artist* q = NULL;

	while (p != NULL && strcmp(p->name, name) < 0) {
		//단일 연결리스트 이므로
		q = p;
		p = p->next;
	}
	if (p == NULL && q == NULL) {//노드가 한개도 없는 경우
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else if (q == NULL) {//노드가 한개 이상 존재하면서 맨 앞에 삽입
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else { //일반적인 경우, q 다음에 삽입
		ptr_artist->next = p;
		q->next = ptr_artist;
	}
	//추가된 artist를 가리키는 포인터 return, add_song에 사용됨
	return ptr_artist;
}

Song* create_song_instance(Artist* ptr_artist, char* title, char* path) {
	Song* ptr_song = (Song*)malloc(sizeof(Song));
	ptr_song->artist = ptr_artist;
	ptr_song->title = title;
	ptr_song->path = path;
	ptr_song->index = num_index;//노래들을 구분하기 위한 목적
	num_index++;

	return ptr_song;
}

void add_song(char* artist, char* title, char* path) {
	// find if the artist already exists
	// return NULL if not
	Artist* ptr_artist = find_artist(artist);
	if (ptr_artist == NULL) {
		//새로 artist객체 만들고, 주소 return(노래 추가해야하므로)
		ptr_artist = add_artist(artist);
	}
	//노래객체 생성하여 artist 가리키도록하고, snode 생성하여 그 노래객체를 가리키도록(ppt그림 참고)
	Song* ptr_song = create_song_instance(ptr_artist, title, path);//노래객체 생성, 해당 artist를 가리킴
	SNode* ptr_snode = (SNode*)malloc(sizeof(SNode));//노래객체를 가리키는 snode 생성
	ptr_snode->song = ptr_song;
	ptr_snode->next = NULL;
	ptr_snode->prev = NULL;

	//aritst가 가진 이중연결리스트에 snode 삽입
	insert_node(ptr_artist, ptr_snode);
	insert_to_index_directory(ptr_song);
}

void insert_to_index_directory(Song* ptr_song) {//ptr_song에 정보들 다 들어있으므로 배열에 추가만 하면 됨
	SNode* ptr_snode = (SNode*)malloc(sizeof(SNode));//노래객체를 가리키는 snode 생성
	ptr_snode->song = ptr_song;
	ptr_snode->next = NULL;
	ptr_snode->prev = NULL; //단방향이므로 prev 필드는 사용X

	int index = ptr_song->index % SIZE_INDEX_TABLE;// index는 0부터 99까지 존재

	//song 을 가리키고 있는 snode를 index_directory[index] 의 단방향 연결리스트에 삽입
	SNode* p = index_directory[index];
	SNode* q = NULL;//단방향이므로
	while (p != NULL && strcmp(p->song->title, ptr_song->title) < 0) {
		q = p;
		p = p->next;
	}
	if (q == NULL) {//맨 앞에 삽입
		if (p == NULL) {
			index_directory[index] = ptr_snode;
		}
		else {
			ptr_snode->next = index_directory[index];//index_directory[index] = p
			index_directory[index] = ptr_snode;
		}

	}
	else if(p==NULL){//맨 뒤에 삽입(q 다음)
		q->next = ptr_snode;
	}
	else {//중간 삽입
		ptr_snode->next = p;
		q->next = ptr_snode;
	}
}

void insert_node(Artist* ptr_artist, SNode* ptr_snode) {
	SNode* p = ptr_artist->head;
	while (p != NULL && strcmp(p->song->title, ptr_snode->song->title) < 0) {
		p = p->next;//"이중연결리스트"이기 때문에 두개의 포인터(p, q)를 쓸필요가 없다. p만 쓰면 됨!!!!
	}
	//1. empty 2. 맨 앞 삽입 3. 맨 뒤 삽입 4. 중간 삽입
	//empty
	if (ptr_artist->head == NULL) {
		ptr_artist->head = ptr_snode;
		ptr_artist->tail = ptr_snode;
	}
	//맨 앞 삽입
	else if (p == ptr_artist->head) {
		ptr_snode->next = ptr_artist->head;
		ptr_artist->head->prev = ptr_snode;
		ptr_artist->head = ptr_snode;
	}
	//맨 뒤 삽입
	else if (p == NULL) {//at the end
		ptr_snode->prev = ptr_artist->tail;
		ptr_artist->tail->next = ptr_snode;
		ptr_artist->tail = ptr_snode;
	}
	//중간 삽입(p 앞에)
	else {
		ptr_snode->next = p;
		ptr_snode->prev = p->prev;
		p->prev->next = ptr_snode;
		p->prev = ptr_snode;
	}
}

Artist* find_artist(char* name) {
	//first artist with initial name[0]
	Artist* p = artist_directory[(unsigned char)name[0]];
	//이름이 같거나 더 큰 Artist를 만난 경우 멈춤
	while (p != NULL && strcmp(p->name, name) < 0) {
		p = p->next;
	}
	//내가 찾는 사람과 이름이 같은경우
	if (p != NULL && strcmp(p->name, name) == 0) { return p; }
	//끝까지 가거나 나보다 더 큰 사람을 만난 경우
	else { return NULL; }
}

//현재 저장된 모든 아티스트와 노래를 출력
void status() {
	for (int i = 0; i < NUM_CHARS; i++) {
		Artist* p = artist_directory[i];
		while (p != NULL) {
			print_artist(p);
			p = p->next;
		}
	}
}

void print_artist(Artist* p) {
	printf("%s\n", p->name);
	SNode* ptr_snode = p->head;
	while (ptr_snode != NULL) {
		print_song(ptr_snode->song);
		ptr_snode = ptr_snode->next;
	}
}

void print_song(Song* ptr_song) {
	printf("    %d: %s, %s\n", ptr_song->index, ptr_song->title, ptr_song->path);
}

SNode* find_song(int index) {
	SNode* ptr_snode = index_directory[index % SIZE_INDEX_TABLE];
	while (ptr_snode != NULL && ptr_snode->song->index != index) {
		ptr_snode = ptr_snode->next;
	}
	return ptr_snode;
}

void play(int index) {
	SNode* ptr_snode = find_song(index);
	if (ptr_snode == NULL) {
		printf("No such song exists.\n");
	}

	printf("Found the song: %s\n", ptr_snode->song->title);

	//파일으루 쉘 상에서 실행, 더블클릭과 같은것
	ShellExecuteA(GetDesktopWindow(), "open", ptr_snode->song->path, NULL, NULL, SW_SHOW);
}

void save(FILE *fp) {
	for (int i = 0; i < NUM_CHARS; i++) {
		Artist* p = artist_directory[i];
		while (p != NULL) {
			save_artist(p, fp);
			p = p->next;
		}
	}
}

void save_artist(Artist* p, FILE*fp) {
	SNode* ptr_snode = p->head;
	while (ptr_snode != NULL) {
		save_song(ptr_snode->song, fp);
		ptr_snode = ptr_snode->next;
	}
}

void save_song(Song* ptr_song, FILE* fp) {
	if (ptr_song->artist != NULL) {
		fprintf(fp, "%s#", ptr_song->artist->name);
	}
	else
		fprintf(fp, " #");
	if (ptr_song->title != NULL) 
		fprintf(fp, "%s#", ptr_song->title);
	else 
		fprintf(fp, " #");//path 존재하지 않는 경우 공백으로
	if (ptr_song->path != NULL) 
		fprintf(fp, "%s#\n", ptr_song->path);
	else
		fprintf(fp, " #\n");//path 존재하지 않는 경우 공백으로
}

void remove(int index) {
	//index에 해당하는 song을 찾는다
	SNode* q = NULL;//previous node 
	SNode* p = index_directory[index % SIZE_INDEX_TABLE]; //head node
	while (p != NULL && p->song->index != index) {
		q = p;
		p = p->next;
	}
	if (p == NULL) {//snode 가 하나도 없거나, 끝까지 갔음에도 못찾은 경우
		printf("No such song exists.\n");
		return;
	}
	//하나의 song을 삭제할때 artist 에 달린 양방향 연결리스트의 snode와,
	//inddex_directory[i]에 달린 단방향 연결리스트의 snode 도 삭제해야 한다.
	//순서: index_directory[i]의 snode, artist의 snode, song 순으로 삭제

	//1.index_directory[i]의 song에 해당하는 snode 삭제
	Song* ptr_song = p->song;
	if (q == NULL) {//첫번째 노드 삭제
		index_directory[index % SIZE_INDEX_TABLE] = p->next;
		//p = p->next; <- 이렇게 쓰면 안됨, index_directory[index % SIZE_INDEX_TABLE] != p, 가지는 값만 같을 뿐
	}
	else {//중간 노드(q다음 노드)삭제
		q->next = p->next;// q->next = q->next->next;
	}
	free(p);

	//2. ptr_artist 의 이중연결리스트에서 snode 삭제
	//ptr_artist 의 이중연결리스트에서 snode를 찾는다
	Artist* ptr_artist = ptr_song->artist;
	SNode *ptr_snode = find_snode(ptr_artist, ptr_song->title);
	if (ptr_snode == NULL) {
		printf("Not found snode - something wrong(일어나서는 안되는 상황)\n");
		return;
	}
	remove_snode(ptr_artist, ptr_snode);

	//3.song 객체 삭제
	destroy_song(ptr_song);
}


void destroy_song(Song* ptr_song) {
	if (ptr_song->title != NULL)
		free(ptr_song->title);
	if (ptr_song->path != NULL)
		free(ptr_song->path);
	free(ptr_song);
}

//2. ptr_artist 의 이중연결리스트에서 snode 삭제
void remove_snode(Artist*ptr_artist, SNode* ptr_snode) {
	SNode* first = ptr_artist->head;
	SNode* last = ptr_artist->tail;
	if (first == ptr_snode && last == ptr_snode) {//노드 한개 존재, 맨 앞 노드 삭제
		ptr_artist->head = NULL;
		ptr_artist->tail = NULL;
	}
	else if (first == ptr_snode) {//노드 2개 이상 존재, 맨 앞 노드 삭제
		ptr_artist->head = first->next;
		first->next->prev = NULL;
	}
	else if (last == ptr_snode) {// 노드 2개 이상 존재, 맨 뒤 노드 삭제
		ptr_artist->tail = last->prev;
		last->prev->next = NULL;

	}
	else {//중간 노드 삭제
		ptr_snode->prev->next = ptr_snode->next;
		ptr_snode->next->prev = ptr_snode->prev;
	}
	free(ptr_snode);
}