#include "../include/headerA3.h"
int main(){
    //initializing
    struct employee * headA3 = NULL;
    struct employee * temp;
    int whichOne;
    int whichEmpId;
    char whichName[100];
    int choice;
    int b,c;
    char a;
    int positionName;
    int empCount;
    int employCount;
    int check = 0; //to see if list is already freed

    //loading employees from textfile using helper file
    loadEmpData(&headA3, "./proFile.txt");
    temp = headA3;

    //for menu
    do {
        printf ("\nHere is the menu \n\n");
        printf ("1. Add a new employee\n");
        printf ("2. Print data of all employees\n");
        printf ("3. Print data of the nth employee\n");
        printf ("4. Search for employee based on empId\n");
        printf ("5. Search for employee based on full name\n");
        printf ("6. Count the total number of employees\n");
        printf ("7. Sort the employees based on their empId\n");
        printf ("8. Remove the nth employee in the current LL\n");
        printf ("9. Remove all employees in the current LL\n");
        printf ("10. Exit\n");

        printf ("\nEnter your choice: ");
        scanf ("%d", &choice);

        switch (choice) {
            case 1:
                while ((b = getchar()) != '\n' && b != EOF);//clears buffer of newline
                recruitEmployee(&headA3);
                break;
            case 2:
                printAll(temp);
                break;
            case 3:
                printf("Enter a position: ");
                scanf("%d", &whichOne);
                printOne(temp, whichOne);
                break;
            case 4:
                printf("\nEnter an employee ID: ");
                scanf("%d", &whichEmpId);
                int position = lookOnId(temp, whichEmpId);
                //error checking
                if (position == 0){
                    printf("\nEmployee ID not found.");
                }
                else if(position == -1){
                    printf("\nError, list is empty.");
                }
                else{
                    whichOne = position;
                    printOne(temp, position);
                }
                break;
            case 5:
                while ((c = getchar()) != '\n' && c != EOF);

                printf("Enter the full name of the employee: ");
                fgets(whichName, 100 ,stdin);
                whichName[strcspn(whichName, "\n")] = '\0'; // remove the newline
                positionName = lookOnFullName(temp, whichName);
                //error checking
                if (positionName == 0){
                    printf("\nEmployee name not found.");
                }
                else if(positionName == -1){
                    printf("\nError, list is empty.");
                }
                else{
                    printOne(temp, positionName);
                }
                break;
            case 6:
                empCount = countEmployees(temp);
                //error checking
                if(empCount == 0){
                    printf("Error. The list is empty.");
                }
                printf("\nTotal number of employees = %d", empCount);
                break;
            case 7:
                sortEmployeesId(temp);
                break;
            case 8:
                employCount = countEmployees(temp);
                printf("\nTotal number of employees = %d", employCount);
                printf("\nWhich employee do you wish to fire - enter a value between 1 and %d: ", employCount);
                scanf("%d", &whichOne);
                //error checking
                while(whichOne < 1 || whichOne > employCount){
                    printf("\nTry again: ");
                    scanf("%d", &whichOne);
                }
                fireOne(&headA3, whichOne);
                break;
            case 9:
                printf("\nAre you sure you want to fire everyone?: ");
                scanf(" %c", &a);
                if( a == 'y' || a == 'Y'){
                    fireAll(&headA3);
                    check = 1; //to alert that memory has been freed
                }
                break;
            case 10:
                printf("\nYou have exited.\n");
                break;

            default: printf ("\nThat is an invalid choice\n");

        }

    } while (choice != 10);
    
    //frees memory if it hasnt been freed
    if(check != 1){
        fireAll(&headA3);
    }
    
    return 0;
}
