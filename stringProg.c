//
// Created by Shaked Levi on 10/12/2021
//

#define TXT 1024
#define WORD 30

#include <ctype.h>
#include <string.h>

char *word;
char *txt;

void load(char *word, char*txt)
{
    int i = 0;
    char c = "";
    *word = (char *)malloc(sizeof(char) * (WORD)); // size of word is 30.
    if (word == NULL)
    {
        printf("Memory allocation fault");
    }
    *txt = (char *)malloc(sizeof(char) * TXT); // size of txt is up to 1024.
    if (txt == NULL)
    {
        printf("Memory allocation fault");
    }

    //WORD LOADING: stops at a certain char / length = 30.
    while(c!="," && c!="\n" && c!="\t" && i<WORD){ 
        scanf("%c",&(*(word+i)));
        ++i;
    }
    
    i = 0;
    //TEXT LOADING: stops at '~' / length = 1024.
    while(c!="~" && i<TXT){
        scanf("%c",&(*(txt+i)));
        ++i;
    }  
}
/////////////////////////// geometric methods ///////////////////////////////// < working perfectly.
/**
 * This private method transforms char to a desired value. as we need to use in the project.
 */
int char_value_transform(char c)
{
    int loc = c;
    if (loc > 96 && loc < 123)
    { // a-z case
        c = c - 'a' + 1;
        return c;
    }
    else if (loc > 64 && loc < 91)
    { // A-Z case
        c = c - 'A' + 1;
        return c;
    }
    else
    { // all other is equal to zero.
        loc = 0;
        return loc;
    }
}

void geometric_sequence(char *word, char *txt)
{

    printf("geometric_sequence: \n");
    int txt_sum = 0;
    int i = 0;
    int word_sum = 0; // the geometric sum of the word.

    // Calculates the sum of the current word..
    while (word[i] != '\0')
    {
        word_sum += char_value_transform(word[i]);
        ++i;
    }
    printf("The word Sum is: %d \n", word_sum);

    int j; // starting index, updates everytime.
    int word_size = 0;
    for (j = 0; txt[j]; ++j)
    {
        txt_sum = 0; // resets every loop.
        word_size = 0;
        for (i = j; txt[i]; ++i)
        {
            if (txt_sum > word_sum)
            { // bad case. break the loop
                break;
            }
            else if (txt_sum == word_sum)
            {
                if (char_value_transform(*(txt+j)) != 0 && char_value_transform(*(txt+i-word_size)) != 0) // checks that start&last index are alphbet.
                {
                    for (int loop = j; loop <i; ++loop)
                    {
                        printf("%c", txt[loop]);
                    }
                    printf("~");
                }
                break;
            }
            else
            {
                txt_sum += char_value_transform(txt[i]);
                word_size++;
            }
        }
    }
}

/////////////////////////// ATBASH method /////////////////////////////////< Left to fix it, working kinda properly.
// converts the char to its rightful location in atbash.

// converts the char to its rightful location in atbash.
char atbash_value_transform(char c){
    int loc = c;
    if(loc>96 && loc<123){ // a-z case
        c = 'z'- c+'a';
        return c;
    }
    else if(loc>64 && loc<91){ // A-Z case
        c = 'Z' - c+'a'; 
         return c;
    }else{ // all other is equal to zero.
        loc = 0;
        return loc;
    } 
}
// the word converter.
void atbash_converter(char*word){
    
    int i =0;
    for(i = 0; word[i]; ++i){
        *(word+i) = atbash_value_transform(word[i]);
    }
    //printf("ATBASH : %s\n ", word);
    
}
void str_rev(char* str)
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
    for (i = 0; i < l / 2; i++) {
  
        // swap character
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;
  
        // update pointers positions
        begin_ptr++;
        end_ptr--;
    }
}
//private compare to method that igoners inside blankes
int str_cmp(char *str1, char *str2){
    int str1_counter = 0;
    for(int loop=0; (*(str2+loop))!='\0'; loop++)
	{
	    if(char_value_transform(str2[loop])==0){ // any blank space in between, hence i dont care.
            ++loop;
        }
		if(*(str1+str1_counter) == *(str2+loop))
		{
		    str1_counter++;
			
		}
	}
    if(str1_counter == strlen(word)){
        return 0; // is equal.
    }else{ 
        return -1; // not equal
    }
}
//convert word to atbash, then strchar(tmp,'txt');
// if yes, then ++, if not, just blip again.
void atbash_sequence(char *word, char*txt){
    printf("Atbash Sequence: ");
    char * word_copy= malloc(strlen(word) + 1); //creating a new word, so i wont overwrite mine,
    strcpy(word_copy, word);
    atbash_converter(word_copy);
    //printf("REG: %s",word_copy);
    char *reverse = (char*)malloc(sizeof(char)*WORD);
    strcpy(reverse,word_copy);
    str_rev(reverse); // reverses the text,
    int word_size = 0;
    int i = 0;
    int j = 0;
    // int index_reset;
    for(j = 0; txt[j]; ++j){
        word_size = 0;
        for(i = j; txt[i]; ++i){
        if(strchr(word_copy,txt[i])!=NULL||char_value_transform(txt[i])==0){ // < This if is a problem for spaced words. that are not included!!!!!
                word_size++;
                //printf("SUBTRINS: %s\n",sub_string);
                // printf("The reversed String: %s\n",reverse);
                // printf("The subString: %s", sub_string);
                if (char_value_transform(*(txt+j)) != 0 && char_value_transform(*(txt+i-word_size)) != 0){ // checks that start&last index are alphbet.
                char *sub_string = (char*)malloc(sizeof(char)*WORD);
                if(sub_string==NULL || reverse==NULL){
                    printf("MEMORY FAULT");
                }
                strncpy(sub_string,(txt+j),word_size);
                if(str_cmp(word_copy,sub_string)==0||str_cmp(reverse,sub_string)==0){
                    printf("%s~", sub_string);
                    free(sub_string);
                    break;
                }
                }
        }else{
            break;
        }
    }
    }
}

/////////////////////////// anagram methods ///////////////////////////////// 