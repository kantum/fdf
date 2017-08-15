#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

typedef struct s_params	t_params;

struct					s_params
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			color;
};

void	rectangle(t_params *param)
{
	int	x;
	int	y;
	
	y = param->y;
	while (y < param->y1)
	{
		x = param->x;
		while (x < param->x1)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, param->color);
			x++;
		}
		y++;
	}
}

int		my_func(int keycode, t_params *param)
{
	if (keycode == 123)
		rectangle(param);
	else if (keycode == 124)
		mlx_clear_window(param->mlx, param->win);
	printf("key event %d\n", keycode);
	return (0);
}

int		main()
{
	t_params	*params;
	void		*mlx;
	void 		*win;
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			color;

	x = 50;
	y = 50;
	x1 = 200;
	y1 = 200;
	color = 0xFFFF00;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "win");

	params = (t_params*)malloc(sizeof(t_params));

	params->mlx = mlx;
	params->win = win;
	params->x = x;
	params->y = y;
	params->x1 = x1;
	params->y1 = y1;
	params->color = color;
	mlx_key_hook(win, my_func, params);
	mlx_loop(mlx);
}
