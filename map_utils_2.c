#include "so_long.h"

int last_line_analyzer(char *buffer, map *c)
{
	int a;
	a = 0;
	if (ft_strlen(buffer) != (size_t)c->columns)
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

int path_finder(map *c)
{
    int i;
	
	i = 0;
	int **visited = malloc(c->lines * sizeof(int *));
//  int **visited = (int **)ft_calloc(c->lines, sizeof(int *));
    while(i < c->lines)
	{
        visited[i] = ft_calloc(c->columns, sizeof(int));
		i++;
	}
    int pathExists = dfs(c->player_y, c->player_x, visited, c);
    if (pathExists)
        printf("\nHay un camino posible desde 'P' a 'E'.\n");
	else
        printf("\nNo hay un camino posible desde 'P' a 'E'.\n");

	// Liberar la memoria de la matriz
    i = 0;
	while(i < c->lines){
        free(visited[i]);
		i++;
	}
	free(visited);

    return(pathExists);
}
int dfs(int row, int col, int **visited, map *c)
{
    // Verificar si estamos fuera de los límites del mapa
	if (row < 0 || row >= c->lines || col < 0 || col >= c->columns)
        return 0;
    // Verificar si el punto actual ya ha sido visitado
    if (visited[row][col])
        return 0;
    // Marcar el punto actual como visitado
    visited[row][col] = 1;
    // Verificar si hemos llegado al punto 'E'
    if (c->mapstruct[row][col] == 'E')
        return 1;
    // Verificar si el punto actual es transitable ('0' o 'P')
    if (c->mapstruct[row][col] == '0' || c->mapstruct[row][col] == 'C' || c->mapstruct[row][col] == 'P') {
        // Llamar recursivamente a DFS en los vecinos
        if (dfs(row - 1, col, visited, c) ||
            dfs(row + 1, col, visited, c) ||
            dfs(row, col - 1, visited, c) ||
            dfs(row, col + 1, visited, c)) {
            return 1;
        }
    }

    return 0;
}