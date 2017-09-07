#include "fdf.h"

void	put_pixel(void *mlx, void *win, t_point *p)
{
	mlx_pixel_put(mlx, win, p->x, p->y, p->color);
}
