#ifndef bdd.h
#define bdd.h

// Lecture du fichier
personne* readActeurs();
personne* readRealisateurs();
film* readFilms();

// Gestion à faire en mémoire
personne* getActeurById(int);
personne* getRealById(int);

void afficherFilm(film);
void afficherNation();
void afficherPersonne();

void ajouterFilm();
void supprimerActeur();
void ajouterRealisateur();
void supprimerRealisateur();
void supprimerFilm();

// Ecriture fichiers
void sauvegarderFilms();
void sauvegarderActeurs();
void sauvegarderReals();

#endif
