#include "so_long.h"

void do_right(map *c)
{
	static int i;
	c->mapstruct[c->player_y][c->player_x] = '0';
	if (c->mapstruct[c->player_y][c->player_x + 1] != 'E')
		c->mapstruct[c->player_y][c->player_x + 1] = 'P';
	if (i == 0)
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_right_step.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i++;
	}
	else
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_right_step_2.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i = 0;
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_x += 1;
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_right.xpm", &c->width, &c->height);
	mlx_do_sync(c->mlx);
	c->moves += 1;
}
void do_left(map *c)
{
	static int i;
	c->mapstruct[c->player_y][c->player_x] = '0';
	if (c->mapstruct[c->player_y][c->player_x - 1] != 'E')
		c->mapstruct[c->player_y][c->player_x - 1] = 'P';
	if (i == 0)
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_left_step.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i++;
	}
	else
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_left_step_2.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i = 0;
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_x -= 1;
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_left.xpm", &c->width, &c->height);
	mlx_do_sync(c->mlx);
	c->moves += 1;
}
void do_up(map *c)
{
	static int i;
	c->mapstruct[c->player_y][c->player_x] = '0';
	if (c->mapstruct[c->player_y - 1][c->player_x] != 'E')
		c->mapstruct[c->player_y - 1][c->player_x] = 'P';
	if (i == 0)
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_up_step.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i++;
	}
	else
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_up_step_2.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i = 0;
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_y -= 1;
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_up.xpm", &c->width, &c->height);
	mlx_do_sync(c->mlx);
	c->moves += 1;
}
void do_down(map *c)
{
	static int i;
	c->mapstruct[c->player_y][c->player_x] = '0';
	if (c->mapstruct[c->player_y + 1][c->player_x] != 'E')
		c->mapstruct[c->player_y + 1][c->player_x] = 'P';
	if (i == 0)
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_stand_step.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i++;
	}
	else
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_stand_step_2.xpm", &c->width, &c->height);
		mlx_do_sync(c->mlx);
		i = 0;
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_y += 1;
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_stand.xpm", &c->width, &c->height);
	mlx_do_sync(c->mlx);
	c->moves += 1;
}