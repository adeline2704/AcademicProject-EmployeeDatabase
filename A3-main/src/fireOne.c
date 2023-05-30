#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne){
    //error checking
    if (*headLL == NULL){
        printf("Error. List is empty.\n");
        return;
    }
    //initialize
    a3Emp * currentNode = *headLL; 
    a3Emp * previousNode = NULL;  
    int i;
    //traverse as position of node requires
    for (i = 1; i<whichOne; i++){
        previousNode = currentNode;
        currentNode = currentNode->nextEmployee;
    }

    if(previousNode == NULL){
        //when head node is being removed
        *headLL = currentNode->nextEmployee;
    }
    else if(currentNode->nextEmployee == NULL){
        //if last node is removed
        previousNode->nextEmployee = NULL;
    }
    else{
        //if selected node is in the middle of the LL
        previousNode->nextEmployee = currentNode->nextEmployee;
    }
    printf("\nEmployee [Id:%d] fired.", currentNode->empId);
    int newEmpC = countEmployees(*headLL);
    printf("\nThere are now %d employees", newEmpC);

    //freeing dependents array from node we remove
    for (int j = 0; j < currentNode->numDependents; j++) {
        free(currentNode->dependents[j]);
    }
    free(currentNode->dependents);

    free(currentNode);
    
}
