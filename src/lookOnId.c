#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {
    int count = 1;
    a3Emp *temp = headLL;

    // if LL is empty
    if (temp == NULL) {
        return -1;
    }

    // loop through each element of LL
    while (temp != NULL) {

        // return position if found
        if (whichEmpId == temp->empId) {
            return count;
        }
        count++;
        temp = temp->nextEmployee;
    }

    // return -1 if not found
    return -1;
}
