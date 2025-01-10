#ifndef COMPACTING_MEMORY_H
#define COMPACTING_MEMORY_H

#include "datatype.h"

void compacting_memory(const char *memory_filename) {
    FILE *file = fopen(memory_filename, "r+b");
    if (!file) {
        perror("Error opening memory file");
        return;
    }

    Bloc block;
    int compact_index = 0;

    for (int i = 0; i < MAX_BLOCS; i++) {
        fseek(file, i * sizeof(Bloc), SEEK_SET);
        fread(&block, sizeof(Bloc), 1, file);

        if (!block.is_free) {
            if (i != compact_index) {
                fseek(file, compact_index * sizeof(Bloc), SEEK_SET);
                fwrite(&block, sizeof(Bloc), 1, file);
            }
            compact_index++;
        }
    }

    for (int i = compact_index; i < MAX_BLOCS; i++) {
        fseek(file, i * sizeof(Bloc), SEEK_SET);
        block.is_free = 1;
        strcpy(block.filename, "");
        fwrite(&block, sizeof(Bloc), 1, file);
    }

    fclose(file);
    printf("Memory compacted.\n");
}

#endif