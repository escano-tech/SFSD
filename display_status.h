#ifndef DISPLAY_STATUS_H
#define DISPLAY_STATUS_H

#include "datatype.h"

void display_status(const char *memory_filename) {
    FILE *file = fopen(memory_filename, "rb");
    if (!file) {
        perror("Error opening memory file");
        return;
    }

    Bloc block;
    printf("\nMemory Status:\n");

    for (int i = 0; i < MAX_BLOCS; i++) {
        fread(&block, sizeof(Bloc), 1, file);
        printf("Block %d: %s\n", i, block.is_free ? "Free" : "Occupied");
    }

    fclose(file);
}

#endif