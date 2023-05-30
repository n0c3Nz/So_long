#include "so_long.h"

int get_pixel_color(void *img_ptr, int x, int y)
{
    int bpp;
    int size_line;
    int endian;
    char *img_data;

    img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    int color = *(int *)(img_data + y * size_line + x * (bpp / 8)); // color del pixel en (x,y)
    return color;
}
void draw_image(void *mlx_ptr, void *win_ptr, void *img_ptr, int start_x, int start_y, int width, int height, int exclude_color)
{
    int x, y;
    int color;

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            color = get_pixel_color(img_ptr, x, y);
            if (color != exclude_color) // si el color no es el color excluido
            {
                mlx_pixel_put(mlx_ptr, win_ptr, start_x + x, start_y + y, color);
            }
        }
    }
}
void do_right(map *c)
{
	static int i;
	c->mapstruct[c->player_y][c->player_x] = '0';
	if (c->mapstruct[c->player_y][c->player_x + 1] != 'E')
		c->mapstruct[c->player_y][c->player_x + 1] = 'P';

	ft_printf("\n%i\n", get_pixel_color(c->player_ptr, 0, 0));
	float temp = c->player_x;
	while (temp < c->player_x + 1){
		if (i == 2)
		{
			c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_right_step_2_t.xpm", &c->width, &c->height);
			mlx_do_sync(c->mlx);
		}
		else if (i == 4)
		{
			c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_right_step_t.xpm", &c->width, &c->height);
			mlx_do_sync(c->mlx);
			i = 0;
		}
		i++;		
		temp += 0.1;
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, (c->player_x + 1) * BPP, c->player_y * BPP);
		draw_image(c->mlx, c->mlx_win, c->player_ptr, temp * BPP, c->player_y * BPP, c->width, c->height, get_pixel_color(c->player_ptr, 0, 0));
		mlx_do_sync(c->mlx);
		usleep(30000);
	}
	c->player_x += 1;
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/p_right_transparente.xpm", &c->width, &c->height);// PRUEBA
	draw_image(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP, c->width, c->height, get_pixel_color(c->player_ptr, 0, 0));	
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