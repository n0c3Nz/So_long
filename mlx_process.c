#include "so_long.h"

int mlx_process(map *c)
{
	c->wall_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/wall.xpm", &c->width, &c->height);
	c->floor_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/floor.xpm", &c->width, &c->height);
	c->exit_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/exit.xpm", &c->width, &c->height);
	c->coin_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/coin.xpm", &c->width, &c->height);
	
	put_imgs(c);
	return(0);
}
void put_imgs(map *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	c->xs = 0;
	c->ys = 0;

	while (i < c->lines)
	{
		while (j < c->columns)
		{
			put_item(c, i, j);
			j++;
			c->xs = c->xs + 32;
		}
		j = 0;
		c->xs = 0;
		c->ys = c->ys + 32;
		i++;
	}
}
void put_item(map *c, int i, int j)
{
	if (c->mapstruct[i][j] == '1')
	{
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->xs, c->ys);
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->wall_ptr, c->xs, c->ys);
	}
	else if (c->mapstruct[i][j] == '0')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->xs, c->ys);
	else if (c->mapstruct[i][j] == 'E')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->exit_ptr, c->xs, c->ys);
	else if (c->mapstruct[i][j] == 'C')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->coin_ptr, c->xs, c->ys);
	else if (c->mapstruct[i][j] == 'P')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->xs, c->ys);

}