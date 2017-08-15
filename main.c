#include <stdio.h>
#include "mlx.h"

void	test_func(int *mlx, int *win, int x_from, int y_from, int x_to, int y_to)
{
	int		x;
	int		y;

	x = x_from;
	y = y_from;
	while (y < y_to)
	{
		while (x < x_to)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}

int		my_func(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	(void)param;
	return (0);
}

int		main()
{
	void	*mlx;
	void 	*win;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "win");
	mlx_key_hook(win, my_func, 0);
	//test_func(100, 200, 200, 400);
	mlx_loop(mlx);
}
