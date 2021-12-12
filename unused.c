/**
 * Trick to sum -> char[pos] -a +1; == exact number in sequcne of 1,2,3...
 * This is a private method to calculate the geometric sum of our word, without overwriting the real word.
 */
// FIX FIX FIX! : 
// IDEA ON LOWER CASING ( CHECK THE ASQII if lower than 60, then its lower, and if bigger its upper )!!! no need to tolower! X_X im stpd.
int word_sum(){
    char *traverse = (char*)malloc(sizeof(char)*WORD); // creating a secondery pointer, so i wont overwrite my own word.
    if (traverse == NULL)
    {
        printf("Memory allocation fault");
    }
    strcpy(traverse,word); // copying the exact word to traverse.
    int i = 0;
    int sum = 0;
    for(i =0; traverse[i]; ++i){
        traverse[i] = tolower(traverse[i]);
        sum+=traverse[i] - 'a'+1; // the geometric sum of the word.
    }
    return sum;

}
void geometric_sequence(char *word, char*txt){
  
    printf("geometric_sequence: \n");
    int txt_sum = 0;
    int i =0;
    int word_sum = 0; // the geometric sum of the word.

    // Calculates the sum.
    while(word[i]!='\0'){
        word_sum+=char_value_transform(word[i]);
        ++i;
    }
    printf("The word Sum is: %d \n",word_sum );
    
    int j =0;
    i =0; // starting index, updates everytime.
    int word_size = 0;
    for(j = 0; txt[j]; ++j){
        if(txt_sum>word_sum){
            txt_sum = 0;
            word_size = 0;
            ++i;
            j = i; // start again from the next index.
        }else if( txt_sum == word_sum){
            char *sub_string = (char*)malloc(sizeof(char)*WORD);
            if(sub_string==NULL){
                printf("MEMORY FAULT");
            }
            printf("%s~", strncpy(sub_string,txt+i,word_size));
            txt_sum = 0;
            ++i;
            j = i;
            word_size = 0;
            free(sub_string);
        }else{
            txt_sum+=char_value_transform(*(txt+j));
            word_size++;
        }
    }
}


//////// TEST FUNCTIONALY OF GEMOETRIC???????
void geometric_sequence(char *word, char*txt){
  
    printf("geometric_sequence: \n");
    int txt_sum = 0;
    int i =0;
    int word_sum = 0; // the geometric sum of the word.

    // Calculates the sum.
    while(word[i]!='\0'){
        word_sum+=char_value_transform(word[i]);
        ++i;
    }
    printf("The word Sum is: %d \n",word_sum );
    
    int j =0;
    i =0; // starting index, updates everytime.
    int word_size = 0;
    for(j = 0; txt[j]; ++j){
        if(txt_sum>word_sum){
            txt_sum = 0;
            word_size = 0;
            j = i;
            ++i;
            // start again from the next index.
        }else if(txt_sum == word_sum){
            char *sub_string = (char*)malloc(sizeof(char)*TXT);
            if(sub_string==NULL){
                printf("MEMORY FAULT");
            }
            strncpy(sub_string,(txt+j-word_size),(word_size));
            // if(char_value_transform(sub_string[0])!=0){
                printf("%s~",sub_string);
                txt_sum = 0;
                i+=word_size-2;
                j = i;
                word_size = 0;
                free(sub_string);
            // }
        }else{
                txt_sum+=char_value_transform(*(txt+j));
                word_size++;
            
    }
}
}


//////////// TMP GEOMATRY////
void geometric_sequence(char *word, char*txt){
  
    printf("geometric_sequence: \n");
    int txt_sum = 0;
    int i =0;
    int word_sum = 0; // the geometric sum of the word.

    // Calculates the sum.
    while(word[i]!='\0'){
        word_sum+=char_value_transform(word[i]);
        ++i;
    }
    printf("The word Sum is: %d \n",word_sum );
    int j =0;
    i =0; // starting index, updates everytime.
    int word_size = 0;
    for(j = 0 ; txt[j]; ++j){
       for(i = j ; txt[i]; ++i){
           if(txt_sum>word_sum){
               txt_sum = 0;
               word_size = 0;
           }else if(txt_sum == word_sum){
            char *sub_string = (char*)malloc(sizeof(char)*TXT);
            if(sub_string==NULL){
                printf("MEMORY FAULT");
            }
            strncpy(sub_string,(txt+i-word_size),(word_size));
            int last_pos = strlen(sub_string)-1;
            if(char_value_transform(sub_string[0])!=0 && char_value_transform(sub_string[last_pos])!=0){
                printf("%s~",sub_string);
            }
                i+=word_size;
                word_size = 0;
                txt_sum = 0;
                free(sub_string);
           }
           else{
                txt_sum+=char_value_transform(*(txt+i));
                word_size++;
            
           }
       }
    }
}

