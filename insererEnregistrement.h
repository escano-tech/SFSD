#ifndef INSERERENREGESTRIMENT_H
#define INSERERENREGESTRIMENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

// fonction pour ins�rer les enregistrements dans des blocs adjacents de mani�re tri�e ou non tri�e
void insererEnregistrement(SecondaryMemory *memory, Metadata *fichier, BlockData enreg, const char *organisationInterne) {
    FILE *file = fopen(memory->filename, "r+b");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier de memoire");
        return;
    }

    int i, j;
    int nombreEnregistrementsParBloc = sizeof(Bloc) / sizeof(BlockData);

    if (strcmp(organisationInterne, "triee") == 0) {
        // Insertion tri�e
        for (i = fichier->adresse_premier_bloc; i < fichier->adresse_premier_bloc + fichier->taille_blocs; i++) {
            Bloc block;
            fseek(file, i * sizeof(Bloc), SEEK_SET);
            fread(&block, sizeof(Bloc), 1, file);

            for (j = 0; j < nombreEnregistrementsParBloc; j++) {
                if (block.data[j].id == 0 || block.data[j].id > enreg.id) {
                    // D�caler les enregistrements suivants
                    memmove(&block.data[j + 1], &block.data[j], (nombreEnregistrementsParBloc - j - 1) * sizeof(BlockData));
                    block.data[j] = enreg;
                    fseek(file, i * sizeof(Bloc), SEEK_SET);
                    fwrite(&block, sizeof(Bloc), 1, file);
                    printf("Enregistrement ins�r� de maniere triee dans le bloc %d, position %d.\n", i, j);
                    fclose(file);
                    return;
                }
            }
        }
    } else {
        // Insertion non tri�e
        for (i = fichier->adresse_premier_bloc; i < fichier->adresse_premier_bloc + fichier->taille_blocs; i++) {
            Bloc block;
            fseek(file, i * sizeof(Bloc), SEEK_SET);
            fread(&block, sizeof(Bloc), 1, file);

            for (j = 0; j < nombreEnregistrementsParBloc; j++) {
                if (block.data[j].id == 0) {  // Trouver une position libre
                    block.data[j] = enreg;
                    fseek(file, i * sizeof(Bloc), SEEK_SET);
                    fwrite(&block, sizeof(Bloc), 1, file);
                    printf("Enregistrement insere dans le bloc %d, position %d.\n", i, j);
                    fclose(file);
                    return;
                }
            }
        }
    }

    printf("Erreur : espace insuffisant pour inserer l'enregistrement.\n");
    fclose(file);
}

#endif