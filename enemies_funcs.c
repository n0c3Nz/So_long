#include "so_long.h"

int moveEnemyTowardsPlayer(in *fw, entity *enemy, entity *player) {
 int dx = player->x - enemy->x;
    int dy = player->y - enemy->y;

    // Calcular la distancia euclidiana entre el enemigo y el jugador
    double distance = sqrt(dx*dx + dy*dy);

    // Normalizar el vector de dirección hacia el jugador
    double directionX = dx / distance;
    double directionY = dy / distance;

	int posx = 0;
	int posy = 0;
    // Mover el enemigo en la dirección del jugador
	if (getRandomBoolean()){
		posx += (int)round(directionX);
		ft_printf("\nDIRECCION: %i\n", (int)round(directionX));
		if (posx == 0) {
			posy += (int)round(directionY);
		}
	} else {
    	posy += (int)round(directionY);
		ft_printf("\nDIRECCION: %i\n", (int)round(directionY));
		if (posy == 0){
			posx += (int)round(directionX);
		}
	}
    handlemove(fw, enemy, posx, posy);
	if (enemy->x == player->x && enemy->y == player->y)
		return (0);
	return(1);
}

int getRandomBoolean(void) {
    return rand() % 2;
}
