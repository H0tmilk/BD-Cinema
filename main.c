// Librairie SDL au cas où le temps le permettrait
//#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "data-struct.h"
#include "bdd.h"


int main( int argc, char* args[] )
{
    printf("Acteurs : \n");
    personnes* acteurs = readActeurs();

    printf("\nReal : \n");
    personnes* real = readRealisateurs();

    printf("\n Films :\n");
    Films* films = readFilms(acteurs, real );

    printf("\nRecherche\n");

    film* f = searchFilm(1,films->film,films->taille);
    printf("Le film avec l'id %d a pour titre %s",f->id,f->titre);


    libererPersonnes(acteurs);
    libererPersonnes(real);
    free(acteurs);
    free(real);
    free(films);

	return 0;
}
