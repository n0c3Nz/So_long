#include "so_long.h"

int loop_hook(in *fw)
{
	clock_t actual = clock();

	double timerDitto = (double)(actual - fw->ditto->walktimer) / CLOCKS_PER_SEC;
	if (timerDitto >= 0.2){
		moveEnemyTowardsPlayer(fw, fw->ditto, fw->player);
		fw->ditto->walktimer = actual;
	}
	double timerSnorkax = (double)(actual - fw->snorlax->walktimer) / CLOCKS_PER_SEC;
	if (timerSnorkax >= 0.5){
		wall_animation(fw);
		coin_animation(fw);
		moveEnemyTowardsPlayer(fw, fw->snorlax, fw->player);
		fw->snorlax->walktimer = actual;
	}
    return (0);
}
void wall_animation(in *fw) {
	clock_t actual = clock();
	fw->map->env_animation = actual;
	if (fw->map->wall_ptr == fw->map->wall_sprite_1)
        fw->map->wall_ptr = fw->map->wall_sprite_2;
    else
		fw->map->wall_ptr = fw->map->wall_sprite_1;
	put_imgs(fw);
}
void coin_animation(in *fw) {
  static int a = 0;
    if (fw->map->coin_ptr == fw->map->coin_sprite_1 && a == 0) {
      fw->map->coin_ptr = fw->map->coin_sprite_2;
      a++;
    }
    else if (fw->map->coin_ptr == fw->map->coin_sprite_2) {
      fw->map->coin_ptr = fw->map->coin_sprite_1;
      a++;
    }
    else if (fw->map->coin_ptr == fw->map->coin_sprite_1 && a == 2) {
      fw->map->coin_ptr = fw->map->coin_sprite_3;
      a = 0;
    }
	else if (fw->map->coin_ptr == fw->map->coin_sprite_3)
		fw->map->coin_ptr = fw->map->coin_sprite_1;
	put_imgs(fw);
}
void check_coins(in *fw)
{
	if (fw->map->coins_gained >= fw->map->coins){
		fw->map->exit_ptr = mlx_xpm_file_to_image(fw->map->mlx, "sprites/exit_open.xpm", &fw->map->width, &fw->map->height);
		mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->exit_ptr, fw->map->exit_x * BPP, fw->map->exit_y * BPP);
	}
}