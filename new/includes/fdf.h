#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>		//printf() TODO
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
	int		x;
	int		y;
	int		z;
	int		color;
};

typedef struct s_obj	t_obj;
struct					s_obj
{
	int		fd;
	int		width;
	int		height;
	char	*buf;
	int		bres;
	int		pitch;
	t_point	*p;
	t_point	**tab;
};

typedef struct s_env	t_env;
struct					s_env
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	int		scale;
	t_point	origin;
	t_obj	o;
};

typedef struct s_bres	t_bres;
struct					s_bres
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
};

void					rota(t_env *e, int a);
void					init_point(t_point *p);
int						init(t_env *e);
t_point					*newmap(void const *content, size_t content_size);
t_env					*parser(char *arg, t_env *e);
void					put_pixel(void *mlx, void *win, t_point *p);
void					bresenham(t_point a, t_point b, t_env *e);
int						key_hook(int keycode, t_env *e);
void					quit(t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
void					set(t_env *e);
void					draw(t_env *e);
int						expose_hook(t_env *e);

#endif
