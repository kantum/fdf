#include "fdf.h"
#include "libft.h"

static int	get_height(char *str)
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

static int	count_field(char const *s, char c)
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

static void	*scan_input(t_env *e)
{
	int		ret;
	char	*free_ptr;
	char	rd[BUFF_SIZE + 1];
	int		l;

	e->buf = ft_strnew(0);
	while ((ret = read(e->fd, rd, BUFF_SIZE)))
	{
		if (!l)
			l = ret;
		else if (l != ret)
			exit(0);
		rd[ret] = '\0';
		free_ptr = e->buf;
		if (!(e->buf = ft_strjoin(e->buf, rd)))
			return (NULL);
		free(free_ptr);
	}
	if (ret < 0)
		return (NULL);
	e->width = count_field(e->buf, ' ');
	e->height = get_height(e->buf);
	e->totalsize = e->width * e->height;
	close(e->fd);
	return (e);
}

static void	*fill_tab(t_env *e)
{
	int		i;
	int		k;
	char	**tmp;

	i = -1;
	k = -1;
	if (!(e->tab = (int**)malloc(sizeof(int*) * e->height + 1)))
		return (NULL);
	while (get_next_line(e->fd, &e->buf))
	{
		e->tab[++k] = (int*)ft_memalloc((sizeof(int) * e->width));
		tmp = ft_strsplit(e->buf, ' ');
		while (++i < e->width)
			e->tab[k][i] = ft_atoi(tmp[i]);
		i = -1;
		free(e->buf);
		free(tmp);
	}
	close(e->fd);
	return (e);
}

t_env		*parser(char *arg, t_env *e)
{
	e->fd = open(arg, O_RDONLY);
	if (!(scan_input(e)))
		return (NULL);
	e->fd = open(arg, O_RDONLY);
	if (!(fill_tab(e)))
		return (NULL);
	return (e);
}
