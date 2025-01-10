#ifndef SUPPPHYSIQUE_H
#define SUPPPHYSIQUE_H

#include "datatype.h"
#include <unistd.h>

void physicalDelete(const char *filename, int recordIndex) {
    char dat_filename[100];
    snprintf(dat_filename, sizeof(dat_filename), "%s.dat", filename);

    FILE *dat_file = fopen(dat_filename, "r+b");
    if (!dat_file) {
        perror("Error opening .dat file");
        return;
    }

    BlockData enreg;
    int found = 0;
    long pos = 0;

    while (fread(&enreg, sizeof(BlockData), 1, dat_file)) {
        if (recordIndex == 0) {
            // Shift remaining records to fill the gap
            while (fread(&enreg, sizeof(BlockData), 1, dat_file)) {
                fseek(dat_file, pos, SEEK_SET);
                fwrite(&enreg, sizeof(BlockData), 1, dat_file);
                pos += sizeof(BlockData);
            }
            found = 1;
            break;
        }
        recordIndex--;
        pos += sizeof(BlockData);
    }

    fclose(dat_file);

    if (found) {
        // Truncate the file to remove the last record
        truncate(dat_filename, pos);
        printf("Record %d physically deleted from file '%s'.\n", recordIndex, filename);
    } else {
        printf("Error: Record %d not found in file '%s'.\n", recordIndex, filename);
    }
}

#endif