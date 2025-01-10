#ifndef SUPPLOGIC_H
#define SUPPLOGIC_H

#include "datatype.h"

void logicalDelete(const char *filename, int recordIndex) {
    char dat_filename[100];
    snprintf(dat_filename, sizeof(dat_filename), "%s.dat", filename);

    FILE *dat_file = fopen(dat_filename, "r+b");
    if (!dat_file) {
        perror("Error opening .dat file");
        return;
    }

    BlockData enreg;
    int found = 0;

    while (fread(&enreg, sizeof(BlockData), 1, dat_file)) {
        if (recordIndex == 0) {
            // Mark the record as deleted (logical deletion)
            enreg.age = -1; // Use a special value to mark as deleted
            fseek(dat_file, -sizeof(BlockData), SEEK_CUR);
            fwrite(&enreg, sizeof(BlockData), 1, dat_file);
            found = 1;
            break;
        }
        recordIndex--;
    }

    fclose(dat_file);

    if (found) {
        printf("Record %d logically deleted from file '%s'.\n", recordIndex, filename);
    } else {
        printf("Error: Record %d not found in file '%s'.\n", recordIndex, filename);
    }
}

#endif