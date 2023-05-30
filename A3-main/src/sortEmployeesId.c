#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL){
    //error checking
    if (headLL == NULL){
        printf("Error. List is empty.\n");
        return;
    }
    //initializing
    a3Emp * temp = malloc(sizeof(a3Emp));
    a3Emp * copyHeadLL = copyList(headLL);
    a3Emp * current = copyHeadLL;
    a3Emp * afterC = NULL;

    //traverses through list keeping track of current node and the one next to it
    while(current != NULL){
      afterC = current->nextEmployee;
      while(afterC != NULL){
        //had to swap attributes of nodes using bubble sort instead of swapping actual nodes
        if(current->empId>afterC->empId){
          strcpy(temp->fname , current->fname);
          strcpy(temp->lname , current->lname);
          temp->numDependents = current->numDependents;
          temp->dependents = current->dependents;
          temp->empId = current->empId;

          strcpy(current->fname , afterC->fname);
          strcpy(current->lname ,  afterC->lname);
          current->numDependents = afterC->numDependents;
          current->dependents = afterC->dependents;
          current->empId = afterC->empId;

          strcpy(afterC->fname , temp->fname);
          strcpy(afterC->lname , temp->lname);
          afterC->numDependents = temp->numDependents;
          afterC->dependents = temp->dependents;
          afterC->empId = temp->empId;

        }
        afterC = afterC->nextEmployee;
      }
    current = current->nextEmployee;
    }
    //prints list in function and frees all memory necessary from copying the list and temp variable
    printf("\nAfter sorting on empId, the employees are as follows:");
    printAll(copyHeadLL);
    free(temp);
    fireAll(&copyHeadLL);
}
