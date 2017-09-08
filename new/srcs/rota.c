#include "fdf.h"

void	rota(t_env *e, int a)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	mlx_clear_window(e->mlx, e->win);
	while(++i < e->o.height)
	{
		while(++k < e->o.width)
		{
			e->o.tab[i][k].x = e->o.tab[i][k].x * cos(a + e->o.tab[i][k].x) - e->o.tab[i][k].y * sin(a);
			e->o.tab[i][k].y = e->o.tab[i][k].x * sin(a + e->o.tab[i][k].y) + e->o.tab[i][k].y * cos(a);
		}
		k = -1;
	}
	draw(e);
}
