#include "../include/headerA3.h"

int main(int argc, char *argv[]) {
    int choice=0;
    int repeat=1;
    char fileName[MAX_LENGTH] = "proFile.txt";
    int whichNumber;
    int whichId;
    char whichName[MAX_LENGTH*2];
    int whichNumberFire;
    char confirm;
    char waste;

    // start it off right
    a3Emp * headLL = NULL;
    loadEmpData(&headLL, fileName);

    // print the menu, loop until user wants to exit
    while (repeat) {
        printf("\n1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");
        printf("\nChoose a menu option: ");

        // get menu choice from user
        if (!scanf("%d%c", &choice, &waste)) {
            choice = -1;
        }
        printf("\n");

        // switch based off user input
        switch(choice) {

            // user entered invalid input
            default:

                printf("It appears the input you entered is not valid. Be sure to enter an integer from 1-10.\n\n");

            break;

            case 1:

                // add an element to the end of the LL
                recruitEmployee(&headLL);

            break;
            
            case 2:

                // print all elements of the LL
                printAll (headLL);

            break;

            case 3:

                // get position to print
                printf("Enter a position: ");
                if (!scanf("%d", &whichNumber)) {
                    whichNumber = -1;
                }
                printOne(headLL, whichNumber);

            break;

            case 4:

                // search for employee by id
                printf("Enter an Employee Id: ");
                if (!scanf("%d", &whichId)) {
                    whichId = -1;
                }

                printOne(headLL, lookOnId(headLL, whichId));

            break;

            case 5:

                // get name to search for
                printf("Enter an Employee name: ");
                fgets(whichName, MAX_LENGTH*2, stdin);

                // remove trailing newline from fgets
                whichName[strlen(whichName)-1] = '\0';

                printOne(headLL, lookOnFullName (headLL, whichName));

            break;

            case 6:

                // print number of employees (empty is count == 0)
                if (countEmployees(headLL) == 0) {
                    printf("The list is empty.\n\n");
                }
                else {
                    printf("Total number of employees = %d\n\n", countEmployees (headLL));
                }

            break;

            case 7:

                // print the sorted employees using the function
                sortEmployeesId (headLL);

            break;

            case 8:

                // ask user who they want to fire
                printf("Currently there are %d employees.\n", countEmployees(headLL));
                printf("Which employee do you wish to fire – enter a value between 1 and %d: ", countEmployees(headLL));
                if (!scanf("%d", &whichNumberFire)) {
                    whichNumberFire = -1;
                }

                // fire the desired employee
                fireOne(&headLL, whichNumberFire);
                printf("There are now %d employees.\n\n", countEmployees(headLL));

            break;

            case 9:

                // confirm if they want to fire everyone
                printf("Are you sure you want to fire everyone: ");
                scanf(" %c", &confirm);

                if (confirm == 'y') {
                    // this prints after firing so that the exit function does not print
                    if (countEmployees(headLL) > 0) {
                        fireAll (&headLL);
                        printf("All fired. Linked list is now empty.\n\n");
                    }
                    // fireAll could also be called here as it does nothing
                    // I'm calling it purely to show that it doesn't error
                    else {
                        fireAll (&headLL);
                        printf("The list is empty.\n\n");
                    }
                }

            break;

            case 10:

                // fire all the employees before exiting so that there are no memory leaks
                fireAll(&headLL);
                repeat = 0;

            break;
        }
    }

    return 0;
}