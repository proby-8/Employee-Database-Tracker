#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne) {
    int count = 1;
    int i=0;
    a3Emp *temp = headLL;

    // if LL is empty
    if (temp == NULL) {
        printf("The list is empty.\n\n");
        return;
    }

    // if position is not within range
    if (!((whichOne > 0) && (whichOne <= countEmployees(headLL)))) {
        printf("Could not find the requested employee.\n\n");
    }

    // loop through LL
    while (temp != NULL) {

        // at requested position
        if (count == whichOne) {

            // print requested employee's info
            printf("\nEmployee id: %d\n", temp->empId);
            printf("First name: %s\n", temp->fname);
            printf("Last name: %s\n", temp->lname);
            printf("Dependants: ");
            for (i=0; i<temp->numDependents; i++) {
                if ((i >= ((temp->numDependents)-1))) {
                    printf("%s", temp->dependents[i]);
                }
                else {
                    printf("%s, ", temp->dependents[i]);
                }
            }
            printf("\n\n");
        }

        count++;
        temp = temp->nextEmployee;
    }
}
