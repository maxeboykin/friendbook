//
// Created by Max Boykin on 5/11/22.
//

#ifndef FRIENDBOOK_BOOK_H
#define FRIENDBOOK_BOOK_H

/*array to hold our contacts */
void addEntry();
void display(int index);
void search(char *key, search_t type);
void readFromFile();
void saveToFile();

#endif //FRIENDBOOK_BOOK_H
