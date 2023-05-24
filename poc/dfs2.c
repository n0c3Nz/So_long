#include <stdio.h>

#define ROWS 5
#define COLS 5

char map[ROWS][COLS] = {
    "11111",
    "101E1",
    "10101",
    "1P001",
    "11111"
};

int isValidPosition(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

int dfs(int row, int col, int destRow, int destCol, int visited[ROWS][COLS]) {
    if (row == destRow && col == destCol) {
        return 1; // Se ha encontrado un camino válido
    }

    visited[row][col] = 1; // Marcar la posición actual como visitada

    // Generar posiciones vecinas
    int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < 4; i++) {
        int newRow = row + neighbors[i][0];
        int newCol = col + neighbors[i][1];

        if (isValidPosition(newRow, newCol) && map[newRow][newCol] == '0' && !visited[newRow][newCol]) {
            if (dfs(newRow, newCol, destRow, destCol, visited)) {
                return 1; // Se ha encontrado un camino válido
            }
        }
    }

    visited[row][col] = 0; // Marcar la posición actual como no visitada
    return 0; // No se ha encontrado un camino válido
}

int main() {
    int startRow = 3;  // Fila del punto 'P'
    int startCol = 1;  // Columna del punto 'P'
    int destRow = 1;   // Fila del punto 'E'
    int destCol = 3;   // Columna del punto 'E'

    map[startRow][startCol] = '0';  // Hacer que 'P' sea transitable

    int visited[ROWS][COLS] = {0};  // Inicializar matriz de visitados

    int pathExists = dfs(startRow, startCol, destRow, destCol, visited);

    if (pathExists) {
        printf("Se ha encontrado un camino válido desde 'P' a 'E'.\n");
    } else {
        printf("No hay un camino válido desde 'P' a 'E'.\n");
    }

    return 0;
}

// ESTE SISTEMA SIRVE PARA SABER SI EXISTE UN CAMINO VÁLIDO DE DESDE P a E
// SABIENDO SUS UBICACIONES.