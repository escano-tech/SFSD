#include <stdio.h>
#include "menu.h"
#include "initializememory.h"
#include "creerFichier.h"
#include "insertion_data.h"
#include "supplogic.h"
#include "suppphysique.h"
#include "display_status.h"
#include "display_metadata.h"
#include "clear_memory.h"
#include "compacting_memory.h"

int main() {
    const char *memory_filename = "secondary_memory.bin";
    initialize_memory(memory_filename, MAX_BLOCS);

    int choix;
    char filename[50];
    BlockData enreg;

    do {
        affichermenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                // Create a file
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter number of records: ");
                int nb_enreg;
                scanf("%d", &nb_enreg);
                creerFichier(memory_filename, filename, nb_enreg, "contigu", "non");
                break;
            case 2:
                // Insert a record
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter record data (name age occupation): ");
                scanf("%s %d %s", enreg.name, &enreg.age, enreg.occupation);
                insertion_data(memory_filename,filename, enreg);
                break;
            case 3:
                // Logical deletion
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter record index: ");
                int recordIndex;
                scanf("%d", &recordIndex);
                logicalDelete(filename, recordIndex);
                break;
            case 4:
                // Physical deletion
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter record index: ");
                scanf("%d", &recordIndex);
                physicalDelete(filename, recordIndex);
                break;
            case 5:
                // Display memory status
                display_status(memory_filename);
                break;
            case 6:
                // Display file metadata
                printf("Enter file name: ");
                scanf("%s", filename);
                displayMetadata(filename);
                break;
            case 7:
                // Clear memory
                clear_memory(memory_filename);
                break;
            case 8:
                // Compact memory
                compacting_memory(memory_filename);
                break;
            case 9:
                // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choix != 9);

    return 0;
}