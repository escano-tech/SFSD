#ifndef ALLOUERBLOCKSCONTIGUE_H
#define ALLOUERBLOCKSCONTIGUE_H
#include <stdio.h>
#include <string.h>
#include "datatype.h"
#include <stdio.h>
#include <string.h>
#include "datatype.h"

// Fonction pour allouer des blocs contigus dans la mémoire secondaire
int allouerBlocsContigus(SecondaryMemory *memory, Metadata *fichier, int nombreBlocs) {
    int start_block = -1;
    int contiguous_blocks = 0;

    // Rechercher une séquence de blocs libres contigus
    for (int i = 0; i < memory->total_blocks; i++) {
        if (memory->table[i].is_free) {
            if (contiguous_blocks == 0) {
                start_block = i; // Début de la séquence de blocs libres
            }
            contiguous_blocks++;
            if (contiguous_blocks == nombreBlocs) {
                break; // On a trouvé suffisamment de blocs contigus
            }
        } else {
            contiguous_blocks = 0; // Réinitialiser si un bloc occupé est trouvé
        }
    }

    // Si on a trouvé suffisamment de blocs contigus
    if (contiguous_blocks == nombreBlocs) {
        // Allouer les blocs
        for (int i = start_block; i < start_block + nombreBlocs; i++) {
            memory->table[i].is_free = 0; // Marquer le bloc comme occupé
            strcpy(memory->table[i].filename, fichier->nom); // Associer le nom du fichier au bloc
            memory->table[i].nb_enreg = 0; // Initialiser le nombre d'enregistrements à 0
        }

        // Mettre à jour les métadonnées du fichier
        fichier->adresse_premier_bloc = start_block;
        fichier->taille_blocs = nombreBlocs;
        fichier->nb = nombreBlocs;

        // Mettre à jour le nombre de blocs libres
        memory->free_blocks -= nombreBlocs;

        return 1; // Succès
    } else {
        return 0; // Échec (pas assez de blocs contigus disponibles)
    }
}
#endif