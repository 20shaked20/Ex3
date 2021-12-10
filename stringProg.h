//
// Created by Shaked Levi on 10/12/2021
//
#ifndef EX_3_STRING_PROG_H
#define EX_3_STRING_PROG_H


    /**
     * This method loads a text file from the user:
     * a word until empty char ('','\t','\n')
     * text sequence until '~'.
     *
     */
    void load();
    
    /**
     * This method prints all the minimal sequences in the text with the same geometric value to the word given.
     * A geometric sequence is the sum of all the values of each char the word has, i'e:
     * a=A=1, b=B=2, c=C=3 ... 
     * each charater that is not from the english alphabet has a value of 0.
     */
    void geometric_sequence();

    /**
     * This method prints all the minimal sequences in the text, while ignoring empty chars(stated above), are:
     * 1. equivlenet to the word.
     * 2. equivelent to the word in 'Atbash' sequence.
     * Atbash sequence is - reversering the words in the alphabet, meaning - A turns to Z, B turns to Y ...
     * *note that words keep their case (upper or lower) while switching.
     * each charater that is not from the english alphabet is to remain the same.
     */
    void atbash_sequence();

    /**
     * This method prints all the minimal possible sequences in the text which contains:
     * 1. all the charaters from the word given.
     * 2. blank spaces are ok to consider, also need to take note its minimal sequence.!
     * i'e:
     * Given the word: #aabcdefg
     * valid sequence - > fg#     gb adace
     * not valid sequence - > fg#   gb,adace
     */
    void sub_sequences();





#endif //EX_3_STRING_PROG_H