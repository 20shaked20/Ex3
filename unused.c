/////////////////////////// anagram methods /////////////////////////////////
// THIS METHOD IS WORKING FOR BEE, but not for SEA FOR SOME REASON. maybe their angram meaning is wrong yaben zona

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

void anagram_sequence(char *word, char *txt)
{
    printf("anagram Sequence: ");
    int i = 0; // inside loop index.
    int j = 0; // outside loop index.
    int word_size = 0; // calcualtes the current txt word size, so i can know where it ends.
    int real_size = strlen(word)-1; // ignore \0
    char* Printout = (char*)malloc(sizeof(char)*TXT);
    if(Printout == NULL){
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
            
            if (strchr(word, txt[i]) != NULL || char_value_transform(txt[i]) == 0)
            {   
                // printf("THE J IS : %d \n ",j);
                // printf("Txt[i]: %c \n", txt[i]); 
                    // checks that start&last index are alphbet.
                    if (char_value_transform(*(txt + j)) != 0 && char_value_transform(*(txt + i)) != 0)
                    { 
                        word_size++;
                        // good case, where our txt word reached the real size of the given word.
                        if (word_size == real_size)
                        {
                        // Substring creation: 
                        char *sub_string = (char *)malloc(sizeof(char) * WORD);
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
                            strcat(Printout,sub_string);
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
    printf("%s",Printout);
}