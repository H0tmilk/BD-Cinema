#include <stdio.h>
#include <stdlib.h>
#include "data_struct.h"
#include "bdd.h"

int main( int argc, char* args[] )
{
    personnes* acteurs = readActeurs();
    personnes* real = readRealisateurs();
    Films* films = readFilms(acteurs, real );

    char* saisie = malloc(sizeof(char*));

    int continuer = 1;

    do {
      int rep = 0, ret;
    	printf("============= Cine Info =============");
    	do {
    		printf("\n\nChoisissez une action en tapant son numéro :\n");
    		printf("1 - Afficher la liste de tous les films\n");
    		printf("2 - Afficher la liste de tous les acteurs\n");
    		printf("3 - Afficher la liste de tous les realisateurs\n\n");
    		printf("4 - Rechercher un film\n");
        printf("5 - Rechercher un acteur\n");
        printf("6 - Rechercher un realisateur\n\n");
        printf("7 - Quitter\n\n");
        fflush(stdin);
    		ret = scanf(" %d", &rep);
    		printf("\n");
    		// S'il y a une erreur avec le scanf
    		if (ret != 1)
    			rep = 0;

    		// Nettoyage du buffer pour enlever le \n de l'entrée
    		getchar();
    	} while(rep > 7 || rep < 1);

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
          fflush(stdin);
    			gets(saisie);
          printf("\n");
  				film* f = searchFilmByName(saisie, films->film, films->taille);

    			if (f != NULL) {
    				afficherFilmPtr(f);
            printf("\n");
    			} else {
    				printf("Le film \"%s\" n'existe pas dans notre base de données.\n", saisie);
    			}
    		break;
        case 5:
    			printf("Entrez le nom de l'acteur que vous voulez rechercher :\n");
          fflush(stdin);
    			gets(saisie);
          printf("\n");
  				personne* a = searchPersonneByName(saisie, acteurs->pers, acteurs->taille);

    			if (a != NULL) {
    				afficherPersonnePtr(a);
            printf("\n");
    			} else {
    				printf("L'acteur \"%s\" n'existe pas dans notre base de données.\n", saisie);
    			}

    		break;
        case 6:
          printf("Entrez le nom du realisateur que vous voulez rechercher :\n");
          fflush(stdin);
    			gets(saisie);
          printf("\n");
          personne* r= searchPersonneByName(saisie, real->pers, real->taille);

          if (r != NULL) {
            afficherPersonnePtr(r);
            printf("\n");
          } else {
            printf("Le realisateur \"%s\" n'existe pas dans notre base de données.\n", saisie);
          }

        break;
        case 7:
          printf("A bientot !\n");
          return 0;
        break;
    	}

      printf("Appuyez sur une touche pour continuer...\n");
      getchar();
    } while (continuer == 1);


    libererPersonnes(acteurs);
    libererPersonnes(real);
    libererFilms(films);
    free(saisie);
    free(acteurs);
    free(real);
    free(films);

	return 0;
}
