#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL) {
    int count = 0;
    a3Emp *temp = headLL;

    // if head of LL is null, no employees exist
    if (temp == NULL) {
        return 0;
    }

    // iterate through each element of the LL
    while (temp != NULL) {
        count++;
        temp = temp->nextEmployee;
    }

    // return number of elements in LL
    return count;
}
