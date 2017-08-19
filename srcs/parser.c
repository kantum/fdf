#include "fdf.h"
#include "libft.h"

t_env	*parser(char *arg, t_env *e)
{
	int		i;
	int		k;
	char	**lines;
	char	**tmp;

	ft_putstr("hello");
	lines = NULL;
	e->fd = open(arg, O_RDONLY);
	i = 0;
	k = 0;
	while (get_next_line(e->fd, lines))
	{
		tmp = ft_strsplit(*lines, ' ');
		while (tmp[i])
		{
			e->tab[k][i] = atoi(tmp[i]);
		}
		k++;
	}
	e->tab[k] = NULL;
	return (e);
}
