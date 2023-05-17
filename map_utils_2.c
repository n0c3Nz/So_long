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
int path_finder(map *c)
{
	int visited[c->lines][c->columns];
	ft_memset(visited, 0, sizeof(visited));
	int pathExists = dfs(c->player_y, c->player_x, visited, c );
    if (pathExists) {
        printf("Hay un camino posible desde 'P' a 'E'.\n");
    } else {
        printf("No hay un camino posible desde 'P' a 'E'.\n");
    }

    return 0;
}
int dfs(int row, int col, int visited[7][7], map *c)
{
    // Verificar si estamos fuera de los límites del mapa
    if (row < 0 || row >= c->lines || col < 0 || col >= c->columns)
        return 0;
    // Verificar si hemos llegado al punto 'E'
    if (c->mapstruct[row][col] == 'E')
        return 1;
    // Verificar si el punto actual es transitable ('0' o 'P') y no ha sido visitado
    if ((c->mapstruct[row][col] == '0' || c->mapstruct[row][col] == 'C' || c->mapstruct[row][col] == 'P') && !visited[row][col]) {
        // Marcar el punto actual como visitado
        visited[row][col] = 1;
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