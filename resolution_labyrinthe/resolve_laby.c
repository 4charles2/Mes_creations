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


int ft_resolveur(char **labyrinthe, int x, int y)
{
	Index *list = ft_init();
	int verif = 1, depart_x = 0, depart_y = 0;
	for(int a = 0; a < y; a++)
	{
		for(int b = 0; b < x; b++)
		{
			if(labyrinthe[a][b] == '@')
			{
				depart_x = b;
				depart_y = a;
			}
		}
	}
	ft_new_node(list, depart_y, depart_x);
	while(verif)
	{
			if(b++ < x)
				verif = ft_check_position(labyrinthe,Index *list, int a, int b);
			if(b-- < x)
				verif = ft_check_position(labyrinthe,Index *list, int a, int b);
			if(a++ < y)
				verif = ft_check_position(labyrinthe, Index *list, int a, int b);
/* Boucle sa correspond pas il faut revoir sa */
	}

	return 1;
}

 int ft_check_position(char **labyrinthe, int a, int b)
{
			switch (labyrinthe[a][b])
			{
				case '#':
					break;
				case '.':
					ft_new_node(list, a, b);
					break;
				case '$':
					
					ft_unstack(list);
					break;
				default:
					printf("Erreur mauvais caractere lu dans le ft_resolveur.c:48");
					break;
			};;

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
