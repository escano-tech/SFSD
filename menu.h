#ifndef MENU_H
#define MENU_H

#include <stdio.h>

void affichermenu() {
    printf("\n====== Main Menu ======\n");
    printf("1. Create File\n");
    printf("2. Insert Record\n");
    printf("3. Delete Record (Logical)\n");
    printf("4. Delete Record (Physical)\n");
    printf("5. Display Memory Status\n");
    printf("6. Display File Metadata\n");
    printf("7. Clear Memory\n");
    printf("8. Compact Memory\n");
    printf("9. Exit\n");
    printf("=======================\n");
    printf("Choose an option: ");
}

#endif