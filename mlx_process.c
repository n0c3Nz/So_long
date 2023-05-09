#include "so_long.h"

int mlx_process(map *c)
{
	int i;
	int j;
	int e;
	int k;

	i = 0;
	j = 0;
	e = 10;
	k = 10;
	c->img_ptr = mlx_xpm_file_to_image(c->mlx, "tests/pacsuelo.xpm", &c->width, &c->height);
	while (i < c->lines)
	{
		while (j < c->columns)
		{
			if (c->mapstruct[i][j] == '1')
				mlx_put_image_to_window(c->mlx, c->mlx_win, c->img_ptr, e, k);
			j++;
			e = e + 10;
		}
		j = 0;
		e = 10;
		k = k + 10;
		i++;
	}
	return(0);
}