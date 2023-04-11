#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void*b){   
    return strcmp(*(const char**)a, *(const char**)b);
}


char morse[26][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-", "-.--", "--.."};


int uniqueMorseRepresentations(char ** words, int wordsSize){
    
    if (wordsSize == 1) return 1;
    
    char** trans = (char**)malloc(wordsSize * sizeof(char*));   
    
    for(int i=0; i < wordsSize; i++){
        int len = strlen(words[i]);
        trans[i] = (char*) calloc((len * 4 + 1), sizeof(char)); 
        for(int j=0; j < len; j++)
            strcat(trans[i], morse[words[i][j] - 'a']);     
    }
    
    qsort(trans, wordsSize, sizeof(char**), cmp);      
    
    int cnt = wordsSize;        
    for(int i=1; i < wordsSize; i++)
        if (!strcmp(trans[i-1], trans[i])) cnt--;   
    
    for(int i=0; i < wordsSize; i++)    
        free(trans[i]);
    free(trans);
    
    return cnt;
}