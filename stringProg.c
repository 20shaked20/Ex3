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

/**
 * This private method transforms char to a desired value. as we need to use in the project.
 */
int char_value_transform(char c){
    int loc = c;
    if(loc>96 && loc<123){ // a-z case
        c = c-'a'+1;
    }
    else if(loc>64 && loc<91){ // A-Z case
        c = c-'A'+1;
    }else{ // all other is equal to zero.
        c = 0; 
    } 
}
void geometric_sequence(){
    printf("geometric_sequence:");
    int txt_sum = 0;
    int i =0;
    int word_sum = 0; // the geometric sum of the word.

    // Calculates the sum.
    while(word[i]!='\0'){
        word_sum+=char_value_transform(word[i]);
        ++i;
    }
    //Test for me. to be removed later.
    printf("The word Sum is: %d \n",word_sum );
    
    i = 0;
    for(int j =0; txt[j]; ++j){
        if(txt_sum>word_sum){ // if we overacheived the sum, just bounce back.
            j = i;
            txt_sum = 0;
            ++i;
        }else if(txt_sum == word_sum){
            char *txt_tmp = (char*)malloc(sizeof(char)*TXT);
            if(txt_tmp==NULL){
                printf("Memory allocation fault");
            }
            printf("%s ~ ", strncpy(txt_tmp,txt+i,j));
            txt_sum = 0;
            ++i;
            j = i;
        }else{
            txt_sum+=char_value_transform(txt[j]);
            
        }
    }
}
