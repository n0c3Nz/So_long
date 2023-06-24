#include "so_long.h"

int handlekeys(in *fw, char key)
{	
	int coordX;
	int coordY;

	coordX = 0;
	coordY = 0;
	if (key == 'a')
		coordX = -1;
	else if (key == 's') 
		coordY = 1;
	else if (key == 'd') 
		coordX = 1;
	else if (key == 'w') 
		coordY = -1;
	return (check_move(fw, coordX, coordY));
}

int check_move(in *fw, int coordX, int coordY)
{
	ft_printf("\nVALOR DE LA SIGUIENTE CASILLA: %c\n",fw->map->mapstruct[fw->player->y + coordY][fw->player->x + coordX]);
	if (fw->map->mapstruct[fw->player->y + coordY][fw->player->x + coordX] != '1')
	{
		if (fw->map->mapstruct[fw->player->y + coordY][fw->player->x + coordX] == 'C'){
			fw->map->coins_gained += 1;
			check_coins(fw);
		}
	if ((fw->map->mapstruct[fw->player->y + coordY][fw->player->x + coordX] == '0') || 
	    (fw->map->mapstruct[fw->player->y + coordY][fw->player->x + coordX] == 'C') ||
	    ((fw->map->mapstruct[fw->player->y + coordY][fw->player->x + coordX] == 'E') && 
	    (fw->map->coins_gained == fw->map->coins)))
		{
			handlemove(fw, fw->player, coordX, coordY);
			fw->map->moves += 1;
			ft_printf("\nNúmero de movimientos %i\nCoins %i/%i\n", fw->map->moves, fw->map->coins_gained, fw->map->coins);
			return (0);
		}
	}
	return(1);
}

int check_e(in *fw){
	if (fw->player->y == fw->map->exit_y && fw->player->x == fw->map->exit_x)
	{
		ft_printf("\n¡Has completado el nivel, gracias por jugar!\n");
		mlx_destroy_image(fw->map->mlx, fw->map->floor_ptr);
		mlx_destroy_image(fw->map->mlx, fw->map->wall_ptr);
		mlx_destroy_image(fw->map->mlx, fw->player->ptr);
		mlx_destroy_image(fw->map->mlx, fw->map->coin_ptr);
		mlx_destroy_image(fw->map->mlx, fw->map->exit_ptr);
		mlx_destroy_window(fw->map->mlx, fw->map->mlx_win);
		free_mapstruct(fw);
		exit(0);
	}
	return(0);
}
