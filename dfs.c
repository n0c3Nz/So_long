#include <stdio.h>

#define ROWS 5
#define COLS 5

char map[ROWS][COLS] = {
    "11111",
    "1P101",
    "10101",
    "100E1",
    "11111"
};

int dfs(int row, int col, int visited[ROWS][COLS]) {
    // Verificar si estamos fuera de los límites del mapa
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }

    // Verificar si hemos llegado al punto 'E'
    if (map[row][col] == 'E') {
        return 1;
    }

    // Verificar si el punto actual es transitable ('0' o 'P') y no ha sido visitado
    if ((map[row][col] == '0' || map[row][col] == 'P') && !visited[row][col]) {
        // Marcar el punto actual como visitado
        visited[row][col] = 1;

        // Llamar recursivamente a DFS en los vecinos
        if (dfs(row - 1, col, visited) ||
            dfs(row + 1, col, visited) ||
            dfs(row, col - 1, visited) ||
            dfs(row, col + 1, visited)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int startRow = 1;  // Fila del punto 'P'
    int startCol = 1;  // Columna del punto 'P'

    int visited[ROWS][COLS] = {0};  // Inicializar matriz de visitados

    int pathExists = dfs(startRow, startCol, visited);
	printf("\nResultado de la función: %i\n", pathExists);
    if (pathExists) {
        printf("Hay un camino posible desde 'P' a 'E'.\n");
    } else {
        printf("No hay un camino posible desde 'P' a 'E'.\n");
    }
	int i = COLS - 1;
	int f = ROWS - 1;
	while (f >= 0) {
	    while (i >= 0) {
	        printf("%d", visited[f][i]);
	        i--;
	    }
	    printf("\n");
	    i = COLS - 1;
	    f--;
}
    return 0;
}


// ESTE SISTEMA DFS trata de encontrar E desde P.
