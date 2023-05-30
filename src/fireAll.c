#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL) {  
    a3Emp *temp;

    // loop through each element of LL
    while (*headLL != NULL) {
        // set head = to the next employee
        temp = *headLL;
        *headLL = temp->nextEmployee;

        // delete the old head
        for (int i = 0; i<temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        free (temp);
    }
}
