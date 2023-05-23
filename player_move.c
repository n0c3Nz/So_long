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
		if (c->mapstruct[c->player_y + 1][c->player_x] == '0' || c->mapstruct[c->player_y + 1][c->player_x] == 'P' || c->mapstruct[c->player_y + 1][c->player_x] == 'C' || (c->mapstruct[c->player_y + 1][c->player_x] == 'E' && c->coins_gained == c->coins))
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
		if (c->mapstruct[c->player_y][c->player_x - 1] == '0' || c->mapstruct[c->player_y][c->player_x - 1] == 'P' || c->mapstruct[c->player_y][c->player_x - 1] == 'C' || (c->mapstruct[c->player_y][c->player_x - 1] == 'E' && c->coins_gained == c->coins))
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

int loop_hook(map *c)
{
	wall_animation(c);
	coin_animation(c);
    return (0);
}
void wall_animation(map *c)
{
    static int counter;
    counter++;
    if (counter == 35000) // Asumiendo que el programa corre a 60 FPS, 180 frames son 3 segundos.
    {
        // Cambia el sprite de los 'wall'
        if (c->wall_ptr == c->wall_sprite_1)
            c->wall_ptr = c->wall_sprite_2;
        else
            c->wall_ptr = c->wall_sprite_1;

        // Redibuja el mapa
        put_imgs(c);
        counter = 0;
    }
}
void coin_animation(map *c) {
  static int counter = 0;
  static int a = 0;

  counter++;

  if (counter == 20000) {
    if (c->coin_ptr == c->coin_sprite_1 && a == 0) {
      c->coin_ptr = c->coin_sprite_2;
      a++;
    }
    else if (c->coin_ptr == c->coin_sprite_2) {
      c->coin_ptr = c->coin_sprite_1;
      a++;
    }
    else if (c->coin_ptr == c->coin_sprite_1 && a == 2) {
      c->coin_ptr = c->coin_sprite_3;
      a = 0;
    }
	else if (c->coin_ptr == c->coin_sprite_3)
		c->coin_ptr = c->coin_sprite_1;
    put_imgs(c);
    counter = 0;
  }
}
void check_coins(map *c)
{
	if (c->coins_gained == c->coins){
		c->exit_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/wall.xpm", &c->width, &c->height);
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->exit_ptr, c->exit_x * BPP, c->exit_y * BPP);
	}
}