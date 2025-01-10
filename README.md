# Simulateur Simplifié de Système de Gestion de Fichiers (SGF)

## Contexte
Ce projet modélise un système de gestion de fichiers (SGF), composant essentiel des systèmes d'exploitation, en développant un simulateur simplifié. Il permet de reproduire les principes fondamentaux de la gestion des fichiers tels que l'organisation de la mémoire secondaire, la gestion des métadonnées et les opérations courantes sur les fichiers.

## Fonctionnalités Principales
1. **Gestion de la Mémoire Secondaire (MS) :**
   - Initialisation et allocation en blocs.
   - Modes d'organisation : contiguë ou chaînée.
   - Compactage pour réduire la fragmentation.
   - Visualisation graphique des blocs (libres/occupés).

2. **Fichiers de Données :**
   - Création et configuration des fichiers (nom, taille, organisation).
   - Insertion, recherche, suppression (logique/physique).
   - Défragmentation des fichiers.

3. **Fichiers de Métadonnées :**
   - Informations sur les fichiers (nom, taille, adresse, etc.).
   - Mises à jour automatiques après chaque opération.

4. **Interface Interactive :**
   - Menu pour accéder aux différentes fonctionnalités.
   - Affichage graphique de l'état de la mémoire et des fichiers.

## Structure du Code
Le projet est structuré en plusieurs modules :
- **main.c** : Point d'entrée du programme avec la boucle du menu principal.
- **memory.h** : Gestion de la mémoire secondaire et des tables d'allocation.
- **file.h** : Opérations sur les fichiers de données et leurs métadonnées.
- **utils.c / utils.h** : Fonctions utilitaires pour affichage et gestion des erreurs.

## Comment Exécuter le Projet
1. **Prérequis :**
   - Un compilateur C (GCC recommandé).
   - Un environnement compatible (Linux, Windows avec MinGW, ou MacOS).

2. **Étapes :**
   - Clonez le dépôt GitHub :
     ```bash
     git clone https://github.com/Agoudjiliss/SFSD-Project.git
     cd SFSD-Project
     ```
   - Compilez le code :
     ```bash
     gcc main.c -o main
     ```
   - Exécutez le programme :
     ```bash
     ./main
     ```

3. **Utilisation :**
   - Suivez les instructions affichées dans le menu interactif pour explorer les fonctionnalités.

## Fonctionnalités Futures
- Ajout de nouveaux modes d'organisation des fichiers.
- Visualisation des tables d'allocation sous forme graphique avancée.
- Support pour la gestion de fichiers non structurés.

## Contributions
Les contributions sont les bienvenues ! Pour signaler un problème ou proposer une amélioration :
- Créez une *issue* ou soumettez une *pull request*.

## Auteurs
Issam Agoudjil
Lakri Abdeldjalil Mohamed Reda
Anes Ragoub
ines Nadji
Mahfi Marwa 
abdarahman machaal ....
Anes Halimi

Projet réalisé sous la supervision de LAHRECHE Abdelmadjid.

