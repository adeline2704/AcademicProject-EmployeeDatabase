#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]){
    //error checking
    if(headLL == NULL){
        return -1;
    }
    //initializing
    int length = strlen(whichName);
    int i = 0;
    int j;
    char fname [MAX_LENGTH] = "";
    char lname [MAX_LENGTH] = "";
    int count = 0;
    //getting fname before space
    while(whichName[i]!= ' ' && i < length){
        fname[i] = whichName[i];
        i++;
    }
    fname[i] = '\0';
    //getting lname after space
    for (j = i+1; j < length; j++){
        lname[j-i-1] = whichName[j];
        
    }
    lname[j-i] = '\0';
    //comparing to first and last names in LL and returning position when match is found
    while(headLL != NULL){
        count++;
        if(strcmp(headLL->fname, fname) == 0 && strcmp(headLL->lname, lname) == 0){
            return count;
        }
        headLL = headLL->nextEmployee;
    }
    return count;
}