#include "so_long.h"

int mlx_process(map *c)
{
	c->wall_sprite_1 = mlx_xpm_file_to_image(c->mlx, "sprites/wall.xpm", &c->width, &c->height);
	c->wall_sprite_2 = mlx_xpm_file_to_image(c->mlx, "sprites/wall2.xpm", &c->width, &c->height);
	c->wall_ptr = c->wall_sprite_1;
	c->floor_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/floor.xpm", &c->width, &c->height);
	c->exit_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/exit.xpm", &c->width, &c->height);
	c->coin_sprite_1 = mlx_xpm_file_to_image(c->mlx, "sprites/coin.xpm", &c->width, &c->height);
	c->coin_sprite_2 = mlx_xpm_file_to_image(c->mlx, "sprites/coin2.xpm", &c->width, &c->height);
	c->coin_sprite_3 = mlx_xpm_file_to_image(c->mlx, "sprites/coin3.xpm", &c->width, &c->height);
	c->coin_ptr = c->coin_sprite_1;
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_down_t.xpm", &c->width, &c->height); 
	// c->player_img = mlx_get_data_addr(c->player_ptr, &c->width, &c->height, &c->endian);
	c->moves = 0;
	c->coins_gained = 0;
	put_imgs(c);
	handlemove(c, 0, 0);
	// ft_printf("\nPosición y:%i\nPosición x:%i", c->player_y, c->player_x);
	return (0);
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
	{
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->exit_ptr, x * BPP, y * BPP);
		c->exit_x = x;
		c->exit_y = y;
	}
	else if (c->mapstruct[y][x] == 'C')
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->coin_ptr, x * BPP, y * BPP);
}
int key_hook(int keycode, map *c)
{
	char letra = convertirKeyCodeALetra(keycode);
	ft_printf("\nHas pulsado la tecla %c!", letra);
	if (keycode == 0x61 || keycode == 0x41 || keycode == 0) // tecla a o A ¡EL ULTIMO ES PARA MAC!.
		handlekeys(c, 'a');
	else if (keycode == 0x73 || keycode == 0x53 || keycode == 1) // tecla s o S
		handlekeys(c, 's');
	else if (keycode == 0x64 || keycode == 0x44 || keycode == 2) // tecla d o D
		handlekeys(c, 'd');
	else if (keycode == 0x77 || keycode == 0x57 || keycode == 13) // tecla w o W
		handlekeys(c, 'w');
	else {
		ft_printf("\n¡Tecla inválida!");
		return (1);
	}
	check_coins(c);
	check_e(c);
	return (0);
}
void free_mapstruct(map *c)
{
	int i = 0;
	while (i <= c->lines)
	{
		if (c->mapstruct[i] != NULL)
		{
			free(c->mapstruct[i]);
		}
		i++;
	}
}
char convertirKeyCodeALetra(int keycode) {
    if (keycode >= 65 && keycode <= 90) {
        return (char)keycode;  // Códigos ASCII para letras mayúsculas
    } else if (keycode >= 97 && keycode <= 122) {
        keycode -= 32;
		return (char)keycode;  // Códigos ASCII para letras minúsculas
    } else {
        printf("Error: Código de tecla inválido.\n");
        return '\0';  // Valor nulo para indicar un error
    }
}