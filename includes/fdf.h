#ifndef FDF_H
# define FDF_H

# define RED	= 0xFF0000
# define GREEN	= 0x00FF00
# define BLUE	= 0x0000FF

# include <stdlib.h>
# include <stdio.h>		//printf()
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 1280;
# define HEIGHT 800;

typedef struct s_point	t_point;
struct					s_point
{
	int					x;
	int					y;
	int					color;
};

typedef struct s_env	t_env;
struct					s_env
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			height;
	int			width;

	int			fd;
	
	int			x;
	int			y;

	int			x1;
	int			y1;
	int			ex;
	int			ey;
	int			dx;
	int			dy;
	int			color;

	int			scale;
	int			**tab;
};

void					quit(t_env *e);
t_env					*parser(char *arg, t_env *e);
void					bresenham(t_env *e);
void					red_point(t_env *e);
void					put_pixel(int x, int y, int color);
#endif
