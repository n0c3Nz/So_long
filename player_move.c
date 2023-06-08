#include "so_long.h"

int handlekeys(map *c, char key) {	
	int coordX;
	coordX = 0;
	int coordY;
	coordY = 0;
	if (key == 'a')
		coordX = -1;
	else if (key == 's') 
		coordY = 1;
	else if (key == 'd') 
		coordX = 1;
	else if (key == 'w') 
		coordY = -1;
	if (c->mapstruct[c->player_y + coordY][c->player_x + coordX] != '1')
	{
		if (c->mapstruct[c->player_y + coordY][c->player_x + coordX] == 'C')
			c->coins_gained += 1;
		check_coins(c);
		if (c->mapstruct[c->player_y + coordY][c->player_x + coordX] == '0' || c->mapstruct[c->player_y + coordY][c->player_x + coordX] == 'P' || c->mapstruct[c->player_y + coordY][c->player_x + coordX] == 'C' || (c->mapstruct[c->player_y + coordY][c->player_x + coordX] == 'E' && c->coins_gained == c->coins))
		{
			ft_printf("\nNúmero de movimientos %i", c->moves);
			ft_printf("\nCoins %i/%i\n", c->coins_gained, c->coins);
			handlemove(c, coordX, coordY);
			return (0);
		}
	}
	return (1);
}

int check_e(map *c){
	if (c->mapstruct[c->player_y][c->player_x] == 'E')
	{
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

