#include "fillit.h"

char	ft_next_valid_letter(t_triminos *lst, char letter)
{
	char	ret;

	while (lst->next && letter != lst->letter)
		lst = lst->next;
	if (letter == lst->letter)
	{
		while (lst->next && letter > lst->letter)
			lst = lst->next;
		if (lst->letter > letter)
			return (lst->letter);
		else
			return (0);
	}
	else
		return (0);
}
