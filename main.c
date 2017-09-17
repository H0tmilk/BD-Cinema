// Librairie SDL au cas où le temps le permettrait
//#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "data-struct.h"
#include "bdd.h"


int main( int argc, char* args[] )
{
    printf("Acteurs : \n");
    personnes acteurs = readActeurs();

    printf("\nReal : \n");
    personnes real = readRealisateurs();

    printf("%d",real->size);

    printf("\n Films :\n");
    film* films = readFilms(&acteurs , &real );

    free(acteurs);
    free(real);
    free(films);

	return 0;
}
