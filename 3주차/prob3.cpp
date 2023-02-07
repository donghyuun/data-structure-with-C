#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 10000
//********테스트 모두 통과*********

//1. 파일 읽는다
//	 읽어올 때 '\t' 과 \0" 을 기준으로 분리하여 words, sentences 배열에 저장

//2. words 배열을 사전식으로 정렬하며, 이때 sentences 배열은 words 배열과 쌍이다.

//3. 정렬된 배열 words 와 sentences 배열을 이용해 
//   읽어온 파일과 같은 형태로 새로운 파일을 생성해저장한다

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
    //한 문장씩 읽어들여서 단어와 설명으로 나누고 각각 배열에 저장한다.
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