#include "so_long.h"

int	main(int argc, char **argv)
{
	map c;
	entity player;
	entity ditto;
	entity snorlax;
	in fw;//Framework
	fw.map = &c;
	fw.player = &player;
	fw.ditto = &ditto;
	fw.snorlax = &snorlax;
	fw.player->value = 'P';
	fw.snorlax->value = 'S';
	fw.ditto->value = 'D';
	fw.ditto->iswalking = false;
	fw.snorlax->iswalking = false;
	fw.player->iswalking = false;
	XInitThreads();
	c.env_animation = clock();
	c.map_name = argv[1];
	check_argc(argc);
	check_file_extension(argv[1], ".ber");
	process_map_file(&fw);
	fw.map->mlx = mlx_init();
	fw.map->mlx_win = mlx_new_window(fw.map->mlx, fw.map->columns * BPP, fw.map->lines * BPP, "Pokémon Adventures");
	mlx_process(&fw);
	mlx_key_hook(c.mlx_win, key_hook, &fw);
	mlx_loop_hook(c.mlx, loop_hook, &fw);
	mlx_loop(fw.map->mlx);
	return(0);
}