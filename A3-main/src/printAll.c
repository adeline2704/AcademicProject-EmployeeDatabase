#include "../include/headerA3.h"
void printAll (struct employee * headLL) {
   //error checking
   if (headLL == NULL){
        printf("Error. List is empty.\n");
        return;
    }
   //prints each nodes attributes as specified in sample run
   int count = 0;
   while (headLL != NULL) {
      count++;//to count number of employees
      printf("\nEmployee #%d\n", count);
      printf("\tEmployee id: %d\n", headLL->empId);
      printf("\tFirst name: %s\n", headLL->fname);
      printf("\tLast name: %s\n", headLL->lname);
      printf("\tDependents[%d]: ", headLL->numDependents);
      for(int i = 0; i < headLL->numDependents; i++){
         if(i == headLL->numDependents-1){
            printf("%s", headLL->dependents[i]);
         }
         else{
         printf("%s, ", headLL->dependents[i]);
         }
      }
      printf("\n");
      headLL = headLL->nextEmployee;
   }
   printf("\nCurrently, there are %d employees\n", count);
}