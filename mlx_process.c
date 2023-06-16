#include "so_long.h"

int mlx_process(in *fw)
{
	fw->map->wall_sprite_1 = mlx_xpm_file_to_image(fw->map->mlx, "sprites/wall.xpm", &fw->map->width, &fw->map->height);
	fw->map->wall_sprite_2 = mlx_xpm_file_to_image(fw->map->mlx, "sprites/wall2.xpm", &fw->map->width, &fw->map->height);
	fw->map->wall_ptr = fw->map->wall_sprite_1;
	fw->map->floor_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/floor.xpm", &fw->map->width, &fw->map->height);
	fw->map->exit_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/exit.xpm", &fw->map->width, &fw->map->height);
	fw->map->coin_sprite_1 = mlx_xpm_file_to_image(fw->map->mlx, "sprites/coin.xpm", &fw->map->width, &fw->map->height);
	fw->map->coin_sprite_2 = mlx_xpm_file_to_image(fw->map->mlx, "sprites/coin2.xpm", &fw->map->width, &fw->map->height);
	fw->map->coin_sprite_3 = mlx_xpm_file_to_image(fw->map->mlx, "sprites/coin3.xpm", &fw->map->width, &fw->map->height);
	fw->map->coin_ptr = fw->map->coin_sprite_1;
	fw->player->ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/p_down_t.xpm", &fw->map->width, &fw->map->height);
	fw->snorlax->ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/s_down_t.xpm", &fw->map->width, &fw->map->height);
	fw->ditto->ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/d_down_t.xpm", &fw->map->width, &fw->map->height);
	fw->map->moves = 0;
	fw->map->coins_gained = 0;
	put_imgs(fw);
	handlemove(fw, fw->player, 0, 0);
	handlemove(fw, fw->snorlax, 0, 0);
	handlemove(fw, fw->ditto, 0, 0);
	// ft_printf("\nPosición y:%i\nPosición x:%i", fw->map->player_y, fw->map->player_x);
	return (0);
}
void put_imgs(in *fw)
{
	int y;
	int x;

	y = 0;
	x = 0;

	while (y < fw->map->lines)
	{
		while (x < fw->map->columns)
		{
			put_item(fw, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}
void put_item(in *fw, int y, int x)
{
	if (fw->map->mapstruct[y][x] == '1')
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->wall_ptr, x * BPP, y * BPP);
	else if (fw->map->mapstruct[y][x] == '0')
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->floor_ptr, x * BPP, y * BPP);
	else if (fw->map->mapstruct[y][x] == 'E')
	{
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->exit_ptr, x * BPP, y * BPP);
		fw->map->exit_x = x;
		fw->map->exit_y = y;
	}
	else if (fw->map->mapstruct[y][x] == 'C')
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->coin_ptr, x * BPP, y * BPP);
}
// Variables globales para el limitador de movimientos.
clock_t lastKeyPressTime = 0;
const int MIN_DELAY = 1000000; // 1 segundo en microsegundos

int key_hook(int keycode, in *fw)
{
	char letra = convertirKeyCodeALetra(keycode);
	ft_printf("\nHas pulsado la tecla %c!", letra);
	if (hasEnoughTimeElapsed())
	{
		if (keycode == 0x61 || keycode == 0x41 || keycode == 0) // tecla a o A ¡EL ULTIMO ES PARA MAC!.
			handlekeys(fw, 'a');
		else if (keycode == 0x73 || keycode == 0x53 || keycode == 1) // tecla s o S
			handlekeys(fw, 's');
		else if (keycode == 0x64 || keycode == 0x44 || keycode == 2) // tecla d o D
			handlekeys(fw, 'd');
		else if (keycode == 0x77 || keycode == 0x57 || keycode == 13) // tecla w o W
			handlekeys(fw, 'w');
		else
		{
			ft_printf("\n¡Tecla inválida!");
			return (1);
		}
	}
	return (0);
}
void free_mapstruct(in *fw)
{
	int i = 0;
	while (i <= fw->map->lines)
	{
		if (fw->map->mapstruct[i] != NULL)
		{
			free(fw->map->mapstruct[i]);
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
    } else
        return '\0';  // Valor nulo para indicar un error
}