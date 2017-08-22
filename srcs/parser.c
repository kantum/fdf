#include "fdf.h"
#include "libft.h"

char	*cat_read(int fd)
{
	char	*buf;
	int		ret;
	void	*free_ptr;
	char	rd[BUFF_SIZE + 1];

	buf = ft_strnew(0);
	while ((ret = read(fd, rd, BUFF_SIZE)))
	{
		rd[ret] = '\0';
		free_ptr = (void*)buf;
		if (!(buf = ft_strjoin(buf, rd)))
			return (NULL);
		free(free_ptr);
	}
	return (buf);
}

int		get_height(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while(str[i])
	{
		if (str[i] == '\n' )
			k++;
		i++;
	}
	if ((str[i - 1] != '\n'))
		k++;
	return (k);
}

int		get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		count_field(char const *s, char c)
{
	int	i;
	int	read;
	int	field;

	i = 0;
	read = 0;
	field = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == c)
			read = 0;
		else if (!(s[i] == c) && read == 0)
		{
			read = 1;
			field++;
		}
		i++;
	}
	return (field);
}

t_env	*parser(char *arg, t_env *e)
{
	int		i;
	int		k;
	char	*lines;
	char	**tmp;

	i = 0;
	k = 0;
	e->fd = open(arg, O_RDONLY);
	lines = cat_read(e->fd);
	e->width = count_field(lines, ' ');
	e->height = get_height(lines);
	if (!(e->tab = (int**)malloc(sizeof(int*) * e->width + 1)))
		return (NULL);
	close(e->fd);
	e->fd = open(arg, O_RDONLY);
	while (get_next_line(e->fd, &lines))
	{
		e->tab[k] = (int*)ft_memalloc((sizeof(int) * e->width));
		tmp = ft_strsplit(lines, ' ');
		while (tmp[i])
		{
			e->tab[k][i] = ft_atoi(tmp[i]);
			i++;
		}
		free(tmp);
		k++;
	}
	e->tab[k] = NULL;
	close(e->fd);
	return (e);
}

