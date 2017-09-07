#include "fdf.h"

static void	check_length(t_obj *o)
{
	static int	l = 0;

	if (!l)
		l = o->width;
	else if (l != o->width)
		exit(-1);
}

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

static void	*scan_input(t_obj *o)
{
	int		ret;
	char	*f_ptr;
	char	rd[BUFF_SIZE + 1];

	o->buf = ft_strnew(0);
	while ((ret = read(o->fd, rd, BUFF_SIZE)))
	{
		rd[ret] = '\0';
		f_ptr = o->buf;
		if (!(o->buf = ft_strjoin(o->buf, rd)) || ret < 0)
			return (NULL);
		free(f_ptr);
	}
	o->width = count_field(o->buf, ' ');
	o->height = ft_getnline(o->buf);
	close(o->fd);
	return (o);
}

static void	*fill_tab(t_obj *o)
{
	char	**tmp;
	int		i;
	int		k;

	i = -1;
	k = -1;
	if (!(o->tab = (t_point**)malloc(sizeof(t_point*) * o->height + 1)))
		return (NULL);
	while(get_next_line(o->fd, &o->buf))
	{
		o->width = count_field(o->buf, ' ');
		check_length(o);
		tmp = ft_strsplit(o->buf, ' ');
		while (++i < o->width)
		{
			o->tab[++k] = (t_point*)malloc((sizeof(t_point) * o->width + 1));
			o->p->x = i;
			o->p->y = k;
			o->p->z = tmp[i][k];
		}
		i = -1;
		free(tmp);
	}
	close(o->fd);
	return (o);
}

t_obj		*parser(char *arg, t_obj *o)
{
	o->fd = open(arg, O_RDONLY);
	if (!scan_input(o))
		return (NULL);
	if (!fill_tab(o))
		return (NULL);
	return (o);
}
