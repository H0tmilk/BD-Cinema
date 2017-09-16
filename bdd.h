#ifndef bdd
#define bdd

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
