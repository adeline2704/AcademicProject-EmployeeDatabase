#include "../include/headerA3.h"
void recruitEmployee (struct employee ** headLL){
    //initialize vars
    int i = 0;
    int count = 0;
    char dep = 'y';
    a3Emp * ptr;
    ptr = malloc(sizeof(a3Emp));
    ptr->nextEmployee = NULL;
    ptr->dependents = malloc(sizeof(char*));

    //get first and last name of employee
    printf("\nEnter the first name of the employee: ");
    fgets(ptr->fname, MAX_LENGTH, stdin);
    ptr->fname[strcspn(ptr->fname, "\n")] = '\0'; 

    printf("Enter the last name of the employee: ");
    fgets(ptr->lname, MAX_LENGTH, stdin);
    ptr->lname[strcspn(ptr->lname, "\n")] = '\0';

    //collect names of employee's dependent(s)
    while((dep == 'y'|| dep == 'Y')&&(dep != 'n' || dep != 'N')){
        count++;
        char * depName = malloc(sizeof(char) * MAX_LENGTH);
        printf("\nEnter name of dependent#%d: ", count);
        scanf("%s", depName);
        depName = realloc(depName, sizeof(depName)*(strlen(depName)+1));
        ptr->dependents[i] = depName;
        //asks if more than one dependent
        printf("\nDo you have any more dependents? ");
        scanf(" %c", &dep);
        while(dep != 'y' && dep != 'Y' && dep != 'N' && dep != 'n'){
            printf("Try again.");
            scanf(" %c", &dep);
        }
        if (dep == 'y' || dep == 'Y'){//since there is another dependent i'm adding another slot
            ptr->dependents = realloc(ptr->dependents, sizeof(char*)*(count+1));
        }
        i++;
    }
    //give value to numDependents and empId
    ptr->numDependents = count;
    ptr->empId = 0;
    //add each asci value to empId and length of last name
    for(int j = 0; j < strlen(ptr->fname); j++){
        ptr->empId += ptr->fname[j];
        //printf("%d\n", ptr->empId);
    }
    //printf("%d\n", ptr->empId);
    ptr->empId += strlen(ptr->lname);
    //printf("%d", ptr->empId);
    a3Emp * current = *headLL;
    while(current != NULL){
        if(current->empId == ptr->empId){
            ptr->empId += ((rand() % 999) + 1);
            current = *headLL;
        }
        else{
            current = current-> nextEmployee;
        }
    }
    if(*headLL == NULL){
        *headLL = ptr;
    }
    else{
        current = *headLL;
        while(current->nextEmployee != NULL){
            current = current->nextEmployee;
        }
        current->nextEmployee = ptr;
    }
    printf("\nYou have %d dependents.\n", ptr->numDependents);
    printf("Your computer-generated empId is %d\n", ptr->empId);
    
}