#include "../include/headerA3.h"
void printOne (struct employee * headLL, int whichOne){
    //error checking
    if (headLL == NULL){
        printf("Error. List is empty.\n");
        return;
    }
    //to keep track of how many employees there are
    //dont want to print something out of range
    int count = 0;
    a3Emp * pos = headLL;
    while(headLL != NULL){
        headLL = headLL->nextEmployee;
        count++;
    }
    //asks user to inputing until in range
    while(whichOne>count){
        printf("\nThere are only %d positions", count);
        printf("\nEnter a position: ");
        scanf("%d", &whichOne);
    }
    //traverses through LL until desired position reached
    for(int i = 0; i < whichOne-1; i++){
        pos = pos->nextEmployee;
    }
    //prints attributes at correct position in proper format
    printf("\nEmployee id: %d\n", pos->empId);
    printf("First name: %s\n", pos->fname);
    printf("Last name: %s\n", pos->lname);
    printf("Dependents[%d]: ", pos->numDependents);
    for(int i = 0; i < pos->numDependents; i++){
        if(i == pos->numDependents-1){
            printf("%s", pos->dependents[i]);
         }
        else{
            printf("%s, ", pos->dependents[i]);
        }
    }
    printf("\n");
}