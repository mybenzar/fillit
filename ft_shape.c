#include "fillit.h"

int		ft_shape(char l1, char l2, t_triminos *lst)
{
	t_triminos	*letter1;
	t_triminos	*letter2;
	int i;

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
			return (1);
	}
	return (0);
}
