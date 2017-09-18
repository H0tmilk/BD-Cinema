#ifndef BDD_H
#define BDD_H

#include <stdlib.h>
#include <stdio.h>

#include "data-struct.h"

// Lecture du fichier
personnes* readActeurs();
personnes* readRealisateurs();
Films* readFilms(personnes* acteurs,  personnes* reals);

// Gestion à faire en mémoire
personne* getPersonneById(int id, personne* tab, int taille);

void afficherFilm(film);
void afficherFilmPtr(film*);
void afficherFilms(Films*);
void afficherPersonne(personne);
void afficherPersonnes(personnes*);

film* searchFilm(int id, film* films, int taille);
film* searchFilmByName( char*, film*, int taille);
personne rechercherActeur(char* acteur);
personne rechecherReal(char* real);

void libererPersonnes(personnes* p);
void libererFilms(Films* f);

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
