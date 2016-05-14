/*##########################################################
#	Création d'un labyrinthe !
#	Voici les corespondances :
#		# = MUR
#		@ = DEPART
#		$ = ARRIVEE
# Le programme prend en arument la dimension du labyrinthe
#	sous le format x et y nombre entier
#
#	Date : 11/05/2016 version en cours de developpement v 0.1
############################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
	int x;
	int y;
	Node *prev;
};
typedef struct index
{
	Node *first;
}Index;

Index *ft_init();
void ft_check_position(char **labyrinthe, int a, int b);
void ft_new_node(Index *list, int y, int x);
int ft_resolveur(char **labyrinthe, int x, int y);
static int ft_convertCharInt(char *number);
static void ft_choice_start(char **labyrinthe, int x, int y);
static void ft_show_labyrinthe(char **labbyrinthe, int x, int y);
static void ft_fill_border(char **labytrinthe, int x, int y);
static void ft_create_mur(char **labyrinthe, int x, int y);
static void ft_choice_win(char **labyrenthe, int x, int y);

int main (int argc, char **argv)
{
	srand(time(NULL));
	
	if(argc < 2)
		exit(EXIT_FAILURE);

	int x = ft_convertCharInt(argv[1]), y = ft_convertCharInt(argv[2]);
	char **labyrinthe = malloc((y) * sizeof(char*));
	for(int i = 0; i < y; i++)
		labyrinthe[i] = malloc((x) * sizeof(char));

	ft_fill_border(labyrinthe, x, y);
	ft_choice_start(labyrinthe ,x, y);
	ft_create_mur(labyrinthe, x, y);
	ft_choice_win(labyrinthe, x, y);
	ft_show_labyrinthe(labyrinthe, x, y);
	ft_resolveur(labyrinthe, x , y);

	for(int i = 0; i < x; i++)
		free(labyrinthe[i]);

	free(labyrinthe), labyrinthe = NULL;
		return EXIT_SUCCESS;
}

 static void ft_choice_win(char **labyrinthe, int x, int y)
{
	int random_x = rand()%x;
	int random_y = rand()%y;
	
	if(labyrinthe[random_y][random_x] == '.')
		labyrinthe[random_y][random_x] = '$';
	else
		ft_choice_win(labyrinthe, x, y);
}

 static void ft_create_mur(char **labyrinthe, int x, int y)
{
	int nbMur_max_y = y/5, nbMur_max_x = x/5;
	int nbMur_y = 0, nbMur_x = 0;
	int nb_aleatoire = 0;

	for(int h = 1; h < y-1; h++)
	{
		for(int w = 1; nb_aleatoire = rand()%3, w < x-1;nbMur_x = 0, nbMur_y = 0, w++)
		{
			switch (nb_aleatoire)
			{
				case 1:
					for(int a = 1; a < y-1; a++)
					{
						if(labyrinthe[a][w] == '#')
							nbMur_y++;
					}
					for(int b = 1;  b < x-1; b++)
					{
						if(labyrinthe[h][b] == '#')
							nbMur_x++;;
					}
					if(nbMur_max_y > nbMur_y && nbMur_max_x > nbMur_x)
						labyrinthe[h][w] = '#';
					else
						labyrinthe[h][w] = '.';

					break;
				case 0:
					labyrinthe[h][w] = '.';
					break;
				default:
					labyrinthe[h][w] = '.';
					break;

			}
			for(int a = h-1; a <= h+1; a++)
			{
				for(int b = w-1; b <= w+1; b++)
				{
					if(labyrinthe[a][b] == '@')
					{
						labyrinthe[h][w] = '.';
					}
				}
			}
		}
	}
}

 static void ft_show_labyrinthe(char **labyrinthe, int x, int y)
{
	for(int h = 0; h < y; h++)
	{
		printf("\n");
		for(int w = 0; w < x; w++)
		{
			printf("%c", labyrinthe[h][w]);
		}
	}
}

 static void ft_fill_border(char **labyrinthe, int x, int y)
{
	for(int h = 0; h < y; h++)
	{
		if(labyrinthe[h][0] != '@')
			labyrinthe[h][0] = '#';

		if(labyrinthe[h][x-1] != '@')
			labyrinthe[h][x-1] = '#';

	}
		for(int w = 0; w < x; w++)
		{
			if(labyrinthe[0][w] != '@')
				labyrinthe[0][w] = '#';

			if(labyrinthe[y-1][w] != '@')
				labyrinthe[y-1][w] = '#';

		}
}

 static void ft_choice_start(char **labyrinthe, int x, int y)
{
	int nb_aleatoire = rand()%(x+y)*2-1;

	if(nb_aleatoire < x-1 && nb_aleatoire != 0)
		labyrinthe[0][nb_aleatoire] = '@';
	else if(nb_aleatoire > x && nb_aleatoire < ((y-1)+(x-1)))
		labyrinthe[nb_aleatoire - x][x-1] = '@';
	else if(nb_aleatoire > (x+y) && nb_aleatoire < (2*(x-1) + (y-1)))
		labyrinthe[y-1][nb_aleatoire - (x + y)] = '@';
	else if(nb_aleatoire > (2*x + y) && nb_aleatoire < ((x-1)+(y-1))*2)
		labyrinthe[nb_aleatoire-((2*x)+y)][0] = '@';
	else
		ft_choice_start(labyrinthe, x, y);
}

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
