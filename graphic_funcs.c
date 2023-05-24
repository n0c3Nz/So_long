#include "so_long.h"

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
		c->exit_ptr = mlx_xpm_file_to_image(c->mlx, "sprites/exit_open.xpm", &c->width, &c->height);
		mlx_put_image_to_window(c->mlx, c->mlx_win, c->exit_ptr, c->exit_x * BPP, c->exit_y * BPP);
	}
}