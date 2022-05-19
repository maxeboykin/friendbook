//
// Created by Max Boykin on 5/11/22.
//

#ifndef FRIENDBOOK_TYPES_H
#define FRIENDBOOK_TYPES_H

/* structure to hold the information of a single contact */
typedef struct {
    int id;
    char firstName[45];
    char lastName[65];
    char mobileNumber[20];
    int birthdayMonth[10];
    int birthdayDay[10];
    int birthdayYear[10];

} Contact;

typedef enum { FIRST_NAME, LAST_NAME, MOBILE_NUMBER } search_t;

#endif //FRIENDBOOK_TYPES_H


