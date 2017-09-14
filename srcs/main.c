/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdurot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:10:23 by qdurot            #+#    #+#             */
/*   Updated: 2017/09/10 19:10:41 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc < 2 || argc > 2)
		return (-1);
	if (!ft_strcmp(argv[1], "/dev/random") ||
		!ft_strcmp(argv[1], "/dev/urandom"))
		return (-1);
	if (argc == 2)
		e = *parser(argv[1], &e);
	if (init(&e) < 0)
		return (-1);
	mlx_hook(e.win, 17, (1L << 17), quit, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
}
