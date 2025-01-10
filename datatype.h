#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCS 100
#define BLOCK_SIZE 1024

// Structure for a record
typedef struct {
    char name[50];
    int age;
    char occupation[50];
} BlockData;

// Structure for a block
typedef struct {
    int is_free; // 1 if free, 0 if occupied
    BlockData data; // Data stored in the block
    char filename[50]; // Name of the file associated with the block
    int nb_enreg; // Number of records in the block
} Bloc;

// Structure for file metadata
typedef struct {
    char nom[50]; // File name
    int taille_blocs; // Size in blocks
    int taille_enreg; // Size in records
    int adresse_premier_bloc; // Address of the first block
    char mode_globale[10]; // Global organization mode (contigu/chaîné)
    char mode_interne[10]; // Internal organization mode (trié/non trié)
} Metadata;

// Structure for the memory allocation table
typedef struct {
    int block_number; // Block number
    int is_free; // 1 if free, 0 if occupied
    char filename[50]; // Name of the file associated with the block
    int nb_enreg; // Number of records in the block
} MemoryTableEntry;

// Structure for secondary memory
typedef struct {
    char filename[50]; // Name of the memory file
    int total_blocks; // Total number of blocks
    int free_blocks; // Number of free blocks
    MemoryTableEntry table[MAX_BLOCS]; // Memory allocation table
    Bloc ms[MAX_BLOCS]; // Secondary memory (blocks)
} SecondaryMemory;

#endif // DATATYPE_H