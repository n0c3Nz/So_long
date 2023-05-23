#include "so_long.h"

int	main(int argc, char **argv)
{
	map c;
	c.map_name = argv[1];
	process_map_file(argc, argv, &c);
	c.mlx = mlx_init();
	c.mlx_win = mlx_new_window(c.mlx, c.columns * BPP, c.lines * BPP, "Juego");
	mlx_process(&c);
	// En tu función principal, después de llamar a mlx_process
	mlx_key_hook(c.mlx_win, key_hook, &c);
	mlx_loop_hook(c.mlx, loop_hook, &c);
	mlx_loop(c.mlx);
	return(0);
}