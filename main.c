// Librairie SDL au cas où le temps le permettrait
//#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "data-struct.h"
#include "bdd.h"


int main( int argc, char* args[] )
{
    personnes* acteurs = readActeurs();
    personnes* real = readRealisateurs();
    Films* films = readFilms(acteurs, real );

    int rep = 0, ret;
  	printf("============= Cine Info =============");
  	do {
  		printf("\n\nChoisissez une action en tapant son numéro :\n");
  		printf("1 - Afficher la liste de tous les films\n");
  		printf("2 - Afficher la liste de tous les acteurs\n");
  		printf("3 - Afficher la liste de tous les realisateurs\n\n");
  		printf("4 - Rechercher un film\n\n");
  		ret = scanf(" %d", &rep);
  		printf("\n");
  		// S'il y a une erreur avec le scanf
  		if (ret != 1)
  			rep = 0;

  		// Nettoyage du buffer pour enlever le \n de l'entrée
  		getchar();
  	} while(rep > 5 || rep < 1);

  	char* saisie;
  	switch (rep) {
  		case 1:
  			printf("== FICHES FILMS ==\n\n");
  			afficherFilms(films);
  		break;
  		case 2:
  			printf("== FICHES ACTEURS ==\n\n");
  			afficherPersonnes(acteurs);
  		break;
  		case 3:
  			printf("== FICHES REALISATEURS ==\n\n");
  			afficherPersonnes(real);
  		break;
  		case 4:
  			printf("Entrez le nom du film que vous voulez rechercher :\n");
  			scanf("%s", &saisie);

				film* f = searchFilmByName(saisie, films, films->taille);

  			if (f != NULL) {
  				afficherFilmPtr(f);
  			} else {
  				printf("Le film \"%s\" n'existe pas dans notre base de données.\n", saisie);
  			}

  		break;
  	}


    libererPersonnes(acteurs);
    libererPersonnes(real);
    free(acteurs);
    free(real);
    free(films);

	return 0;
}
