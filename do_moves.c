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
#include "mlx.h"

void draw_image(void *mlx_ptr, void *win_ptr, void *img_ptr, int start_x, int start_y, int width, int height, int exclude_color)
{
    int x, y;
    int color;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            color = get_pixel_color(img_ptr, x, y);
            if (color != exclude_color) // si el color no es el color excluido
            {
                mlx_pixel_put(mlx_ptr, win_ptr, start_x + x, start_y + y, color);
            }
            x++;
        }
        y++;
    }
}

char *getdirectionimage1(int coordx, int coordy){
	char *imgstep1;
	imgstep1 = "sprites/p_down_step_t.xpm";//default
	if (coordx == -1) //a
		imgstep1 = "sprites/p_left_step_t.xpm";
	else if (coordy == 1) //s
		imgstep1 = "sprites/p_down_step_t.xpm";
	else if (coordx == 1) //d
		imgstep1 = "sprites/p_right_step_t.xpm";
	else if (coordy == -1) //w
		imgstep1 = "sprites/p_up_step_t.xpm";
	return imgstep1;
}
char *getdirectionimage2(int coordx, int coordy){
	char *imgstep2;
	imgstep2 = "sprites/p_down_step_2_t.xpm";//default
	if (coordx == -1) //a
		imgstep2 = "sprites/p_left_step_2_t.xpm";
	else if (coordy == 1) //s
		imgstep2 = "sprites/p_down_step_2_t.xpm";
	else if (coordx == 1) //d
		imgstep2 = "sprites/p_right_step_2_t.xpm";
	else if (coordy == -1) //w
		imgstep2 = "sprites/p_up_step_2_t.xpm";
	return imgstep2;
}
char *getdirectionstatic(int coordx, int coordy){
	char *imgstep2;
	imgstep2 = "sprites/p_down_t.xpm";//default
	if (coordx == -1) //a
		imgstep2 = "sprites/p_left_t.xpm";
	else if (coordy == 1) //s
		imgstep2 = "sprites/p_down_t.xpm";
	else if (coordx == 1) //d
		imgstep2 = "sprites/p_right_transparente.xpm";
	else if (coordy == -1) //w
		imgstep2 = "sprites/p_up_t.xpm";
	return imgstep2;
}
float getsumax(int coordx, float lx){
	float sumax = 0;
	if (coordx == -1) //a
		sumax -= lx;
	else if (coordx == 1) //d
		sumax = lx;
	return sumax;
}
float getsumay(int coordy, float lx){
	float sumay = 0;
	if (coordy == 1) //s
		sumay = lx;
	else if (coordy == -1) //w
		sumay -= lx;
	return sumay;
}
int drawcharacter(int stepanimation, map *c, int coordx, int coordy) {
	if (stepanimation == 2)
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, getdirectionimage2(coordx,coordy), &c->width, &c->height);
		mlx_do_sync(c->mlx);
	}
	else if (stepanimation == 4)
	{
		c->player_ptr = mlx_xpm_file_to_image(c->mlx, getdirectionimage1(coordx,coordy), &c->width, &c->height);
		mlx_do_sync(c->mlx);
		stepanimation = 0;
	}
	return stepanimation;
}
void initplayer(map *c, int coordx, int coordy) {
	c->mapstruct[c->player_y][c->player_x] = '0';//fallara esto
	if (c->mapstruct[c->player_y + coordy][c->player_x + coordx] != 'E')
		c->mapstruct[c->player_y + coordy][c->player_x + coordx] = 'P';
}
void handlemove(map *c, int coordx, int coordy)
{
	initplayer(c, coordx, coordy);
	int stepanimation = 0;
	float lx = 0;
	clock_t inicio = clock();

	while (lx < 1) {
		stepanimation++;
		lx += 0.1;
		stepanimation = drawcharacter(stepanimation, c, coordx, coordy);
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, (c->player_x + coordx) * BPP, (c->player_y + coordy) * BPP);
		draw_image(c->mlx, c->mlx_win, c->player_ptr, (c->player_x + getsumax(coordx, lx)) * BPP, (c->player_y + getsumay(coordy, lx)) * BPP, c->width, c->height, get_pixel_color(c->player_ptr, 0, 0));
		mlx_do_sync(c->mlx);
		inicio = timer(inicio, 0.035);
	}
	c->player_x += coordx;
	c->player_y += coordy;
	c->max_actions--;
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->floor_ptr, c->player_x * BPP, c->player_y * BPP);
	c->player_ptr = mlx_xpm_file_to_image(c->mlx, getdirectionstatic(coordx, coordy), &c->width, &c->height);// PRUEBA
	draw_image(c->mlx, c->mlx_win, c->player_ptr, c->player_x * BPP, c->player_y * BPP, c->width, c->height, get_pixel_color(c->player_ptr, 0, 0));	
	mlx_do_sync(c->mlx);
	c->moves += 1;
}


/*ESTO ES EL TIMER DE LA ANIMACION*/

int timer(clock_t inicio, double tiempo_deseado)
{
	clock_t actual = clock();
	double tiempo_transcurrido = (double)(actual - inicio) / CLOCKS_PER_SEC;
	double tiempo_restante = tiempo_deseado - tiempo_transcurrido;
	// Esperar el tiempo restante para alcanzar el tiempo deseado
	double tiempo_espera = tiempo_restante * CLOCKS_PER_SEC;
	clock_t espera_final = actual + (clock_t)tiempo_espera;
	while (clock() < espera_final)// Esperar...
	inicio = clock();
	return(inicio);
}