#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 10000
//********�׽�Ʈ ��� ���*********

//1. ���� �д´�
//	 �о�� �� '\t' �� \0" �� �������� �и��Ͽ� words, sentences �迭�� ����

//2. words �迭�� ���������� �����ϸ�, �̶� sentences �迭�� words �迭�� ���̴�.

//3. ���ĵ� �迭 words �� sentences �迭�� �̿��� 
//   �о�� ���ϰ� ���� ���·� ���ο� ������ �����������Ѵ�

char* words[BUFFER_SIZE];
char* sentences[BUFFER_SIZE];
int n = 0;

void load();
void Sort(char** wor, char** sen, int n);
void save();

int main(void) {
    load();
    Sort(words, sentences, n);
    save();

    return 0;
}

void load() {
    char temp[BUFFER_SIZE];
    FILE* fp = fopen("shuffled_dict.txt", "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    //�� ���徿 �о�鿩�� �ܾ�� �������� ������ ���� �迭�� �����Ѵ�.
    while ((fgets(temp, BUFFER_SIZE, fp) != NULL)) {
        char* tempWord = strtok(temp, "\t");
        char* tempSentence = strtok(NULL, "\0");
        words[n] = strdup(tempWord);
        sentences[n] = strdup(tempSentence);
        n++;
    }
}

void Sort(char** wor, char** sen, int n) {
    char* temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(wor[j], wor[j + 1]) > 0) {
                temp = wor[j];
                wor[j] = wor[j + 1];
                wor[j + 1] = temp;

                temp = sen[j];
                sen[j] = sen[j + 1];
                sen[j + 1] = temp;
            }
        }
    }
}

void save() {
    FILE* fp2 = fopen("sorted_dict.txt", "w");

    for (int i = 0; i < n; i++) {
        fputs(words[i], fp2);
        fputs(sentences[i], fp2);
    }
    fclose(fp2);
}