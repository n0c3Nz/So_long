#include "so_long.h"

int move_up(map *c)
{
	ft_printf("\nHas pulsado la tecla W!");
	if (c->mapstruct[c->player_y - 1][c->player_x] != '1')
	{
		if (c->mapstruct[c->player_y - 1][c->player_x] == 'C')
			c->coins_gained += 1;
		if (c->mapstruct[c->player_y - 1][c->player_x] == '0' || c->mapstruct[c->player_y - 1][c->player_x] == 'P' || c->mapstruct[c->player_y - 1][c->player_x] == 'C' || c->mapstruct[c->player_y - 1][c->player_x] == 'E' && c->coins_gained == c->coins)
		{
			c->mapstruct[c->player_y][c->player_x] = '0';
			if (c->mapstruct[c->player_y - 1][c->player_x] != 'E')
				c->mapstruct[c->player_y - 1][c->player_x] = 'P';
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
			c->player_y -= 1;
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
			c->moves += 1;
			ft_printf("\n Número de movimientos %i", c->moves);
			ft_printf("\n Coins %i/%i", c->coins_gained, c->coins);
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
		if (c->mapstruct[c->player_y + 1][c->player_x] == '0' || c->mapstruct[c->player_y + 1][c->player_x] == 'P' || c->mapstruct[c->player_y + 1][c->player_x] == 'C' || c->mapstruct[c->player_y + 1][c->player_x] == 'E' && c->coins_gained == c->coins)
		{
			c->mapstruct[c->player_y][c->player_x] = '0';
			if (c->mapstruct[c->player_y + 1][c->player_x] != 'E')
				c->mapstruct[c->player_y + 1][c->player_x] = 'P';
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
			c->player_y += 1;
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
			c->moves += 1;
			ft_printf("\n Número de movimientos %i", c->moves);
			ft_printf("\n Coins %i/%i", c->coins_gained, c->coins);
		}
	}
}

int move_right(map *c)
{
	ft_printf("\nHas pulsado la tecla D!");
	if (c->mapstruct[c->player_y][c->player_x + 1] != '1')
	{
		if (c->mapstruct[c->player_y][c->player_x + 1] == 'C')
			c->coins_gained += 1;
		if (c->mapstruct[c->player_y][c->player_x + 1] == '0' || c->mapstruct[c->player_y][c->player_x + 1] == 'P' || c->mapstruct[c->player_y][c->player_x + 1] == 'C' || c->mapstruct[c->player_y][c->player_x + 1] == 'E' && c->coins_gained == c->coins)
		{
			c->mapstruct[c->player_y][c->player_x] = '0';
			if (c->mapstruct[c->player_y][c->player_x + 1] != 'E')
				c->mapstruct[c->player_y][c->player_x + 1] = 'P';
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
			c->player_x += 1;
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
			c->moves += 1;
			ft_printf("\n Número de movimientos %i", c->moves);
			ft_printf("\n Coins %i/%i", c->coins_gained, c->coins);
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
		if (c->mapstruct[c->player_y][c->player_x - 1] == '0' || c->mapstruct[c->player_y][c->player_x - 1] == 'P' || c->mapstruct[c->player_y][c->player_x - 1] == 'C' || c->mapstruct[c->player_y][c->player_x - 1] == 'E' && c->coins_gained == c->coins)
		{
			c->mapstruct[c->player_y][c->player_x] = '0';
			if (c->mapstruct[c->player_y][c->player_x - 1] != 'E')
				c->mapstruct[c->player_y][c->player_x - 1] = 'P';
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
			c->player_x -= 1;
			mlx_put_image_to_window(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP);
			c->moves += 1;
			ft_printf("\n Número de movimientos %i", c->moves);
			ft_printf("\n Coins %i/%i", c->coins_gained, c->coins);
		}
		return(0);
	}
	return(1);
}

int check_e(map *c){
	if (c->mapstruct[c->player_y][c->player_x] == 'E')
	{
		ft_printf("\n¡Has completado el nivel, gracias por jugar!");
		exit(0);
	}
	return(0);
}