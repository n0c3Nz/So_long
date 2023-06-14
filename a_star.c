#include <stdio.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

int moveEnemyTowardsPlayer(Point* enemy, const Point* player) {
    int dx = player->x - enemy->x;
    int dy = player->y - enemy->y;

    // Calcular la distancia euclidiana entre el enemigo y el jugador
    double distance = sqrt(dx*dx + dy*dy);

    // Normalizar el vector de dirección hacia el jugador
    double directionX = dx / distance;
    double directionY = dy / distance;

    // Mover el enemigo en la dirección del jugador
	if (getRandomBoolean()){
		enemy->x += (int)round(directionX);
	} else {
    	enemy->y += (int)round(directionY);
	}
    
	if (enemy->x == player->x && enemy->y == player->y)
		return (0);
	return(1);
}
int getRandomBoolean(void) {
    return rand() % 2;
}
int main() {
    Point enemy = {1, 2};
    Point player = {8, 9};

    printf("Posición inicial del enemigo: (%d, %d)\n", enemy.x, enemy.y);

    while (moveEnemyTowardsPlayer(&enemy, &player))
    	printf("Posición después de mover el enemigo: (%d, %d)\n", enemy.x, enemy.y);
	printf("Posición después de mover el enemigo: (%d, %d)\n", enemy.x, enemy.y);
    return 0;
}
