#include "so_long.h"
int mlx_process(in *fw)
{
	fw->count->zero_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/0.xpm", &fw->count->width, &fw->count->height);
	fw->count->one_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/1.xpm", &fw->count->width, &fw->count->height);
	fw->count->two_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/2.xpm", &fw->count->width, &fw->count->height);
	fw->count->three_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/3.xpm", &fw->count->width, &fw->count->height);
	fw->count->four_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/4.xpm", &fw->count->width, &fw->count->height);
	fw->count->five_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/5.xpm", &fw->count->width, &fw->count->height);
	fw->count->six_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/6.xpm", &fw->count->width, &fw->count->height);
	fw->count->seven_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/7.xpm", &fw->count->width, &fw->count->height);
	fw->count->eight_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/8.xpm", &fw->count->width, &fw->count->height);
	fw->count->nine_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/9.xpm", &fw->count->width, &fw->count->height);
	fw->count->move_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/moves.xpm", &fw->count->widthmove, &fw->count->heightmove);
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
	//ft_printf("\n\nESTE ES EL VALOR DE WIDTH MOVE; %i\n", fw->count->widthmove);//	DEBUG
	handlemove(fw, fw->player, 0, 0);
	handlemove(fw, fw->snorlax, 0, 0);
	handlemove(fw, fw->ditto, 0, 0);
	return (0);
}
void put_imgs(in *fw)
{
	int y, x;
    void *buffer_image = mlx_new_image(fw->map->mlx, fw->map->columns * BPP, fw->map->lines * BPP);
	int bpp, size_line, endian;
    int *buffer_data = (int *)mlx_get_data_addr(buffer_image, &bpp, &size_line, &endian);
	y = 0;
	x = 0;
	while (y < fw->map->lines)
	{
		put_item_to_buffer(fw, buffer_data, y, x);
		x++;
		if (x >= fw->map->columns) {
			x = 0;
			y++;
		}
	}
    mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, buffer_image, 0, 0);
	draw_image(fw, fw->ditto->ptr, fw->ditto->xT* BPP, fw->ditto->yT * BPP);
	draw_image(fw, fw->snorlax->ptr, fw->snorlax->xT * BPP, fw->snorlax->yT * BPP);
	//agregarCeros(fw);
	draw_image(fw, fw->player->ptr, fw->player->xT* BPP, fw->player->yT * BPP);
	//draw_image(fw, fw->map->coin_ptr, 100, (fw->map->lines - 1) * BPP);//ESTO ES PARA VER SI PUEDO PONER LA IMAGEN DEL CONTADOR AQUI
	//draw_image(fw, fw->map->coin_ptr, 80, (fw->map->lines - 1) * BPP);//ESTO ES PARA VER SI PUEDO PONER LA IMAGEN DEL CONTADOR AQUI Y VER SI SE PUEDEN SUPERPONER LOS NUMEROS!!!
	mlx_do_sync(fw->map->mlx);//HE PROBADO A QUITAR ESTO Y EN EL PORTATIL TIENE MENOS BUG VISUAL DE CHIRIBITAS.
    mlx_destroy_image(fw->map->mlx, buffer_image);
}
void put_item_to_buffer(in *fw, int *buffer_data, int y, int x)
{
    int *image_data;
    void *image_ptr = NULL;
    int bpp, size_line, endian;
	if (fw->map->mapstruct[y][x] == '1')
	 	image_ptr = fw->map->wall_ptr;
	else if (fw->map->mapstruct[y][x] == '0')
		image_ptr = fw->map->floor_ptr;
	else if (fw->map->mapstruct[y][x] == 'P' || fw->map->mapstruct[y][x] == 'S' || fw->map->mapstruct[y][x] == 'D')//al agregar nuevos enemigos, poner su letra aqui para saber que estan en la capa del suelo
		image_ptr = fw->map->floor_ptr;
	else if (fw->map->mapstruct[y][x] == 'E')
	{
		image_ptr = fw->map->exit_ptr;
		fw->map->exit_x = x;
		fw->map->exit_y = y;
	}
	else if (fw->map->mapstruct[y][x] == 'C')
		image_ptr = fw->map->coin_ptr;
	else 
		image_ptr = fw->map->floor_ptr;
    if (image_ptr)
    {
        image_data = (int *)mlx_get_data_addr(image_ptr, &bpp, &size_line, &endian);
        int cell_width = size_line / (bpp / 8);
        int cell_height = BPP;
        for (int row = 0; row < cell_height; row++) {
            for (int col = 0; col < cell_width; col++) {
                int buffer_x = x * cell_width + col;
                int buffer_y = y * cell_height + row;
                int image_index = row * cell_width + col;
                int buffer_index = buffer_y * (fw->map->columns * cell_width) + buffer_x;
                buffer_data[buffer_index] = image_data[image_index];
            }
        }
    }
}
// Variables globales para el limitador de movimientos.
clock_t lastKeyPressTime = 0;
const int MIN_DELAY = 1000000; // 1 segundo en microsegundos
int key_hook(int keycode, in *fw)
{
	char letra = convertirKeyCodeALetra(keycode);
	ft_printf("\nHas pulsado la tecla %c!", letra);
	//ft_printf("\nVALOR DE IS W PRESSED: %i\n", fw->map->is_w_pressed);
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
int key_release(int keycode, in *fw)
{
	if (keycode == 0x61 || keycode == 0x41 || keycode == 0) // tecla a o A ¡EL ULTIMO ES PARA MAC!.
		fw->map->is_w_pressed = 0; // Se soltó la tecla "A"
	else if (keycode == 0x73 || keycode == 0x53 || keycode == 1) // tecla s o S
		fw->map->is_w_pressed = 0; // Se soltó la tecla "S"
	else if (keycode == 0x64 || keycode == 0x44 || keycode == 2) // tecla d o D
		fw->map->is_w_pressed = 0; // Se soltó la tecla "D"
	else if (keycode == 0x77 || keycode == 0x57 || keycode == 13) // tecla w o W
		fw->map->is_w_pressed = 0; // Se soltó la tecla "W"*/
    //ft_printf("\nVALOR DE IS W PRESSED: %i\n", fw->map->is_w_pressed);
	return 0;
}
int is_entity(in *fw, int y, int x, int first_time)
{
	if (fw->map->mapstruct[y][x] == 'S' && first_time == 0)
	{
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->floor_ptr, x * BPP, y * BPP);
		draw_image(fw, fw->snorlax->ptr, fw->snorlax->x * BPP, fw->snorlax->y * BPP);
		return(1);
	}
	else if (fw->map->mapstruct[y][x] == 'D' && first_time == 1)
	{
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->floor_ptr, x * BPP, y * BPP);
		draw_image(fw, fw->ditto->ptr, fw->ditto->x * BPP, fw->ditto->y * BPP);
		return(1);
	}
	else if (fw->map->mapstruct[y][x] == 'P' && first_time == 2)
	{
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->floor_ptr, x * BPP, y * BPP);
		draw_image(fw, fw->player->ptr, fw->player->x * BPP, fw->player->y * BPP);
		return(1);
	}
	return(0);
}
int agregarCeros(in *fw)
{
	//draw_counter(fw, fw->count->move_ptr, (fw->map->columns * BPP / 2) - fw->count->widthmove / 1.45, (fw->map->lines) * BPP);
	int j = 0;
	while (j <= fw->map->columns){
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->floor_ptr, (j * BPP) - fw->map->width, (fw->map->lines) * BPP);
		j++;
	}
	if (fw->map->moves < 0 || fw->map->moves > 999) {
        ft_printf("El número está fuera del rango válido (0-999).\n");
        exit(1);//ESTO PODRIA FALLAR CUIDADITO.
    }
	int unidad, centena, decena;
	unidad = 96;
	decena = 64;
	centena = 32;
	int u, c, d;
	c = fw->map->moves / 100;
	d = (fw->map->moves / 10) % 10;
	u = fw->map->moves % 10;
	if (fw->map->moves < 10){
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + centena), (fw->map->lines) * BPP);
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + decena), (fw->map->lines) * BPP);
		put_number(fw, fw->map->moves, unidad);
	}
	if (fw->map->moves < 100){
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + centena), (fw->map->lines) * BPP);
		put_number(fw, d, decena);
		put_number(fw, u, unidad);
	}else{
		put_number(fw, c, centena);
		put_number(fw, d, decena);
		put_number(fw, u, unidad);
	}
    return(0);
}
void put_number(in *fw, int number, int position){
	if (number == 0)
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
    else if (number == 1)
		draw_image(fw, fw->count->one_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
    else if (number == 2)
		draw_image(fw, fw->count->two_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
    else if (number == 3)
		draw_image(fw, fw->count->three_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
    else if (number == 4)
		draw_image(fw, fw->count->four_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
    else if (number == 5)
		draw_image(fw, fw->count->five_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
    else if (number == 6)
		draw_image(fw, fw->count->six_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
    else if (number == 7)
		draw_image(fw, fw->count->seven_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
	else if (number == 8)
		draw_image(fw, fw->count->eight_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
	else if (number == 9)
		draw_image(fw, fw->count->nine_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines) * BPP);
}