#include "libft.h"

int	count_field(char const *s, char c)
{
	int	i;
	int	read;
	int	field;

	i = -1;
	read = 0;
	field = 0;
	while (s[++i] && s[i] != '\n')
	{
		if (s[i] == c)
			read = 0;
		else if (!(s[i] == c) && read == 0)
		{
			read = 1;
			field++;
		}
	}
	return (field);
}

