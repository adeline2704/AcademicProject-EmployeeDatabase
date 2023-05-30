#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId){
    //error checking
    if(headLL == NULL){
        return -1;
    }
    //return position if empId match is found
    int count = 0;
    while(headLL != NULL){
        count++;
        if(headLL->empId == whichEmpId){
            return count;
        }
        headLL = headLL->nextEmployee;
    }
    return count;
}