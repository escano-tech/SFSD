#ifndef DISPLAY_METADATA_H
#define DISPLAY_METADATA_H

#include "datatype.h"

void displayMetadata(const char *filename) {
    char dat_filename[100];
    snprintf(dat_filename, sizeof(dat_filename), "%s.dat", filename);

    FILE *dat_file = fopen(dat_filename, "rb");
    if (!dat_file) {
        perror("Error opening .dat file");
        return;
    }

    BlockData enreg;
    int recordCount = 0;

    while (fread(&enreg, sizeof(BlockData), 1, dat_file)) {
        recordCount++;
    }

    fclose(dat_file);

    printf("\nMetadata for file '%s':\n", filename);
    printf("Number of records: %d\n", recordCount);
}

#endif