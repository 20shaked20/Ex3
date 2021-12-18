//
// Created by Shaked Levi on 10/12/2021
//
#define TXT 1024
#define WORD 30

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * This is a prive method that converts Charaters of the english alphabet to 1-26.
 * all others are turned to 0.
 */
int char_value_transform(char c)
{
    int loc = c;
    // a-z case
    if (loc > 96 && loc < 123)
    {
        loc = c - 'a' + 1;
        return loc;
    }
    // A-Z case
    else if (loc > 64 && loc < 91)
    {
        loc = c - 'A' + 1;
        return loc;
    }
    // all other is equal to zero.
    else
    {
        return 0;
    }
}

// THE MAIN METHOD:
void Gematria_Sequences(char *word, char *txt)
{
    printf("Gematria Sequences: ");
    int txt_sum = 0;  // the sum i calcaulte to the word in the text.
    int word_sum = 0; // the geometric sum of the the current word.
    int i = 0;        // inside loop index.
    int j = 0;        // outside loop index.
    // The String im printing.
    // char *Printout = (char *)malloc(sizeof(char) * TXT);
    char *Printout = (char *)calloc(TXT, sizeof(char));
    if (Printout == NULL)
    {
        printf("Printout Memory allocation fault");
    }
    // Calculates the sum of the current word
    while (word[i] != '\0')
    {
        word_sum += char_value_transform(word[i]);
        ++i;
    }

    for (j = 0; txt[j]; ++j)
    {
        //Resets:
        txt_sum = 0;

        for (i = j; txt[i]; ++i)
        {
            // bad case. break the loop
            if (txt_sum > word_sum)
            {
                break;
            }
            // good case, we got to a same gematria sum, therefore check the word.
            else if (txt_sum == word_sum)
            {
                char *sub_string = (char *)calloc(WORD, sizeof(char));
                if (sub_string == NULL)
                {
                    printf("MEMORY FAULT");
                }
                int tmp = 0;
                for (int loop = j; loop < i; ++loop)
                {
                    sub_string[tmp] = txt[loop];
                    tmp++;
                }
                // checks that start&last index are alphbet, other wise it has unwatned 'spaces'.
                if (char_value_transform(sub_string[0]) != 0 && char_value_transform(sub_string[strlen(sub_string) - 1]) != 0)
                {
                    sub_string[tmp] = '~'; // adding to the last word.
                    tmp++;
                    sub_string[tmp] = '\0';
                    strcat(Printout, sub_string);
                    free(sub_string);
                }
                break;
            }
            //keep adding value to the sum, and increase word size.
            else
            {
                txt_sum += char_value_transform(txt[i]);
            }
        }
    }
    Printout[strlen(Printout) - 1] = '\0'; // set the last position from ~ to null, i dont want it to print anything.
    printf("%s", Printout);
    free(Printout);
}

/////////////////////////// ATBASH method /////////////////////////////////

///TODO: create more tests for atbash testing. rn its working good.

/**
 * This is a private method that converts Charaters of the english alphabet to thier 'Atbash' charater.
 * all others are turned to 0.
 */
char atbash_value_transform(char c)
{
    int loc = c;
    // a-z case
    if (loc > 96 && loc < 123)
    {
        c = 'z' - c + 'a';
        return c;
    }
    // A-Z case
    else if (loc > 64 && loc < 91)
    {
        c = 'Z' - c + 'a';
        return c;
    }
    // all other is equal to zero.
    else
    {
        loc = 0;
        return loc;
    }
}

/**
 * This is a private method that gets a word pointer, and converts the entire word to 'Atbash' word.
 */
void atbash_converter(char *word)
{
    int i = 0;
    for (i = 0; word[i]; ++i)
    {
        *(word + i) = atbash_value_transform(word[i]);
    }
}

/**
 * This is a private method that gets a word pointer and reverses it.
 */
void str_rev(char *str)
{
    int l, i;
    char *begin_ptr, *end_ptr, ch;

    // Get the length of the string
    l = strlen(str);

    // Set the begin_ptr and end_ptr
    // initially to start of string
    begin_ptr = str;
    end_ptr = str;

    // Move the end_ptr to the last character
    for (i = 0; i < l - 1; i++)
        end_ptr++;

    // Swap the char from start and end
    // index using begin_ptr and end_ptr
    for (i = 0; i < l / 2; i++)
    {

        // swap character
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;

        // update pointers positions
        begin_ptr++;
        end_ptr--;
    }
}

/**
 * This is a private illustartion of the strcmp() method that is given to us in the strings library.
 * i had to maniuplate it a bit so it would consider blanks, 
 * as in the assignemnets in between blanks are part of the word we wish to print.
 */
int str_cmp(char *str1, char *str2)
{ // i guess str2 will be bigger because i consider blanks.
    int str1_counter = 0;
    int word_length = strlen(str1);
    for (int loop = 0; str2[loop]; ++loop)
    {
        // any blank space in between, hence i dont care.
        if (char_value_transform(str2[loop]) == 0)
        {
            ++loop;
        }
        //checks if in same position, while ignoring blanks the strings are equal.
        if (*(str1 + str1_counter) == *(str2 + loop))
        {
            str1_counter++;
        }
        else
        {
            return -1;
        }
    }
    if (str1_counter == word_length)
    {
        return 0; // is equal.
    }
    else
    {
        return -1; // not equal
    }
}

