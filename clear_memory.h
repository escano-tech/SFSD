#ifndef CLEAR_MEMORY_H
#define CLEAR_MEMORY_H

#include "datatype.h"

void clear_memory(const char *memory_filename) {
    FILE *file = fopen(memory_filename, "wb");
    if (!file) {
        perror("Error opening memory file");
        return;
    }

    Bloc block;
    block.is_free = 1;
    strcpy(block.filename, "");

    for (int i = 0; i < MAX_BLOCS; i++) {
        fwrite(&block, sizeof(Bloc), 1, file);
    }

    fclose(file);
    printf("Memory cleared.\n");
}

#endif