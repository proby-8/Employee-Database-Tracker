#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL) {
    a3Emp *temp = headLL;
    int *ids;
    int tempNum;
    int count=0;

    // if LL is empty
    if (temp == NULL) {
        printf("The list is empty.\n\n");
        return;
    }

    // malloc space for an array of IDS
    ids = malloc(sizeof(int) * 1);

    // loop through the entire array
    // create an array of empIds
    while (temp != NULL) {
        count++;
        ids = realloc(ids, sizeof(int) * count);
        ids[count-1] = temp->empId;

        temp = temp->nextEmployee;
    }

    // sort the Ids (smallest to biggest)
    for (int i=0; i<count; i++) {
        for (int j=i; j<count; j++) {
            if (ids[i] > ids[j]) {
                tempNum = ids[i];
                ids[i] = ids[j];
                ids[j] = tempNum;
            }
        }
    }

    printf("After sorting on empId, the employees are as follows:\n\n");

    // print the Id's in order
    // could've used lookOnId but this way works already
    for (int i=0; i<count; i++) {
        temp = headLL;
        while (temp != NULL) {
            if (temp->empId == ids[i]) {

                // print desired employee
                printf("Employee #%d\n", i+1);
                printf("\tEmployee id: %d\n", temp->empId);
                printf("\tFirst name: %s\n", temp->fname);
                printf("\tLast name: %s\n", temp->lname);
                printf("\tDependants [%d]: ", temp->numDependents);
                for (int j=0; j<temp->numDependents; j++) {
                    if ((j >= ((temp->numDependents)-1))) {
                        printf("%s", temp->dependents[j]);
                    }
                    else {
                        printf("%s, ", temp->dependents[j]);
                    }
                }
                printf("\n\n");
            }
            temp = temp->nextEmployee;
        }
    }

    // free the temporary array of Ids
    free(ids);
}