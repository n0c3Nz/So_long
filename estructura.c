#include "so_long.h"

int	main(int argc, char **argv)
{
	map c;
	
	c.map_name = argv[1];
	process_map_file(argc, argv, &c);
	return(0);
}