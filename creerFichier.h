#ifndef CREERFICHIER_H
#define CREERFICHIER_H

#include "datatype.h"

void creerFichier(const char *memory_filename, const char *nom, int nombreEnregistrements, const char *organisationGlobale, const char *organisationInterne) {
    // Create a physical .dat file on the computer
    char dat_filename[100];
    snprintf(dat_filename, sizeof(dat_filename), "%s.dat", nom);

    FILE *dat_file = fopen(dat_filename, "wb");
    if (!dat_file) {
        perror("Error creating .dat file");
        return;
    }
    fclose(dat_file);
    printf("Physical file '%s' created successfully.\n", dat_filename);

    // Open the secondary memory file
    FILE *memory_file = fopen(memory_filename, "r+b");
    if (!memory_file) {
        perror("Error opening memory file");
        return;
    }

    // Calculate the number of blocks needed
    int nombreBlocs = (nombreEnregistrements + 3) / 4; // 4 records per block

    // Search for contiguous free blocks
    int start_block = -1;
    int contiguous_blocks = 0;
    Bloc block;

    for (int i = 0; i < MAX_BLOCS; i++) {
        fseek(memory_file, i * sizeof(Bloc), SEEK_SET);
        fread(&block, sizeof(Bloc), 1, memory_file);

        if (block.is_free) {
            if (contiguous_blocks == 0) {
                start_block = i;
            }
            contiguous_blocks++;
            if (contiguous_blocks == nombreBlocs) {
                break;
            }
        } else {
            contiguous_blocks = 0;
        }
    }

    if (contiguous_blocks == nombreBlocs) {
        // Allocate the blocks
        for (int i = start_block; i < start_block + nombreBlocs; i++) {
            fseek(memory_file, i * sizeof(Bloc), SEEK_SET);
            block.is_free = 0;
            strcpy(block.filename, nom);
            fwrite(&block, sizeof(Bloc), 1, memory_file);
        }

        printf("File '%s' allocated %d blocks in secondary memory.\n", nom, nombreBlocs);
    } else {
        printf("Error: Not enough contiguous blocks available for file '%s'.\n", nom);
    }

    fclose(memory_file);
}

#endif