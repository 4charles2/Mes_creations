/*#################################################################
#	Resolveur de labyrinthe !
#	Doit trouver le chemin le plus court le plus vite possible
#	Voici les corespondances:
#		# = MUR
#		@ = DEPART
#		$ = ARRIVEE
#	Le programme prend en argument le labyrinthe
#	Date : Le 12/05/2016 version en cours de develeppement v 0.1
###################################################################*/
#include <stdio.h>
#include <stdlib.h>

/*############################################################################################################
########################## COMMENTAIRE SUR LE FONCTIONNE ET LA MARCHE A SUIVRE POUR LE CODE ##################
##############################################################################################################
	Utilisation d'une pile
	Index pointe  vers le dernier noeud qui verifiera si ont est sur la case d'arrive
	Et si c'est le cas alors first pointera vers ce noeud.
	On depile alors aussitôt avant de faire tous autre deplacement jusqu'à pointer vers null
	Soit la case départ.
	J'enregistre en même temp les coordonnées x et y contenu dans chaque noeud que je remonte dans un tableau
	Cela va me permettre de ensuite de tracer le chemin sur le labyrinthe
#############################################################################################################*/
typedef struct node Node;
struct node
{
	int x;
	int y;
	Node *prev;
};
struct index
{
	Node *first;
};
typedef struct index Index;

Index *ft_init();
int ft_check_position(char **labyrinthe,Index *list, int a, int b);
void ft_new_node(Index *list, int y, int x);
void ft_check_start(char **labyrinthe, int *a, int *b, int *depart_x, int *depart_y, int x, int y);

int ft_resolveur(char **labyrinthe, int x, int y)
{
	Index *list = ft_init();
	int verif = 1, depart_x = 0, depart_y = 0, a = 0, b = 0;
	ft_check_start(labyrinthe, &a, &b, &depart_x, &depart_y, x, y);
	ft_new_node(list, depart_y, depart_x);
	while(verif)
	{
			if(b++ < x-1)
				verif = ft_check_position(labyrinthe,list, a, b);;
			if(b-- < x-1)
				verif = ft_check_position(labyrinthe,list,  a,  b);;
			if(a++ < y-1)
				verif = ft_check_position(labyrinthe,list,  a,  b);;
/* Boucle sa correspond pas il faut revoir sa */
			printf("coucou\n");
	}

	return 1;
}

void ft_check_start(char **labyrinthe, int *a, int *b, int *depart_x, int *depart_y, int x, int y)
{
		for(*b = 0; *b < x; (*b)++)
			if(labyrinthe[0][*b] == '@')
			{
				*depart_x = *b;
				*depart_y = *a;
				return;
			};;
		for(*a = 0; *a < y; (*a)++)
			if(labyrinthe[*a][x-1] == '@')
			{
				*depart_x = *b;
				*depart_y = *a;
				return;
			};;
		for(*b = x-1; *b >= 0; (*b)--)
			if(labyrinthe[y-1][*b] == '@')
			{
				*depart_x = *b;
				*depart_y = *a;
				return;
			};;
		for(*a = y-1; *a >= 0; (*a)--)
		{
			if(labyrinthe[*a][0] == '@')
				*depart_x = *b;
				*depart_y = *a;
				return;
		}
}

int ft_check_position(char **labyrinthe,Index *list, int a, int b)
{
			char caractere_case = '0';
			switch (labyrinthe[a][b])
			{
				case '#':
					break;
				case '.':
					ft_new_node(list, a, b);
					break;
				case '$':
					
/*					ft_unstack(list);*/
					break;
				default:
					printf("Erreur mauvais caractere lu dans le ft_resolveur.c:84");
					break;
			};;
			printf("\n la ligne%s", labyrinthe[a]);
			caractere_case = labyrinthe[a][b];
			labyrinthe[a][b] = '0';
			printf("\n %s", labyrinthe[a]);
			labyrinthe[a][b] = caractere_case;

	return 1;
}

void ft_new_node(Index *list, int y, int x)
{
	Node *new = malloc(sizeof(*new));
	new->x = x;
	new->y = y;
	new->prev = list->first;
}

Index *ft_init()
{
	Index *newlist = malloc(sizeof(*newlist));
	newlist->first = NULL;
	return newlist;
}
