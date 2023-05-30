#include "../include/headerA3.h"
void fireAll (a3Emp ** headLL){
    //error checking
    if (*headLL == NULL){
        printf("Error. List is empty.\n");
        return;
    }
    a3Emp * curr = *headLL;

    while(curr != NULL){
        a3Emp * next = curr->nextEmployee;
        //frees dependents list as well as nodes
        for (int i = 0; i < curr->numDependents; i++) {
            free(curr->dependents[i]);
        }
        free(curr->dependents);

        free(curr);
        curr = next;
    }
    *headLL=NULL; //signal that list is empty
}