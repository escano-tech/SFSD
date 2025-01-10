#ifndef SAVE_ALLOCATION_TABLE_H
#define SAVE_ALLOCATION_TABLE_H
#include <stdio.h>
#include <string.h>
#include "datatype.h"

void save_allocation_table(SecondaryMemory *memory) {
    FILE *file = fopen("allocation_table.bin", "wb");
    if (!file) {
        perror("Erreur lors de la création du fichier de table de mémoire");
        return;
    }

    fwrite(memory->table, sizeof(MemoryTableEntry), memory->total_blocks, file);
    fclose(file);
}
#endif