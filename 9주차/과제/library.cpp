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

/******���⼭�� ȣ��Ǵ� �ֵ�********/
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

	while (1) {//���� ����
		if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)//���δ����� �Է¹���
			break;//�������� ���� ������

		name = strtok(buffer, "#");
		if (strcmp(name, " ") == 0) //�̸��� �������� �ʴ´�
			name = NULL;
		else
			name = strdup(name);

		title = strtok(NULL, "#");
		if (strcmp(title, " ") == 0) //�̸��� �������� �ʴ´�
			title = NULL;
		else
			title = strdup(title);

		path = strtok(NULL, "#");
		if (strcmp(path, " ") == 0) //�̸��� �������� �ʴ´�
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
	while (ptr_snode != NULL && strcmp(ptr_snode->song->title, title) < 0)//���������� ���������Ƿ�
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

	//artist��带 ������ ���Ḯ��Ʈ�� ù��° �ּ�
	Artist* p = artist_directory[(unsigned char)name[0]];// first node
	Artist* q = NULL;

	while (p != NULL && strcmp(p->name, name) < 0) {
		//���� ���Ḯ��Ʈ �̹Ƿ�
		q = p;
		p = p->next;
	}
	if (p == NULL && q == NULL) {//��尡 �Ѱ��� ���� ���
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else if (q == NULL) {//��尡 �Ѱ� �̻� �����ϸ鼭 �� �տ� ����
		artist_directory[(unsigned char)name[0]] = ptr_artist;
	}
	else { //�Ϲ����� ���, q ������ ����
		ptr_artist->next = p;
		q->next = ptr_artist;
	}
	//�߰��� artist�� ����Ű�� ������ return, add_song�� ����
	return ptr_artist;
}

Song* create_song_instance(Artist* ptr_artist, char* title, char* path) {
	Song* ptr_song = (Song*)malloc(sizeof(Song));
	ptr_song->artist = ptr_artist;
	ptr_song->title = title;
	ptr_song->path = path;
	ptr_song->index = num_index;//�뷡���� �����ϱ� ���� ����
	num_index++;

	return ptr_song;
}

void add_song(char* artist, char* title, char* path) {
	// find if the artist already exists
	// return NULL if not
	Artist* ptr_artist = find_artist(artist);
	if (ptr_artist == NULL) {
		//���� artist��ü �����, �ּ� return(�뷡 �߰��ؾ��ϹǷ�)
		ptr_artist = add_artist(artist);
	}
	//�뷡��ü �����Ͽ� artist ����Ű�����ϰ�, snode �����Ͽ� �� �뷡��ü�� ����Ű����(ppt�׸� ����)
	Song* ptr_song = create_song_instance(ptr_artist, title, path);//�뷡��ü ����, �ش� artist�� ����Ŵ
	SNode* ptr_snode = (SNode*)malloc(sizeof(SNode));//�뷡��ü�� ����Ű�� snode ����
	ptr_snode->song = ptr_song;
	ptr_snode->next = NULL;
	ptr_snode->prev = NULL;

	//aritst�� ���� ���߿��Ḯ��Ʈ�� snode ����
	insert_node(ptr_artist, ptr_snode);
	insert_to_index_directory(ptr_song);
}

void insert_to_index_directory(Song* ptr_song) {//ptr_song�� ������ �� ��������Ƿ� �迭�� �߰��� �ϸ� ��
	SNode* ptr_snode = (SNode*)malloc(sizeof(SNode));//�뷡��ü�� ����Ű�� snode ����
	ptr_snode->song = ptr_song;
	ptr_snode->next = NULL;
	ptr_snode->prev = NULL; //�ܹ����̹Ƿ� prev �ʵ�� ���X

	int index = ptr_song->index % SIZE_INDEX_TABLE;// index�� 0���� 99���� ����

	//song �� ����Ű�� �ִ� snode�� index_directory[index] �� �ܹ��� ���Ḯ��Ʈ�� ����
	SNode* p = index_directory[index];
	SNode* q = NULL;//�ܹ����̹Ƿ�
	while (p != NULL && strcmp(p->song->title, ptr_song->title) < 0) {
		q = p;
		p = p->next;
	}
	if (q == NULL) {//�� �տ� ����
		if (p == NULL) {
			index_directory[index] = ptr_snode;
		}
		else {
			ptr_snode->next = index_directory[index];//index_directory[index] = p
			index_directory[index] = ptr_snode;
		}

	}
	else if(p==NULL){//�� �ڿ� ����(q ����)
		q->next = ptr_snode;
	}
	else {//�߰� ����
		ptr_snode->next = p;
		q->next = ptr_snode;
	}
}

