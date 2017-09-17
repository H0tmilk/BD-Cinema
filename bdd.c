#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data-struct.h"

#define MAX 100


personne* getPersonneById(int id, personne* tab, int taille){
    int i;
    for( i=0;i<taille;++i){
        if(tab[i].id == id){
            return &tab[i];
        }
    }
    return NULL;
}

personnes* readActeurs(){
    FILE* fichier = NULL;
    fichier = fopen("acteurs.csv","r");
    personne* pers = malloc(sizeof(personne));
    char chaine[MAX];

    if(fichier != NULL){
        int i=0;
        while(fgets(chaine,MAX,fichier)!=NULL){
            pers = realloc(pers,(i+1)*sizeof(personne));

            char* mot;
            // id
            mot = strtok(chaine,";");
            pers[i].id=(unsigned int) strtol(mot,(char**)NULL,10);

            // nom
            mot = strtok(NULL,";");
            pers[i].nom =(char*) malloc((strlen(mot)+1)*sizeof(char));
            strcpy(pers[i].nom,mot);

            // prenom
            mot = strtok(NULL,";");
            pers[i].prenom=(char*) malloc((strlen(mot)+1)*sizeof(char));
            strcpy(pers[i].prenom , mot);

            // jour
            mot = strtok(NULL,"/");
            pers[i].naissance.jour = (unsigned int) strtol(mot,(char**)NULL,10);
            // mois
            mot = strtok(NULL,"/");
            pers[i].naissance.mois = (unsigned int) strtol(mot,(char**)NULL,10);

            // ann�e
            mot = strtok(NULL,";");
            pers[i].naissance.annee = (unsigned int) strtol(mot,(char**)NULL,10);


            // Nation
            mot = strtok(NULL,";");

            pers[i].nation = (unsigned int) strtol(mot,(char**)NULL,10);

            i++;
        }
        fclose(fichier);


        personnes* p = malloc(sizeof(personnes));
        p->pers = pers;

        p->taille =i;

        return p;
    }
    else {
        printf("Erreur d'ouverture du fichier");
    }
    return NULL;
}

personnes* readRealisateurs(){
    FILE* fichier = NULL;
    fichier = fopen("realisateurs.csv","r");
    personne* pers = malloc(sizeof(personne));

    char chaine[MAX];

    if(fichier != NULL){
        int i=0;
        while(fgets(chaine,MAX,fichier)!=NULL){
            pers = realloc(pers,(i+1)*sizeof(personne));

            char* mot;
            // id
            mot = strtok(chaine,";");
            pers[i].id=(unsigned int) strtol(mot,(char**)NULL,10);

            // nom
            mot = strtok(NULL,";");
            pers[i].nom =(char*) malloc(strlen(mot)*sizeof(char));
            strcpy(pers[i].nom,mot);

            // prenom
            mot = strtok(NULL,";");
            pers[i].prenom=(char*) malloc(strlen(mot)*sizeof(char));
            strcpy(pers[i].prenom , mot);

            // jour
            mot = strtok(NULL,"/");
            pers[i].naissance.jour = (unsigned int) strtol(mot,(char**)NULL,10);
            // mois
            mot = strtok(NULL,"/");
            pers[i].naissance.mois = (unsigned int) strtol(mot,(char**)NULL,10);

            // ann�e
            mot = strtok(NULL,";");
            pers[i].naissance.annee = (unsigned int) strtol(mot,(char**)NULL,10);

            // Nation
            mot = strtok(NULL,";");
            pers[i].nation = (Nation) ((unsigned int) strtol(mot,(char**)NULL,10));
            i++;
        }
        fclose(fichier);

        personnes* p = malloc(sizeof(personnes));
        p->pers = pers;

        p->taille =i;

        return p;
    }
    else {
        printf("Erreur d'ouverture du fichier");
    }
    return NULL;
}

