#ifndef bdd
#define bdd

// Lecture du fichier
personne* readActeurs();
personne* readRealisateurs();
film* readFilms();

// Gestion à faire en mémoire
personne* getPersonneById(int id, personne* tab, int taille);

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
