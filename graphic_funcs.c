#include "so_long.h"

int loop_hook(map *c)
{
	clock_t actual = clock();
    double tiempo_transcurrido = (double)(actual - c->env_animation) / CLOCKS_PER_SEC;

    if (tiempo_transcurrido >= 0.5) {
        wall_animation(c);
		coin_animation(c);
        c->env_animation = actual;
    }
    return (0);
}
void wall_animation(map *c)
{
	if (c->wall_ptr == c->wall_sprite_1)
        c->wall_ptr = c->wall_sprite_2;
    else
        c->wall_ptr = c->wall_sprite_1;
    put_imgs(c);
}
void coin_animation(map *c) {
  static int a = 0;
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
}
void check_coins(map *c)
{
	if (c->coins_gained >= c->coins){
		c->exit_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/exit_open.xpm", &c->width, &c->height);
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->exit_ptr, c->exit_x * BPP, c->exit_y * BPP);
	}
}