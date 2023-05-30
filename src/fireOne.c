#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne) {
    int count = 1;
    a3Emp *temp = *headLL;
    a3Emp *toDelete = temp;

    // if head of list is empty
    if (temp == NULL) {
        printf("The list is empty.\n\n");
        return;
    }

    // if invalid input
    if (!((whichOne > 0) && (whichOne <= countEmployees(temp)))) {
        printf("Could not find the requested employee.\n\n");
    }

    // if they want to delete the head
    if (whichOne == 1) {
        // set head equal to the next employee
        toDelete = *headLL;
        *headLL = toDelete->nextEmployee;
        printf("Employee [Id: %d] fired.\n", toDelete->empId);

        // free the head
        for (int i = 0; i<toDelete->numDependents; i++) {
            free(toDelete->dependents[i]);
        }
        free(toDelete->dependents);
        free (toDelete);
        return;
    }

    // deleting anyone other than the head
    while (temp->nextEmployee != NULL) {
        // stop at the employee before the employee to delete
        if (count == (whichOne-1)) {
            toDelete = temp->nextEmployee;
            printf("Employee [Id: %d] fired.\n", toDelete->empId);
            
            // set the one before nextEmployee to the next next employee (avoid gap)
            temp->nextEmployee = temp->nextEmployee->nextEmployee;

            // free the employee
            for (int i = 0; i<toDelete->numDependents; i++) {
                free(toDelete->dependents[i]);
            }
            free(toDelete->dependents);
            free (toDelete);
            return;
        }

        count++;
        temp = temp->nextEmployee;
    }
}
