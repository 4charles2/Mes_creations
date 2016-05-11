/*##########################################################
#	Création d'un labyrinthe !
#	Voici les corespondances :
#		# = MUR
#		@ = DEPART
#		$ = ARRIVEE
# Le programme prend en arument la dimension du labyrinthe
#	sous le format x et y nombre entier
#
#	Date : 11/05/2016 version en cours de developpement
############################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int ft_convertCharInt(char *number);
/*static void ft_choice_start(char **labyrinthe, int x, int y);*/
/*static void ft_show_labyrinthe(char **labbyrinthe, int x, int y);*/

int main (int argc, char **argv)
{
	if(argc < 2)
		exit(EXIT_FAILURE);

	int x = ft_convertCharInt(argv[1]), y = ft_convertCharInt(argv[2]);

	char **labyrinthe = malloc(sizeof(**labyrinthe) * (y+1) * (x+1));
	/*ft_choice_start(labyrinthe ,x, y);*/
	/*ft_show_labyrinthe(labyrinthe, x, y);*/
	labyrinthe[3][2] = '#';
	printf("%c", labyrinthe[3][2]);

	free(labyrinthe), labyrinthe = NULL;
		return EXIT_SUCCESS;
}

/*static void ft_show_labyrinthe(char **labyrinthe, int x, int y)
{
	for(int h = 1; h < y;printf("\n"), y++)
		for(int w = 1; w < x; x++)
		{
			labyrinthe[h][w] = '#';
			printf("%c", labyrinthe[h][w]);
		}
}*/

/*static void ft_choice_start(char **labyrinthe, int x, int y)
{
	srand(time(NULL));
	int nb_aleatoire = rand()%(x+y)*2;

	if(nb_aleatoire < x)
		labyrinthe[0][nb_aleatoire] = '@';
	else if(nb_aleatoire > x && nb_aleatoire < y)
		labyrinthe[nb_aleatoire - x][x] = '@';
	else if(nb_aleatoire >= (x+y) && nb_aleatoire < (2*x + y))
		labyrinthe[y][nb_aleatoire - (x + y)] = '@';
	else if(nb_aleatoire >= (2 *x + y) && nb_aleatoire < (x+y)*2)
		labyrinthe[nb_aleatoire - (2*x - y)][0] = '@';
}*/

static int ft_convertCharInt(char *number)
{
	int unite = 0, dizaine = 0;
	int num = 0;
	int taille = strlen(number);
	unite = number[taille-1];
	unite -= 48;
	for(int i=taille-2, multiplicateur = 10; i >= 0; i--, multiplicateur *= 10)
	{
		dizaine = number[i];
		dizaine -= 48;
		dizaine *= multiplicateur;
		num += dizaine;
	}

	return num += unite;
}
