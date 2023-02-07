#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_tools.h"
#include "library.h"
#define BUFFER_LENGTH 200

void process_command();
void handle_add();
void handle_load();
void handle_search();
void handle_play();
void handle_save();
void handle_remove();

int main(void) {
	initialize();
	handle_load();
	process_command();
	return 0;
}

void handle_load() {
	char buffer[BUFFER_LENGTH];

	printf("Data file name ? ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) <= 0)//라인단위로 입력받음
		return;

	FILE* fp = fopen(buffer, "r");
	if (fp == NULL) {
		printf("No such file exists.\n");
		return;
	}
	load(fp);
	fclose(fp);
}	

void process_command() {

	char command_line[BUFFER_LENGTH];
	char* command;

	while (1) {//무한 루프
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)//라인단위로 입력받음
			continue;

		command = strtok(command_line, " ");
		if (strcmp(command, "add") == 0)
			handle_add();
		else if (strcmp(command, "search") == 0)
			handle_search();
		else if (strcmp(command, "play") == 0)
			handle_play();
		else if (strcmp(command, "remove") == 0)
			handle_remove();
		else if (strcmp(command, "save") == 0) {
			char* tmp = strtok(NULL, " ");
			if (strcmp(tmp, "as") != 0) {
				continue;
			}
			handle_save();
		}
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "exit") == 0)
			break;
	}
}

void handle_remove() {
	char* id_str = strtok(NULL, " ");
	int index = atoi(id_str);
	remove(index);
}

void handle_save() {
	char* file_name = strtok(NULL, " ");
	FILE* fp = fopen(file_name, "w");
	save(fp);
	fclose(fp);//파일을 닫아줘야 모든 내용이 정상적으로 저장된다
}

void handle_play() {
	char* id_str = strtok(NULL, " ");
	int index = atoi(id_str);
	play(index);
}

void handle_search() {
	char name[BUFFER_LENGTH], title[BUFFER_LENGTH];

	printf("     Artist: ");
	if (read_line(stdin, name, BUFFER_LENGTH) <= 0)//라인단위로 입력받음
	{
		printf("    Artist name required.\n");
		return;
	}
	printf("     Title: ");
	int title_len = read_line(stdin, title, BUFFER_LENGTH);//라인단위로 입력받음
	
	if (title_len <= 0) //노래제목이 입력되지 않은 경우
		search_song(name);
	else
		search_song(name, title);
}


void handle_add() {
	char buffer[BUFFER_LENGTH];
	char* artist = NULL, * title = NULL, * path = NULL;
	
	printf("   Artist: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		artist = strdup(buffer);
	
	printf("   Title: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		title = strdup(buffer);
	
	printf("   Path: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		path = strdup(buffer);
	printf("%s %s %s\n", artist, title, path);
	/*add to the music library*/

	add_song(artist, title, path);
}