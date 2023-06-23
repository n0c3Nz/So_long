#include "so_long.h"

int	moveEnemyTowardsPlayer(in *fw, entity *enemy, entity *player) {

	int	dx = player->x - enemy->x;
    int	dy = player->y - enemy->y;

    // Calcular la distancia euclidiana entre el enemigo y el jugador
    double distance = sqrt(dx*dx + dy*dy);

    // Normalizar el vector de dirección hacia el jugador
    double directionX = dx / distance;
    double directionY = dy / distance;

	int	posx = 0;
	int	posy = 0;
    // Mover el enemigo en la dirección del jugador
	if (getRandomBoolean()) {
        posx += (int)round(directionX);
        if (posx == 0 && iswall(fw, enemy, posx, posy)) {
            posy += (int)round(directionY);
        }
    } else {
        posy += (int)round(directionY);
        if (posy == 0 && iswall(fw, enemy, posx, posy)) {
            posx += (int)round(directionX);
        }
    }

    // Si la nueva dirección también es un obstáculo o movimiento en diagonal, buscar otra dirección
	if (iswall(fw, enemy, posx, posy) || (posx != 0 && posy != 0)) {
		posx = posy == 0 ? (getRandomBoolean() ? 1 : -1) : 0;
		posy = posx == 0 ? (getRandomBoolean() ? 1 : -1) : 0;
	}
	if ((enemy->x + posx) == player->x && (enemy->y + posy) == player->y){
		ft_printf("\n¡TE PILLÉ!\n");
		exit(0);
	}
	if (!iswall(fw,enemy,posx,posy)){
		handlemove(fw, enemy, posx, posy);
	}
	return(1);
}
bool iswall(in *fw, entity *enemy, int	posx, int	posy){
	if (fw->map->mapstruct[enemy->y + posy][enemy->x + posx] != 'C' && fw->map->mapstruct[enemy->y + posy][enemy->x + posx] != 'D' && fw->map->mapstruct[enemy->y + posy][enemy->x + posx] != 'S' && fw->map->mapstruct[enemy->y + posy][enemy->x + posx] != '1' && fw->map->mapstruct[enemy->y + posy][enemy->x + posx] != 'P'){
		return false;
	}
	return true;
}
int	getRandomBoolean(void) {
    return rand() % 2;
}
