#ifndef BDD_H
#define BDD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "data_struct.h"

// Lecture du fichier
personnes* readActeurs();
personnes* readRealisateurs();
Films* readFilms(personnes*,  personnes*);

// Gestion à faire en mémoire
personne* getPersonneById(int, personne*, int);

void afficherFilm(film);
void afficherFilmPtr(film*);
void afficherFilms(Films*);
void afficherPersonne(personne);
void afficherPersonnePtr(personne* p);
void afficherPersonnes(personnes*);

film* searchFilm(int, film*, int);
film* searchFilmByName(char*, film*, int);
personne* searchPersonneByName(char*, personne*, int);

// Liberations mémoire
void libererPersonnes(personnes*);
void libererFilms(Films*);

#endif
