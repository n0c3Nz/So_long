#include "so_long.h"

int move_up(map *c)
{
	ft_printf("\nHas pulsado la tecla W!");
	if (c->mapstruct[c->player_y - 1][c->player_x] != '1')
	{
		if (c->mapstruct[c->player_y - 1][c->player_x] == 'C')
			c->coins_gained += 1;
		if (c->mapstruct[c->player_y - 1][c->player_x] == '0' || c->mapstruct[c->player_y - 1][c->player_x] == 'P' || c->mapstruct[c->player_y - 1][c->player_x] == 'C' || (c->mapstruct[c->player_y - 1][c->player_x] == 'E' && c->coins_gained == c->coins))
		{
			do_up(c);
			return (0);
		}
	}
	return(1);
}

int move_down(map *c)
{
	ft_printf("\nHas pulsado la tecla S!");
	if (c->mapstruct[c->player_y + 1][c->player_x] != '1')
	{
		if (c->mapstruct[c->player_y + 1][c->player_x] == 'C')
			c->coins_gained += 1;
		if (c->mapstruct[c->player_y + 1][c->player_x] == '0' || c->mapstruct[c->player_y + 1][c->player_x] == 'P' || c->mapstruct[c->player_y + 1][c->player_x] == 'C' || (c->mapstruct[c->player_y + 1][c->player_x] == 'E' && c->coins_gained == c->coins))
		{
			do_down(c);
			return (0);
		}
	}
	return (1);
}

int move_right(map *c)
{
	ft_printf("\nHas pulsado la tecla D!");
	if (c->mapstruct[c->player_y][c->player_x + 1] != '1')
	{
		if (c->mapstruct[c->player_y][c->player_x + 1] == 'C')
			c->coins_gained += 1;
		if (c->mapstruct[c->player_y][c->player_x + 1] == '0' || c->mapstruct[c->player_y][c->player_x + 1] == 'P' || c->mapstruct[c->player_y][c->player_x + 1] == 'C' || (c->mapstruct[c->player_y][c->player_x + 1] == 'E' && c->coins_gained == c->coins))
		{
			do_right(c);
			return(0);
		}
	}
	return(1);
}

int move_left(map *c)
{
	ft_printf("\nHas pulsado la tecla A!");
	if (c->mapstruct[c->player_y][c->player_x - 1] != '1')
	{
		if (c->mapstruct[c->player_y][c->player_x - 1] == 'C')
			c->coins_gained += 1;
		if (c->mapstruct[c->player_y][c->player_x - 1] == '0' || c->mapstruct[c->player_y][c->player_x - 1] == 'P' || c->mapstruct[c->player_y][c->player_x - 1] == 'C' || (c->mapstruct[c->player_y][c->player_x - 1] == 'E' && c->coins_gained == c->coins))
		{
			do_left(c);
			return(0);
		}
	}
	return(1);
}

int check_e(map *c){
	if (c->mapstruct[c->player_y][c->player_x] == 'E')
	{
		sleep(1);
		ft_printf("\n¡Has completado el nivel, gracias por jugar!");
		mlx_destroy_image(c->mlx, c->floor_ptr);
		mlx_destroy_image(c->mlx, c->wall_ptr);
		mlx_destroy_image(c->mlx, c->player_ptr);
		mlx_destroy_image(c->mlx, c->coin_ptr);
		mlx_destroy_image(c->mlx, c->exit_ptr);
		mlx_destroy_window(c->mlx, c->mlx_win);
		free_mapstruct(c);
		exit(0);
	}
	return(0);
}