Films* readFilms(personnes* acteurs,  personnes* reals){
    FILE* fichier = NULL;
    fichier = fopen("films.csv","r");
    film* films = malloc(sizeof(film));

    char chaine[MAX];

    if(fichier != NULL){
        int i=0,j,k,l;
        char temp[MAX], *act;

        while(fgets(chaine,MAX,fichier)!=NULL){
            films = realloc(films,(i+1)*sizeof(film));

            char* mot;
            // id
            mot = strtok(chaine,";");
            films[i].id=(unsigned int) strtol(mot,(char**)NULL,10);

            // titre
            mot = strtok(NULL,";");
            films[i].titre=(char*) malloc((strlen(mot)+1)*sizeof(char));
            strcpy(films[i].titre , mot);
            // sortie
            mot = strtok(NULL,";");
            films[i].an_sortie=(unsigned int) strtol(mot,(char**)NULL,10);

           // real
            mot = strtok(NULL,";");
            films[i].real = getPersonneById((unsigned int) strtol(mot,(char**)NULL,10), reals->pers, reals->taille);

            // acteurs
            for (l = 0; l < 3; l++) {
              films[i].acteurs[l] = NULL;
            }
            mot = strtok(NULL,";");
            strcpy(temp,mot);
            mot = strtok(NULL,";");
            char* last = strtok(NULL,";");
            for (k=0, j=0; temp[k]; k++){
                 j+= (temp[k] == ',');
            }
            act = strtok(temp,",");
            for(k=0;k<=j;k++){
                films[i].acteurs[k] = getPersonneById((unsigned int) strtol(act,(char**)NULL,10), acteurs->pers,acteurs->taille);

                if(k==j-1){
                    act = strtok(NULL,";");
                }
                else if(k!=j){
                    act = strtok(NULL,",");
                }
            }

            // dur�e


            films[i].duree = (unsigned int) strtol(mot,(char**)NULL,10);

            // Genre
            films[i].genre = (Genre) ((int) strtol(last,(char**)NULL,10));

            i++;
        }

        Films* f = malloc(sizeof(Films));
        f->film = films;

        f->taille =i;
        fclose(fichier);
        return f;
    }
    else {
        printf("Erreur d'ouverture du fichier");
    }
    return NULL;
}

void libererPersonnes(personnes* p){
    int i;
    for(i=0;i<p->taille;++i){
        free(p->pers[i].nom);
        free(p->pers[i].prenom);
    }
}

film* searchFilm(int id, film* films, int taille){
    int i = 0;
    while( i<taille){
        if(films[i].id == id){
            return &films[i];
        }
        i++;
    }
    return NULL;
}

film* searchFilmByName(char* titre, Films* films, int taille){
    int i = 0;
    printf("%d", taille);
    while( i < taille){
        if(strcmp(titre, films->film[i].titre)==0){
            return &films->film[i];
        }
        i++;
    }
    return NULL;
}


void afficherFilm(film f) {
  printf("%s (%d)\n", f.titre, f.an_sortie);
  printf("Realisateur : %s %s\n", f.real->prenom, f.real->nom);
  printf("Acteurs : ");
  int i;
  for (i = 0; i < 3; i++) {
    if (f.acteurs[i] != NULL) {
      if (i != 0) {
        printf(", ");
      }
      printf("%s %s", f.acteurs[i]->prenom, f.acteurs[i]->nom);
    }
  }
  printf("\n");
  printf("Duree : %02dh%02d\n", f.duree/60, f.duree%60);
  printf("Genre : %s\n", genres[f.genre]);
}

void afficherFilmPtr(film* f) {
  printf("%s (%d)\n", f->titre, f->an_sortie);
  printf("Realisateur : %s %s\n", f->real->prenom, f->real->nom);
  printf("Acteurs : ");
  int i;
  for (i = 0; i < 3; i++) {
    if (f->acteurs[i] != NULL) {
      if (i != 0) {
        printf(", ");
      }
      printf("%s %s", f->acteurs[i]->prenom, f->acteurs[i]->nom);
    }
  }
  printf("\n");
  printf("Duree : %02dh%02d\n", f->duree/60, f->duree%60);
  printf("Genre : %s\n", genres[f->genre]);
}

void afficherFilms(Films* films) {
  int i;
  for (i = 0; i < films->taille; i++) {
    afficherFilm(films->film[i]);
    printf("\n");
  }
}

void afficherPersonne(personne p) {
  printf("Nom : %s %s\n", p.prenom, p.nom);
  printf("Date de naissance : %02d/%02d/%02d\n", p.naissance.jour, p.naissance.mois,
    p.naissance.annee);
  printf("Nationalité : %s\n", nationalites[p.nation]);
}

void afficherPersonnes(personnes* pers) {
  int i;
  for (i = 0; i < pers->taille; i++) {
    afficherPersonne(pers->pers[i]);
    printf("\n");
  }
}