void insert_node(Artist* ptr_artist, SNode* ptr_snode) {
	SNode* p = ptr_artist->head;
	while (p != NULL && strcmp(p->song->title, ptr_snode->song->title) < 0) {
		p = p->next;//"���߿��Ḯ��Ʈ"�̱� ������ �ΰ��� ������(p, q)�� ���ʿ䰡 ����. p�� ���� ��!!!!
	}
	//1. empty 2. �� �� ���� 3. �� �� ���� 4. �߰� ����
	//empty
	if (ptr_artist->head == NULL) {
		ptr_artist->head = ptr_snode;
		ptr_artist->tail = ptr_snode;
	}
	//�� �� ����
	else if (p == ptr_artist->head) {
		ptr_snode->next = ptr_artist->head;
		ptr_artist->head->prev = ptr_snode;
		ptr_artist->head = ptr_snode;
	}
	//�� �� ����
	else if (p == NULL) {//at the end
		ptr_snode->prev = ptr_artist->tail;
		ptr_artist->tail->next = ptr_snode;
		ptr_artist->tail = ptr_snode;
	}
	//�߰� ����(p �տ�)
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
	//�̸��� ���ų� �� ū Artist�� ���� ��� ����
	while (p != NULL && strcmp(p->name, name) < 0) {
		p = p->next;
	}
	//���� ã�� ����� �̸��� �������
	if (p != NULL && strcmp(p->name, name) == 0) { return p; }
	//������ ���ų� ������ �� ū ����� ���� ���
	else { return NULL; }
}

//���� ����� ��� ��Ƽ��Ʈ�� �뷡�� ���
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

	//�������� �� �󿡼� ����, ����Ŭ���� ������
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
		fprintf(fp, " #");//path �������� �ʴ� ��� ��������
	if (ptr_song->path != NULL) 
		fprintf(fp, "%s#\n", ptr_song->path);
	else
		fprintf(fp, " #\n");//path �������� �ʴ� ��� ��������
}

void remove(int index) {
	//index�� �ش��ϴ� song�� ã�´�
	SNode* q = NULL;//previous node 
	SNode* p = index_directory[index % SIZE_INDEX_TABLE]; //head node
	while (p != NULL && p->song->index != index) {
		q = p;
		p = p->next;
	}
	if (p == NULL) {//snode �� �ϳ��� ���ų�, ������ �������� ��ã�� ���
		printf("No such song exists.\n");
		return;
	}
	//�ϳ��� song�� �����Ҷ� artist �� �޸� ����� ���Ḯ��Ʈ�� snode��,
	//inddex_directory[i]�� �޸� �ܹ��� ���Ḯ��Ʈ�� snode �� �����ؾ� �Ѵ�.
	//����: index_directory[i]�� snode, artist�� snode, song ������ ����

	//1.index_directory[i]�� song�� �ش��ϴ� snode ����
	Song* ptr_song = p->song;
	if (q == NULL) {//ù��° ��� ����
		index_directory[index % SIZE_INDEX_TABLE] = p->next;
		//p = p->next; <- �̷��� ���� �ȵ�, index_directory[index % SIZE_INDEX_TABLE] != p, ������ ���� ���� ��
	}
	else {//�߰� ���(q���� ���)����
		q->next = p->next;// q->next = q->next->next;
	}
	free(p);

	//2. ptr_artist �� ���߿��Ḯ��Ʈ���� snode ����
	//ptr_artist �� ���߿��Ḯ��Ʈ���� snode�� ã�´�
	Artist* ptr_artist = ptr_song->artist;
	SNode *ptr_snode = find_snode(ptr_artist, ptr_song->title);
	if (ptr_snode == NULL) {
		printf("Not found snode - something wrong(�Ͼ���� �ȵǴ� ��Ȳ)\n");
		return;
	}
	remove_snode(ptr_artist, ptr_snode);

	//3.song ��ü ����
	destroy_song(ptr_song);
}


void destroy_song(Song* ptr_song) {
	if (ptr_song->title != NULL)
		free(ptr_song->title);
	if (ptr_song->path != NULL)
		free(ptr_song->path);
	free(ptr_song);
}

//2. ptr_artist �� ���߿��Ḯ��Ʈ���� snode ����
void remove_snode(Artist*ptr_artist, SNode* ptr_snode) {
	SNode* first = ptr_artist->head;
	SNode* last = ptr_artist->tail;
	if (first == ptr_snode && last == ptr_snode) {//��� �Ѱ� ����, �� �� ��� ����
		ptr_artist->head = NULL;
		ptr_artist->tail = NULL;
	}
	else if (first == ptr_snode) {//��� 2�� �̻� ����, �� �� ��� ����
		ptr_artist->head = first->next;
		first->next->prev = NULL;
	}
	else if (last == ptr_snode) {// ��� 2�� �̻� ����, �� �� ��� ����
		ptr_artist->tail = last->prev;
		last->prev->next = NULL;

	}
	else {//�߰� ��� ����
		ptr_snode->prev->next = ptr_snode->next;
		ptr_snode->next->prev = ptr_snode->prev;
	}
	free(ptr_snode);
}