#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data-struct.h"

#define MAX 100


personne* getPersonneById(int id, personne* tab, int taille){
    int i;
    for( i=0;i<taille;++i){
        printf("%d ",tab[i].id);
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
        int i=0,j=0;
        while(fgets(chaine,MAX,fichier)!=NULL){
            pers = realloc(pers,(i+1)*sizeof(personne));

            char* mot;
            // id
            mot = strtok(chaine,";");
            pers[i].id=(unsigned int) strtol(mot,(char**)NULL,10);
            printf("%d : ",pers[i].id);

            // nom
            mot = strtok(NULL,";");
            pers[i].nom = mot;
            printf("%s, ",pers[i].nom);

            // prenom
            mot = strtok(NULL,";");
            pers[i].prenom = mot;
            printf("%s, ",pers[i].prenom);

            // jour
            mot = strtok(NULL,"/");
            pers[i].naissance.jour = (unsigned int) strtol(mot,(char**)NULL,10);
            printf(" Naissance = %d/",pers[i].naissance.jour);
            // mois
            mot = strtok(NULL,"/");
            pers[i].naissance.mois = (unsigned int) strtol(mot,(char**)NULL,10);
            printf("%d/",pers[i].naissance.mois);

            // année
            mot = strtok(NULL,";");
            pers[i].naissance.annee = (unsigned int) strtol(mot,(char**)NULL,10);
            printf("%d, ",pers[i].naissance.annee);


            // Nation
            mot = strtok(NULL,";");

            pers[i].nation = (unsigned int) strtol(mot,(char**)NULL,10);
            printf("Nation = %d",pers[i].nation);

            printf("\n");
            j++;
        }
        fclose(fichier);

        personnes* p = malloc(sizeof(personnes));
        p->pers = pers;
        p->size =j;

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
        int i=0,j=0;
        while(fgets(chaine,MAX,fichier)!=NULL){
            pers = realloc(pers,(i+1)*sizeof(personne));

            char* mot;
            // id
            mot = strtok(chaine,";");
            pers[i].id=(unsigned int) strtol(mot,(char**)NULL,10);
            printf("%d : ",pers[i].id);

            // nom
            mot = strtok(NULL,";");
            pers[i].nom = mot;
            printf(" %s, ",pers[i].nom);

            // prenom
            mot = strtok(NULL,";");
            pers[i].prenom = mot;
            printf("%s, ",pers[i].prenom);

            // jour
            mot = strtok(NULL,"/");
            pers[i].naissance.jour = (unsigned int) strtol(mot,(char**)NULL,10);
            printf(" Naissance = %d/",pers[i].naissance.jour);
            // mois
            mot = strtok(NULL,"/");
            pers[i].naissance.mois = (unsigned int) strtol(mot,(char**)NULL,10);
            printf("%d/",pers[i].naissance.mois);

            // année
            mot = strtok(NULL,";");
            pers[i].naissance.annee = (unsigned int) strtol(mot,(char**)NULL,10);
            printf("%d, ",pers[i].naissance.annee);

            // Nation
            mot = strtok(NULL,";");
            pers[i].nation = (Nation) ((unsigned int) strtol(mot,(char**)NULL,10));
            printf("Nation = %d",pers[i].nation);

            printf("\n");
            j++;
        }
        fclose(fichier);

        personnes* p = malloc(sizeof(personnes));
        p->pers = pers;
        p->size =j;

        return p;
    }
    else {
        printf("Erreur d'ouverture du fichier");
    }
    return NULL;
}

film* readFilms(personnes* acteurs, personnes* reals){
    FILE* fichier = NULL;
    fichier = fopen("films.csv","r");
    film* films = malloc(sizeof(film));

    char chaine[MAX];

    if(fichier != NULL){
        int i=0;
        while(fgets(chaine,MAX,fichier)!=NULL){
            films = realloc(films,(i+1)*sizeof(film));

            char* mot;
            // id
            mot = strtok(chaine,";");
            films[i].id=(unsigned int) strtol(mot,(char**)NULL,10);
            printf("%d : ",films[i].id);

            // titre
            mot = strtok(NULL,";");
            films[i].titre = mot;
            printf("Nom = %s, ",films[i].titre);

            // sortie
            mot = strtok(NULL,";");
            films[i].an_sortie=(unsigned int) strtol(mot,(char**)NULL,10);
            printf("sortie = %d,",films[i].an_sortie);

           // real
            mot = strtok(NULL,";");
            films[i].real = getPersonneById((unsigned int) strtol(mot,(char**)NULL,10), reals->pers, reals->size);
            if(films[i].real !=NULL){
                printf(" Real = %s/",films[i].real->nom);
            }
            // acteur 1
 /*
            mot = strtok(NULL,",");
            films[i].acteurs[0] = getPersonneById((unsigned int) strtol(mot,(char**)NULL,10), acteurs->pers,acteurs->size);
            printf("%s/",films[i].acteurs[0]->nom);
*/
            // durée
            mot = strtok(NULL,";");
            printf("%s,",mot);


            mot = strtok(NULL,";");
            films[i].duree = (int) strtol(mot,(char**)NULL,10);
            printf("%d, ",films[i].duree);

            // Genre
            mot = strtok(NULL,";");
            films[i].genre = (Genre) ((int) strtol(mot,(char**)NULL,10));
            printf("Genre = %d",films[i].genre);

            printf("\n");
        }
        fclose(fichier);
        return films;
    }
    else {
        printf("Erreur d'ouverture du fichier");
    }
    return NULL;
}

