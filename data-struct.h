#ifndef data-struct
#define data-struct

// On se limite aux genres que nous utiliserons
typedef enum Genre {ACTION=0, HORREUR, COMEDIE, DOCUMENTAIRE, POLICIER, DRAME, ANIMATION,SCIENCEFICTION} Genre;

// On se limite aux nations que nous utiliserons
typedef enum Nation{FRANCE = 0, USA, UK, CANADA} Nation;

typedef struct date {
    int annee;
    int mois;
    int jour;
} date;

typedef struct personne {
    unsigned int id;
    char* nom;
    char* prenom;
    date naissance;
    Nation nation;
} personne;


typedef struct film {
    unsigned int id;
    char* titre;
    int an_sortie;
    personne* real;
    personne* acteurs[3];
    int duree;
    Genre genre;
} film;

typedef struct personnes{
    personne* pers;
    int taille;
} personnes;

typedef struct Films{
    film* film;
    int taille;
} Films;

#endif
