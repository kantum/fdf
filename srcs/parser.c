/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:28 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_field(char const *s, char c)
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

static void	check_length(t_obj *o)
{
	static int	l = 0;

	o->width = count_field(o->buf, ' ');
	if (!l)
		l = o->width;
	else if (l != o->width)
		exit(-1);
}

static void	*scan_input(t_obj *o)
{
	int		ret;
	char	*f_ptr;
	char	rd[BUFF_SIZE + 1];

	o->buf = ft_strnew(0);
	while ((ret = read(o->fd, rd, BUFF_SIZE)))
	{
		if (ret < 0)
			exit(-1);
		rd[ret] = '\0';
		f_ptr = o->buf;
		if (!(o->buf = ft_strjoin(o->buf, rd)) || ret < 0)
			return (NULL);
		free(f_ptr);
	}
	o->width = count_field(o->buf, ' ');
	o->height = ft_getnline(o->buf);
	free(o->buf);
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
	if (!(o->tab = (t_point**)malloc(sizeof(t_point*) * o->height)))
		return (NULL);
	while (get_next_line(o->fd, &o->buf))
	{
		check_length(o);
		o->tab[++i] = (t_point*)malloc((sizeof(t_point) * o->width));
		tmp = ft_strsplit(o->buf, ' ');
		while (++k < o->width)
		{
			o->tab[i][k].x = k;
			o->tab[i][k].y = i;
			o->tab[i][k].z = ft_atoi(tmp[k]);
		}
		k = -1;
		free(o->buf);
		free_tab(tmp);
	}
	close(o->fd);
	return (o);
}

t_env		*parser(char *arg, t_env *e)
{
	if (!(e->o.fd = open(arg, O_RDONLY)))
		exit(-1);
	if (!scan_input(&e->o))
		exit(-1);
	if (!(e->o.fd = open(arg, O_RDONLY)))
		exit(-1);
	if (!fill_tab(&e->o))
		exit(-1);
	return (e);
}
