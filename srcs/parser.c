#include "fdf.h"

t_env	*parser(char *arg, t_env *e)
{
	e->fd = open(arg, O_RDONLY);
	return (e);
}
