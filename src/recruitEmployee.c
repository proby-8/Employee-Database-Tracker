#include "../include/headerA3.h"
#include <time.h>

void recruitEmployee (struct employee ** headLL) {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char more;
    int dependentNum = 1;
    int empId = 0;
    int repeat = 1;
    char tempString[MAX_LENGTH];
    int tryAgain = 1;
    int power = 1;
    int random;

    a3Emp *loop = *headLL;
    a3Emp *newNode = NULL;
    a3Emp *temp = *headLL;

    // allocate space for the struct
    newNode = malloc(sizeof(a3Emp));

    // employee name
    printf("Enter the first name of the employee: ");
    scanf("%s", firstName);
    printf("Enter the last name of the employee: ");
    scanf("%s", lastName);
    
    // allocate space for the dependents array
    newNode->dependents = malloc(sizeof(char *) * dependentNum);

    // for each new dependent
    while (repeat) {
        // allocate space for the char array and set it to desired name
        newNode->dependents = realloc(newNode->dependents, sizeof(char *) * dependentNum);
        printf("\nEnter name of dependent# %d: ", dependentNum);
        scanf("%s", tempString);
        newNode->dependents[dependentNum-1] = malloc(sizeof(char) * (strlen(tempString) + 1));
        strcpy((newNode->dependents[dependentNum-1]), tempString);
        
        // ask if there are any more dependents
        while ((getchar()) != '\n');
        printf("Do you have any more dependents? ");
        scanf("%c", &more);

        // if they say yes, stop repeating
        if ((more != 'y') && (more != 'Y')) {
            repeat = 0;
        }
        // if they say no, increase count of dependents
        else {
            dependentNum++;
        }
    }

    // display number of dependents
    printf("\nYou have %d dependents.\n", dependentNum);

    // generate empId
    for (int i=0; i<strlen(firstName); i++) {
        empId += firstName[i];
    }
    empId += strlen(lastName);

    // check if unique
    while (tryAgain) {
        tryAgain = 0;
        while (loop != NULL) {
            if (empId == loop->empId) {
                random = (rand() % 1000);
                while (random >= power) {
                    power *= 10;
                }
                empId = (empId*power) + (rand() % 1000);
                tryAgain = 1;
            }
            loop = loop->nextEmployee;
        }
    }


    printf("\nYour computer-generated empId is %d\n\n", empId);

    // set first and last name
    strcpy(newNode->fname, firstName);
    strcpy(newNode->lname, lastName);

    // set empId and number of dependents
    newNode->empId = empId;
    newNode->numDependents = dependentNum;

    // set nextEmployee to null as it is at the end of the list
    newNode->nextEmployee = NULL;

    // account for LL being empty
    if (!(*headLL)) {
        *headLL = newNode;
    }
    else {
        // set this node to the last position
        while (temp->nextEmployee != NULL) {
            temp = temp->nextEmployee;
        }
        temp->nextEmployee = newNode;
    }

    while ((getchar()) != '\n');
}
