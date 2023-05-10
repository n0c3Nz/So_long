#include "so_long.h"

int	main(int argc, char **argv)
{
	map c;
	
	c.map_name = argv[1];
	process_map_file(argc, argv, &c);
	c.mlx = mlx_init();
	c.mlx_win = mlx_new_window(c.mlx, c.columns * 32, c.lines * 32, "Juego");
	mlx_process(&c);
	mlx_loop(c.mlx);
	return(0);
}