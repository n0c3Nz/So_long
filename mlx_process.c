#include "so_long.h"

int mlx_process(map *c)
{
	int i;
	i = 0;

	while (i < c->lines)
	{
		ft_printf("%d\n%s\n", ft_strlen(c->mapstruct[i]), c->mapstruct[i]);
		i++;
	}
	return(0);
}