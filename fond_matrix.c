#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void ft_fond_matrix();

int main (void)
{
	ft_fond_matrix();
		return EXIT_SUCCESS;
}

void ft_fond_matrix()
{
	int nombre = 0;
	srand(time(NULL));

	for(int count = 0; count < 10000; count++)
	{
	system("clear");
	for(int y = 0; y < 100; y++)
	{
	for(int i = 0;printf("%d",nombre = rand()%2), i < 100;i++);
	}
	sleep(1);
	}
}
