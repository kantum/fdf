#include "libft.h"

int	get_height(char *str)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] == '\n')
			k++;
	if ((str[i - 1] != '\n'))
		k++;
	return (k);
}
