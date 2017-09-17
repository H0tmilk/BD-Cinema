#ifndef BDD_H
#define BDD_H

#include <stdlib.h>
#include <stdio.h>

#include "data_struct.h"

// Lecture du fichier
void readActeurs(personne*);
void readRealisateurs(personne*);
void readFilms(film*);

// Gestion à faire en mémoire
personne* getActeurById(int);
personne* getRealById(int);

void afficherFilm(film);
void afficherNation(Nation);
void afficherPersonne(personne);

film rechercherFilm(char* film);
personne rechercherActeur(char* acteur);
personne rechecherReal(char* real);

// void ajouterFilm();
// void supprimerActeur();
// void ajouterRealisateur();
// void supprimerRealisateur();
// void supprimerFilm();

// Ecriture fichiers
// void sauvegarderFilms();
// void sauvegarderActeurs();
// void sauvegarderReals();

#endif
