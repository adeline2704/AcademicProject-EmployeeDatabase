#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL){
    int count = 0;
    //error checking
    if(headLL == NULL){
        return 0;
    }
    //increments count as traversing list
    while(headLL != NULL){
        headLL = headLL->nextEmployee;
        count++;
    }
    return count;
}
