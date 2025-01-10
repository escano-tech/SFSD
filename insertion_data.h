#ifndef INSERTION_DATA_H
#define INSERTION_DATA_H

#include "datatype.h"

void insertion_data(const char *memory_filename, const char *filename, BlockData enreg) {
    // Open the .dat file for appending
    char dat_filename[100];
    snprintf(dat_filename, sizeof(dat_filename), "%s.dat", filename);

    FILE *dat_file = fopen(dat_filename, "ab");
    if (!dat_file) {
        perror("Error opening .dat file");
        return;
    }

    // Write the record to the .dat file
    fwrite(&enreg, sizeof(BlockData), 1, dat_file);
    fclose(dat_file);

    printf("Record inserted into file '%s'.\n", dat_filename);
}

#endif