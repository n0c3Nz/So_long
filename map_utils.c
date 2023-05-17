#include "so_long.h"

void check_argc(int argc)
{
	if (argc < 2)
	{
		perror("No hay argumentos");
		exit(1);	
	}
}
int check_line(char *buffer, int *i, map *c)
{
	static int e;
	buffer[*i] = '\0';
    map_validator(buffer, c);
	c->mapstruct[e] = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	ft_strlcpy(c->mapstruct[e], buffer, ft_strlen(buffer) + 1);
	ft_printf("%s\n", c->mapstruct[e]);
	e++;
    *i = 0;
    return 0;
}
int first_line_analyzer(char *buffer, map *c)
{
	c->columns = (ft_strlen(buffer));
	int a;
	a = 0;
	while (buffer[a] != '\0')
	{
		if (buffer[a] != '1' )
		{
			perror("Primera línea sin cerrar");
			exit(1);
		}
		a++;
	}
	if (a < 3)
	{
		perror("Mapa demasiado pequeño");
		exit(1);
	}
	return(0);
}
int body_line_analyzer(char *buffer, map *c)
{
	int a;
	static int e;
	a = 0;
	//ft_printf("\nen body_line_analyzer el buffer mide %i y el modelo a seguir %i\n", ft_strlen(buffer), c->columns);
	if (ft_strlen(buffer) != c->columns || buffer[a] != '1' || buffer[(c->columns - 1)] != '1')
	{
		perror("mapa inconsistente");
		exit(1);
	}
	a++;
	while(a != (c->columns - 1))
	{
		if (buffer[a] == 'P')
		{
			c->player_y = e + 1;
			c->player_x = a;
		}
		search_items(buffer[a], c);//aqui es ir revisando el cuerpo del mapa e ir añadiendo si hay un coin pues coin++;
		a++;
	}
	e++;
	return(0);
}
int search_items(char item, map *c)
{
	if (item == 'C')
		c->coins = c->coins + 1;
	else if (item == 'E')
		c->exitp = c->exitp + 1;
	else if (item == 'P')
		c->startp = c->startp + 1;
	else if (item == '0')
		c->zeros = c->zeros + 1;
	else if (item == '1')
		c->ones = c->ones + 1;
	else
	{
		perror("Carácter no válido en el mapa");
		exit(1);
	}
	return(0);
}