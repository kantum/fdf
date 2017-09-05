#include "fdf.h"
#include "libft.h"

static void	check_length(t_env *e)
{
	static int	l = 0;

	if (!l)
		l = e->width;
	else if (l != e->width)
		exit(-1);
}

static void	*scan_input(t_env *e)
{
	int		ret;
	char	*free_ptr;
	char	rd[BUFF_SIZE + 1];

	e->buf = ft_strnew(0);
	while ((ret = read(e->fd, rd, BUFF_SIZE)))
	{
		if (ret < 0)
			return (NULL);
		rd[ret] = '\0';
		free_ptr = e->buf;
		if (!(e->buf = ft_strjoin(e->buf, rd)))
			return (NULL);
		free(free_ptr);
	}
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
		e->width = count_field(e->buf, ' ');
		check_length(e);
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
