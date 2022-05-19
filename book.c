//
// Created by Max Boykin on 5/11/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "types.h"
#include "book.h"
#include "utilities.h"

#define MAX_SIZE 100
Contact phonebook[MAX_SIZE];
/*current size of the phonebook array */
int currentSize = 0;

void addEntry()
{
    if(currentSize == MAX_SIZE) {
        puts("Error: phonebook is full");
        return;
    }

    Contact c;
    printf("Enter First Name: ");
    scanf(" %[^\n]s", &c.firstName);
    printf("Enter Last Name: ");
    scanf(" %[^\n]s", &c.lastName);
    printf("Enter phone number (no spaces or special characters: ");
    scanf(" %[^\n]s", &c.mobileNumber);
    printf("Add birthday month\nJanuary [1]\nFebruary [2]\nMarch [3]\nApril [4]\nMay [5]\nJune [6]\nJuly [7]\nAugust [8]\nSeptember [9]\nOctober [10]\nNovember [11]\nDecember [12]\n");
    scanf(" %[^\n]s", c.birthdayMonth);
    printf("Birthday day of the month: (1-31)");
    scanf(" %[^\n]s", c.birthdayDay);
    printf("Year of birth: ");
    scanf(" %[^\n]s", c.birthdayYear);
    phonebook[currentSize] = c;
    ++currentSize;
}

void display(int index)
{
    if(index < 0 || index >= currentSize) {
        puts("Error: invalid index!");
        return;
    }

    Contact c = phonebook[index];
    printf("First Name: %s\n", c.firstName);
    printf("Last Name: %s\n", c.lastName);
    printf("Mobile Number: %s\n", c.mobileNumber);
    printf("Birthday: %s %s %s", c.birthdayMonth, c.birthdayDay, c.birthdayYear);
}


/*CAUTION this function modifies the given string  */
void search(char *key, search_t type)
{
    int found = 0;
    int i;

    strtolower(key);
    char content[41];

    if(type == FIRST_NAME) { //search by first name
        for (i=0; i<currentSize; i++){
            strcpy(content, phonebook[i].firstName);
            strtolower(content);
            if(strcmp(content, key) == 0){
                display(i);
                found = 1;
            }
        }
    }
    else if(type == LAST_NAME) { // search by last name
        for (i=0; i<currentSize; i++){
            strcpy(content, phonebook[i].lastName);
            strtolower(content);
            if(strcmp(content, key) == 0){
                display(i);
                found = 1;
            }
        }
    }
    else if(type == MOBILE_NUMBER) { //search by mobile number
        for (i=0; i<currentSize; i++){
            strcpy(content, phonebook[i].mobileNumber);
            strtolower(content);
            if(strcmp(content, key) == 0){
                display(i);
                found = 1;
            }
        }
    }
    else {
        puts("Error: invalid search type!");
        return;
    }
    if(!found) {
        puts("Not found in phone book");
    }
}

void readFromFile()
{
    FILE *fp;
    if((fp = fopen("friendsbook.db", "rb")) == NULL) {
        puts("Error: can't load the database file");
        return;
    }
    /*read the size of the friends book */
    if(fread(&currentSize, sizeof(currentSize), 1, fp) != 1) {
        puts("Error: can't read the data");
        return;
    }
    /*read the actual friendsbook content */
    if(fread(phonebook, sizeof(phonebook), 1, fp) != 1) {
        puts("Error: can't read the data");
        return;
    }
}

void saveToFile()
{
    FILE *fp;
    if( (fp = fopen("friendsbook.db", "wb")) == NULL ) {
        puts("Error: can't create a database file!");
        return;
    }
    /* save the current size of the friends book */
    if (fwrite(&currentSize, sizeof(currentSize), 1, fp) != 1) {
        puts("Error: cant save data!");
        return;
    }
    /* save the friends book contents */
    if(fwrite(phonebook, sizeof(phonebook), 1, fp) != 1) {
        puts("Error: can't save data!");
        return;
    }

}