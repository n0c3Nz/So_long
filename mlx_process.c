#include "so_long.h"

int mlx_process(map *c)
{
	c->wall_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/wall.xpm", &c->width, &c->height);
	c->floor_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/floor.xpm", &c->width, &c->height);
	c->exit_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/exit.xpm", &c->width, &c->height);
	c->coin_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/coin.xpm", &c->width, &c->height);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_stand.xpm", &c->width, &c->height);
	c->moves = 0;
	c->coins_gained = 0;
	put_imgs(c);
	ft_printf("\nPosición y:%i\nPosición x:%i", c->player_y, c->player_x);
	return(0);
}
void put_imgs(map *c)
{
	int y;
	int x;

	y = 0;
	x = 0;

	while (y < c->lines)
	{
		while (x < c->columns)
		{
			put_item(c, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}
void put_item(map *c, int y, int x)
{
	if (c->mapstruct[y][x] == '1')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->wall_ptr, x * BPP, y * BPP);
	else if (c->mapstruct[y][x] == '0')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, x * BPP, y * BPP);
	else if (c->mapstruct[y][x] == 'E')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->exit_ptr, x * BPP, y * BPP);
	else if (c->mapstruct[y][x] == 'C')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->coin_ptr, x * BPP, y * BPP);
	else if (c->mapstruct[y][x] == 'P')
	{
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, x * BPP, y * BPP);
		c->player_x = x;
		c->player_y = y;
	}
}

int key_hook(int keycode, map *c)
{
	if (keycode == 0x61 || keycode == 0x41) // tecla a o A
        move_left(c);
    else if (keycode == 0x73 || keycode == 0x53) // tecla s o S
        move_down(c);
    else if (keycode == 0x64 || keycode == 0x44) // tecla d o D
        move_right(c);
    else if (keycode == 0x77 || keycode == 0x57) // tecla w o W
		move_up(c);
	check_e(c);
	return (0);
}