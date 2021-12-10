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