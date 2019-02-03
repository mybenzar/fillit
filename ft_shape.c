#include "fillit.h"
#include <stdio.h>

int		ft_shape(char l1, char l2, t_triminos *lst)
{
	t_triminos	*letter1;
	t_triminos	*letter2;
	int i;

	printf("Comparaison de formes avec ft_shape lettre 1 : %c et lettre 2 %c\n", l1, l2);
	i = 0;
	letter1 = lst;
	letter2 = lst;
	while (letter1->letter != l1 && letter1->next)
		letter1 = letter1->next;
	while (letter2->letter != l2 && letter2->next)
		letter2 = letter2->next;
	if (letter1->letter == l1 && letter2->letter == l2)
	{
		while (letter1->pos[i].x == letter2->pos[i].x &&
		letter1->pos[i].y == letter2->pos[i].y)
			i++;
		if (i == 4)
		{
			printf("%c meme forme que %c\n", l1, l2);
			return (1);
		}
	}
	return (0);
}
