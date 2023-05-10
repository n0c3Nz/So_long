#include "so_long.h"

int mlx_process(map *c)
{
	c->wall_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/wall.xpm", &c->width, &c->height);
	c->floor_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/floor.xpm", &c->width, &c->height);
	c->exit_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/exit.xpm", &c->width, &c->height);
	c->coin_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/coin.xpm", &c->width, &c->height);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_stand.xpm", &c->width, &c->height);
	put_imgs(c);
	ft_printf("\nPosición x:%y\nPosición y:%y", c->player_x, c->player_y);
	return(0);
}
void put_imgs(map *c)
{
	int y;
	int x;

	y = 0;
	x = 0;
	c->xs = 0;
	c->ys = 0;

	while (y < c->lines)
	{
		while (x < c->columns)
		{
			put_item(c, y, x);
			x++;
			c->xs = c->xs + BPP;
		}
		x = 0;
		c->xs = 0;
		c->ys = c->ys + BPP;
		y++;
	}
}
void put_item(map *c, int y, int x)
{
	if (c->mapstruct[y][x] == '1')
	{
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->wall_ptr, c->xs, c->ys);
	}
	else if (c->mapstruct[y][x] == '0')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->xs, c->ys);
	else if (c->mapstruct[y][x] == 'E')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->exit_ptr, c->xs, c->ys);
	else if (c->mapstruct[y][x] == 'C')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->coin_ptr, c->xs, c->ys);
	else if (c->mapstruct[y][x] == 'P')
	{
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->xs, c->ys);
		c->player_x = y;
		c->player_y = x;
	}
}

int key_hook(int keycode, map *c)
{
	if (keycode == 0x61 || keycode == 0x41) // tecla a o A
        ft_printf("\nHas pulsado la tecla A!");
    else if (keycode == 0x73 || keycode == 0x53) // tecla s o S
        ft_printf("\nHas pulsado la tecla S!");
    else if (keycode == 0x64 || keycode == 0x44) // tecla d o D
        ft_printf("\nHas pulsado la tecla D!");
    else if (keycode == 0x77 || keycode == 0x57) // tecla w o W
    	ft_printf("\nHas pulsado la tecla W!");
	return (0);
}