#include "../include/headerA3.h"

void printAll (struct employee * headLL) {
    int count = 1;
    int i=0;
    a3Emp *temp = headLL;

    // if LL is empty
    if (temp == NULL) {
        printf("The list is empty.\n\n");
        return;
    }

    // loop through each element of LL
    while (temp != NULL) {

        // print employee information
        printf("Employee #%d\n", count);
        printf("\tEmployee id: %d\n", temp->empId);
        printf("\tFirst name: %s\n", temp->fname);
        printf("\tLast name: %s\n", temp->lname);
        printf("\tDependants [%d]: ", temp->numDependents);
        for (i=0; i<temp->numDependents; i++) {
            if ((i >= ((temp->numDependents)-1))) {
                printf("%s", temp->dependents[i]);
            }
            else {
                printf("%s, ", temp->dependents[i]);
            }
        }

        printf("\n\n");

        count++;
        temp = temp->nextEmployee;
    }

    // print number of employees
    printf("Currently, there are %d employees.\n\n", countEmployees(headLL));
}
