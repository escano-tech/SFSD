#ifndef INITIALIZEMEMORY_H
#define INITIALIZEMEMORY_H

#include "datatype.h"

void initialize_memory(const char *memory_filename, int total_blocks) {
    FILE *file = fopen(memory_filename, "wb");
    if (!file) {
        perror("Error opening memory file");
        exit(1);
    }

    // Initialize all blocks as free
    Bloc block;
    block.is_free = 1;
    strcpy(block.filename, "");

    for (int i = 0; i < total_blocks; i++) {
        fwrite(&block, sizeof(Bloc), 1, file);
    }

    fclose(file);
    printf("Secondary memory file '%s' initialized with %d blocks.\n", memory_filename, total_blocks);
}

#endif