#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "types.h"
#include "book.h"
#include "utilities.h"

extern int currentSize;

int main() {

    readFromFile();
    char selection[20];
    int i;
    int choice;

    puts("FriendsBook application main menu.");
    puts("Enter your choice:");
    puts("      1. Insert a new entry");
    puts("      2. Display All Entry");
    puts("      3. Search by First Name");
    puts("      4. Search by Last Name");
    puts("      5. Search by Mobile Number");
    puts("      6. Delete a contact (by Mobile Number)");
    puts("      7. Save Database");
    puts("      8. Exit");

    do {
        printf("Enter your choice: ");
        scanf(" %[^\n]s", selection);
        choice = atoi(selection);
    } while (choice < 1 || choice > 8);

    switch(choice)
    {
        case 1:
            addEntry();
            break;
        case 2:
            for(i=0; i<currentSize; i++) {
                display(i);
                puts(""); // extra new line
            }
            break;
        case 3:
            printf("Enter first name to search: ");
            scanf(" %[^\n]s", selection);
            search(selection, FIRST_NAME);
            break;
        case 4:
            printf("Enter last name to search: ");
            scanf(" %[^\n]s", selection);
            search(selection, LAST_NAME);
            break;
        case 5:
            printf("Enter mobile number to search: ");
            scanf(" %[^\n]s", selection);
            search(selection, MOBILE_NUMBER);
            break;
        case 6:
            break;
        case 7:
            saveToFile();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
    }

    //   // addEntry();
//
//   // saveToFile();
//   readFromFile();
//   printf("%d\n", currentSize);
//
//    display(0);
//
    return 0;
}

