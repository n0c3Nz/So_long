#include "so_long.h"

int last_line_analyzer(char *buffer, map *c)
{
	int a;
	a = 0;
	if (ft_strlen(buffer) != c->columns)
	{
		perror("Mapa inconsistente en la última línea");
		exit(1);
	}
	while (buffer[a] != '\0')
	{
		if (buffer[a] != '1')
		{
			perror("Error, mapa sin cerrar en la última línea");
			exit(1);
		}
		a++;
	}
	return(0);
}