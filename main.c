//
// Created by Shaked Levi on 10/12/2021
//
#define TXT 1024
#define WORD 30

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "StringProg.h"

int main()
{
    char *word = (char *)malloc(sizeof(char) * WORD);
    if (word == NULL)
    {
        printf("word Memory Allocation Fault");
    }
    char *txt = (char *)malloc(sizeof(char) * TXT);
    if (txt == NULL)
    {
        printf("txt Memory Allocation Fault");
    }
    char c;
    int i = 0;
    ///TODO: FIX THIS C<
    while (c != '\n')
    {
        scanf("%c", &c);
        word[i] = c;
        ++i;
    }
    i = 0;
    while (c != '~')
    {
        scanf("%c", &c);
        txt[i] = c;
        ++i;
    }
    Gematria_Sequences(word, txt);
    printf("\n");
    Atbash_Sequences(word, txt);
    printf("\n");
    Anagram_Sequences(word, txt);
    free(word);
    free(txt);
}