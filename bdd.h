#ifndef BDD_H
#define BDD_H

#include <stdlib.h>
#include <stdio.h>

#include "data-struct.h"

// Lecture du fichier
personnes* readActeurs();
personnes* readRealisateurs();
film* readFilms();

// Gestion à faire en mémoire
personne* getPersonneById(int id, personne* tab, int taille);

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