// THE MAIN METHOD:
void Atbash_Sequences(char *word, char *txt)
{
    printf("Atbash Sequences: ");
    //Create an atbash word from the current word:
    char *word_copy = malloc(strlen(word) + 1);
    if (word_copy == NULL)
    {
        printf("word_copy, Memory Allocation Fault");
    }
    strcpy(word_copy, word);
    atbash_converter(word_copy);

    // Create a reverse version of the atbash word:
    char *reverse = (char *)malloc(sizeof(char) * WORD);
    if (reverse == NULL)
    {
        printf("reverse, Memory Allocation Fault");
    }
    strcpy(reverse, word_copy);
    str_rev(reverse);

    //String im printing.
    char *Printout = (char *)calloc(TXT, sizeof(char)); // reset memory.
    if (Printout == NULL)
    {
        printf("Printout Memory allocation fault");
    }

    int i = 0;
    int j = 0;

    //TXT travesring:
    for (j = 0; txt[j]; ++j)
    {
        for (i = j; txt[i]; ++i)
        {
            if (strchr(word_copy, txt[i]) != NULL || char_value_transform(txt[i]) == 0)
            {
                char *sub_string = (char *)calloc(WORD, sizeof(char));
                if (sub_string == NULL)
                {
                    printf("MEMORY FAULT");
                }
                int tmp = 0;
                for (int loop = j; loop <= i; ++loop)
                {
                    sub_string[tmp] = txt[loop];
                    tmp++;
                }
                sub_string[tmp] = '\0';
                //alphabet sanity.
                if (char_value_transform(*(txt + j)) != 0 && char_value_transform(*(txt + i)) != 0)
                {

                    if (str_cmp(word_copy, sub_string) == 0 || str_cmp(reverse, sub_string) == 0)
                    {
                        // '~' manipulation to fit my code.
                        sub_string[tmp] = '~';
                        tmp++;
                        sub_string[tmp] = '\0';
                        strcat(Printout, sub_string);
                        break;
                    }
                }

                free(sub_string);
            }
        }
    }
    Printout[strlen(Printout) - 1] = '\0'; // set the last position from ~ to null, i dont want it to print anything.
    printf("%s", Printout);
    free(Printout);
    free(reverse);
    free(word_copy);
}

/////////////////////////// anagram methods /////////////////////////////////

/**
 * This is a private method i created to check if a string is an angram of another string.
 */
int anagram_check(char *str1, char *str2)
{ // i guess str2 will be bigger because i consider blanks. << check this for the loop fix,.

    if (str_cmp(str1, str2) == 0)
    { // checks that the strings are not equal in char location.
        return 0;
    }
    int arr[26]; // as the size of possible letters in alphabet
    int char_index1 = 0;
    int char_index2 = 0;
    int loop = 0;
    //reset array to 0.
    for (loop = 0; loop < 26; ++loop)
    {
        arr[loop] = 0;
    }
    // This loop counts how many occurences each charater has and adds it to the original array.
    for (loop = 0; loop < strlen(str1) - 1; ++loop)
    {
        char_index1 = char_value_transform(str1[loop]);
        arr[char_index1] += 1;
    }
    // This loop counts how many occurences each charater has and removes it from the original array.
    for (loop = 0; loop < strlen(str2); ++loop)
    {
        char_index2 = char_value_transform(str2[loop]);
        arr[char_index2] -= 1;
    }

    // Loop checking if the array is 0, if yes then the word is anagram of the other one.
    // if no: then there was more than occurences of a word in the 2nd string.
    for (loop = 1; loop < 26; ++loop)
    {
        if (arr[loop] != 0)
        {
            return -1;
        }
    }
    return 0; // is equal for sure.
}

// THE MAIN METHOD:
void Anagram_Sequences(char *word, char *txt)
{
    printf("Anagram Sequences: ");
    int i = 0;                                          // inside loop index.
    int j = 0;                                          // outside loop index.
    int word_size = 0;                                  // calcualtes the current txt word size, so i can know where it ends.
    int real_size = strlen(word) - 1;                   // ignore \0
    char *Printout = (char *)calloc(TXT, sizeof(char)); // changed to calloc so my print will reset
    if (Printout == NULL)
    {
        printf("Printout Memory allocation fault");
    }
    //TXT traversing:
    for (j = 0; txt[j]; ++j)
    {
        //resets
        word_size = 0;
        for (i = j; txt[i]; ++i)
        {
            // checks if the word contains the character in current positon, or its blank.

            if (strchr(word, txt[i]) != NULL || txt[i] == ' ')
            {
                // checks that start&last index are alphbet.
                if (char_value_transform(*(txt + j)) != 0 && char_value_transform(*(txt + i)) != 0)
                {
                    word_size++;
                    // good case, where our txt word reached the real size of the given word.
                    if (word_size == real_size)
                    {
                        // Substring creation:
                        char *sub_string = (char *)calloc(WORD, sizeof(char));
                        if (sub_string == NULL)
                        {
                            printf("MEMORY FAULT");
                        }
                        int tmp = 0;
                        for (int loop = j; loop <= i; ++loop)
                        {
                            sub_string[tmp] = txt[loop];
                            tmp++;
                        }
                        sub_string[tmp] = '~'; // adding to the last word.
                        tmp++;
                        sub_string[tmp] = '\0';

                        // printf("SubSTRING: %s\n ",sub_string);
                        //check if the substring is an anagram of our word.
                        if (anagram_check(word, sub_string) == 0)
                        {
                            //combine all the strings togheter.
                            strcat(Printout, sub_string);
                        }
                        free(sub_string);
                    }
                }
            }
            //bad case, it broke the sequence, hence break the loop.
            else
            {
                break;
            }
        }
    }
    Printout[strlen(Printout) - 1] = '\0'; // set the last position from ~ to null, i dont want it to print anything.
    printf("%s", Printout);
    free(Printout);
}
