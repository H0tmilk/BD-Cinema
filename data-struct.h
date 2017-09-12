typedef enum Genre {ACTION, HORREUR, COMEDIE, DOCUMENTAIRE, POLICIER, DRAME, ANIMATION,SCIENCEFICTION} Genre;

typedef enum Nation{FRANCE} Nation;

typedef struct date{
    int annee;
    int mois;
    int jour;
} date;

typedef struct personne{
    char* nom;
    char* prenom;
    date naissance;
    Nation nation;
} personne;


typedef struct film {
    char* titre;
    int an_sortie;
    personne *real;
    personne** acteurs;
    int duree;
    Genre genre;
} film;
