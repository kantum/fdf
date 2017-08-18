#ifndef FDF_H
# define FDF_H

# define RED	= '0xFF0000'
# define GREEN	= '0x00FF00'
# define BLUE	= '0x0000FF'

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>

typedef struct s_env	t_env;
struct					s_env
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			color;
};

void					quit(t_env *e);
int						my_func(int keycode, t_env *e);
void					rectangle(t_env *e);
void					triangle_left(t_env *e);
void					triangle_right(t_env *e);
void					rectangle(t_env *e);
void					trace(t_env *e);
void					red_point(t_env *e);

#endif
