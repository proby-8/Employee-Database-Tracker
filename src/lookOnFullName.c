#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]) {
    int count = 1;
    a3Emp *temp = headLL;
    char tempString[100];
    char firstName [MAX_LENGTH];
    char lastName [MAX_LENGTH];
    char *token;
    char wholeName[MAX_LENGTH];
    char givenWholeName[MAX_LENGTH];

    // if LL is null
    if (temp == NULL) {
        return -1;
    }

    // accounts for empty string
    if (strcmp(whichName, "") == 0) {
        return -1;
    }

    // this is for counting words
    strcpy(tempString, whichName);

    // break apart chars by newlines and spaces
    token = strtok(tempString, " \n");
    strcpy(firstName, token);
    while (token != NULL) {
        strcpy(lastName, token);
        token = strtok(NULL, " \n");
    }

    // we now have the whole name without any spaces
    strcpy(givenWholeName, firstName);
    strcat(givenWholeName, lastName);

    while (temp != NULL) {
        // get whole name of each LL without any spaces
        strcpy(wholeName, temp->fname);
        strcat(wholeName, temp->lname);

        // compare the two names, return position if equal
        if ((strcmp(givenWholeName, wholeName) == 0)) {
            return count;
        }

        count++;
        temp = temp->nextEmployee;
    }

    return -1;
}
