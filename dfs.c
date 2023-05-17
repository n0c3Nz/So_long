#include <stdio.h>

#define ROWS 5
#define COLS 5

char map[ROWS][COLS] = {
    "11111",
    "100E1",
    "10001",
    "1P001",
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

    // Verificar si el punto actual es transitable ('0') y no ha sido visitado
    if (map[row][col] == '0' && !visited[row][col]) {
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
    int startRow = 3;  // Fila del punto 'P'
    int startCol = 1;  // Columna del punto 'P'

    int visited[ROWS][COLS] = {0};  // Inicializar matriz de visitados

    int pathExists = dfs(startRow, startCol, visited);

    if (pathExists) {
        printf("Hay un camino posible desde 'P' a 'E'.\n");
    } else {
        printf("No hay un camino posible desde 'P' a 'E'.\n");
    }

    return 0;
}
