#ifndef data-struct.h
#define dat-struct.h

// On se limite aux genres que nous utiliserons
typedef enum Genre {ACTION, HORREUR, COMEDIE, DOCUMENTAIRE, POLICIER, DRAME, ANIMATION,SCIENCEFICTION} Genre;

// On se limite aux nations que nous utiliserons
typedef enum Nation{FRANCE, USA, UK, CANADA} Nation;

typedef struct date {
    int annee;
    char mois[10];
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
    personne real;
    personne acteurs[3];
    int duree;
    Genre genre;
} film;

#endif
