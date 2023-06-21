#include "so_long.h"

int get_pixel_color(void *img_ptr, int x, int y)
{
    int bpp;
    int size_line;
    int endian;
    char *img_data;

    img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    int color = *(int *)(img_data + y * size_line + x * (bpp / 8)); // color del pixel en (x,y)
    return color;
}

void draw_image(in *fw, void *img_ptr, int start_x, int start_y)
{
    int x;
	int y;
    int color;
	int width;
	int height;
	int exclude_color;
	width = BPP;
	height = BPP;
	exclude_color = get_pixel_color(img_ptr, 0, 0);
	//ft_printf("\nValor del pixel = %i\n", exclude_color); 		DEBUG
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            color = get_pixel_color(img_ptr, x, y);
            if (color != exclude_color) // si el color no es el color excluido
            {
                mlx_pixel_put(fw->map->mlx, fw->map->mlx_win, start_x + x, start_y + y, color);
            }
            x++;
        }
        y++;
    }
}

char* put_values(char *cadena, entity *entity) {
    char *copia = ft_strdup(cadena);  // Crear una copia de la cadena original

    //printf("\nDEBUG do_moves:45  CARACTER DE CADENA:       %c       CADENA:        %s\n", copia[8], copia);
    copia[8] = get_low(entity->value);
    //printf("\nDEBUG do_moves:47  VALOR DE ENTITY         %c       VALOR EN MINUSCULA       %c\n", entity->value, get_low(entity->value));
    //printf("\nHOLA\n");
    //printf("\nDEBUG do_moves:49  CADENA 2:    %s\n", copia);  // DEBUG

    return copia;
}

char get_low(char letter)
{
    if (letter >= 'A' && letter <= 'Z') {
        return letter + 32;
    } else {
        // Si la letra no es mayúscula, se devuelve tal cual
        return letter;
    }
}
char *getdirectionimage1(entity *entity, int coordx, int coordy){
	char *imgstep1;
	imgstep1 = put_values("sprites/p_down_step_t.xpm", entity);//default
	//ft_printf("\nDEBUG do_moves:63	CADENA DE TEXTO:	%s\n", put_values("sprites/p_down_step_t.xpm", entity));//			DEBUG
	if (coordx == -1) //a
		imgstep1 = put_values("sprites/p_left_step_t.xpm", entity);
	else if (coordy == 1) //s
		imgstep1 = put_values("sprites/p_down_step_t.xpm", entity);
	else if (coordx == 1) //d
		imgstep1 = put_values("sprites/p_right_step_t.xpm", entity);
	else if (coordy == -1) //w
		imgstep1 = put_values("sprites/p_up_step_t.xpm", entity);
	return imgstep1;
}
char *getdirectionimage2(entity *entity, int coordx, int coordy){
	char *imgstep2;
	imgstep2 = put_values("sprites/p_down_step_2_t.xpm", entity);//default
	if (coordx == -1) //a
		imgstep2 = put_values("sprites/p_left_step_2_t.xpm", entity);
	else if (coordy == 1) //s
		imgstep2 = put_values("sprites/p_down_step_2_t.xpm", entity);
	else if (coordx == 1) //d
		imgstep2 = put_values("sprites/p_right_step_2_t.xpm", entity);
	else if (coordy == -1) //w
		imgstep2 = put_values("sprites/p_up_step_2_t.xpm", entity);
	return imgstep2;
}
char *getdirectionstatic(entity *entity, int coordx, int coordy){
	char *imgstep2;
	imgstep2 = put_values("sprites/p_down_t.xpm", entity);//default
	if (coordx == -1) //a
		imgstep2 = put_values("sprites/p_left_t.xpm", entity);
	else if (coordy == 1) //s
		imgstep2 = put_values("sprites/p_down_t.xpm", entity);
	else if (coordx == 1) //d
		imgstep2 = put_values("sprites/p_right_t.xpm", entity);
	else if (coordy == -1) //w
		imgstep2 = put_values("sprites/p_up_t.xpm", entity);
	return imgstep2;
}
float getsumax(int coordx, float lx){
	float sumax = 0;
	if (coordx == -1) //a
		sumax -= lx;
	else if (coordx == 1) //d
		sumax = lx;
	return sumax;
}
float getsumay(int coordy, float lx){
	float sumay = 0;
	if (coordy == 1) //s
		sumay = lx;
	else if (coordy == -1) //w
		sumay -= lx;
	return sumay;
}
int drawcharacter(in *fw, entity *entity, int coordx, int coordy) {
	entity->stepanimation++;
	if (entity->stepanimation == 2)
	{
		entity->ptr = mlx_xpm_file_to_image(fw->map->mlx, getdirectionimage2(entity, coordx, coordy), &fw->map->width, &fw->map->height);
		//mlx_do_sync(fw->map->mlx);
	}
	else if (entity->stepanimation == 4)
	{
		entity->ptr = mlx_xpm_file_to_image(fw->map->mlx, getdirectionimage1(entity, coordx, coordy), &fw->map->width, &fw->map->height);
		//mlx_do_sync(fw->map->mlx);
		entity->stepanimation = 0;
	}
	return (entity->stepanimation);
}
void initplayer(in *fw, entity *entity, int coordx, int coordy) {
	//ft_printf("\nDEBUG 1: %c\n", fw->map->mapstruct[entity->y][entity->x]);
	fw->map->mapstruct[entity->y][entity->x] = '0';
	entity->xT = entity->x;
	entity->yT = entity->y;
	if (fw->map->mapstruct[entity->y + coordy][entity->x + coordx] != 'E')
		fw->map->mapstruct[entity->y + coordy][entity->x + coordx] = entity->value;
	//ft_printf("\nDEBUG 2: %c\n", entity->value);
}
void *bucle_asincrono(void* arg) {
	tempcajon* temporal = (tempcajon*)arg;
	in *fw = temporal->tempfw;
	entity *entity = temporal->tempentity;
	int coordx = temporal->coordx;
	int coordy = temporal->coordy;
	free(temporal);
	float lx = 0;
	while (lx < 1) {
		lx += 0.1;
		entity->xT = (entity->x + getsumax(coordx, lx));
		entity->yT = (entity->y + getsumax(coordy, lx));
		put_imgs(fw);
		entity->stepanimation = drawcharacter(fw, entity, coordx, coordy);
		if (entity->value == 'P')
			usleep(20000);
		else if (entity->value == 'D')
			usleep(24000);
		else if (entity->value == 'S')
			usleep(40000);
	}
	entity->x += coordx;
	entity->y += coordy;
	mlx_put_image_to_window(fw->map->mlx, fw->map->mlx_win, fw->map->floor_ptr, entity->x * BPP, entity->y * BPP);//Pone un suelo en la nueva coordenada
	entity->ptr = mlx_xpm_file_to_image(fw->map->mlx, getdirectionstatic(entity, coordx, coordy), &fw->map->width, &fw->map->height);//CARGA LA DIRECCION ESTATICA DEL JUGADOR.
	draw_image(fw, entity->ptr, entity->x * BPP, entity->y * BPP);//Dibuja el paso estatico
	mlx_do_sync(fw->map->mlx);
	entity->iswalking = false;
	check_e(fw);
	pthread_exit(NULL);
	return NULL;
}

void handlemove(in *fw, entity *entity, int coordx, int coordy)
{
	if (entity->iswalking || (coordx == 0 && coordy == 0 && entity->iswalking)){
		return;
	}
	entity->iswalking = true;
	initplayer(fw, entity, coordx, coordy);
	entity->stepanimation = 0;

	tempcajon* temporal = (tempcajon*)malloc(sizeof(tempcajon));
	temporal->tempfw = fw;
    temporal->tempentity = entity;
    temporal->coordx = coordx;
    temporal->coordy = coordy;
	pthread_t hilo;

    pthread_create(&hilo, NULL, bucle_asincrono, (void*)temporal);
 	pthread_detach(hilo);
	//printf("Hola desde el hilo principal\n");
	//moveEnemyTowardsPlayer(fw, fw->snorlax, fw->player);
}


/*ESTO ES EL TIMER DE LA ANIMACION*/

int timer(clock_t inicio, double tiempo_deseado)
{
	clock_t actual = clock();
	double tiempo_transcurrido = (double)(actual - inicio) / CLOCKS_PER_SEC;
	double tiempo_restante = tiempo_deseado - tiempo_transcurrido;
	// Esperar el tiempo restante para alcanzar el tiempo deseado
	double tiempo_espera = tiempo_restante * CLOCKS_PER_SEC;
	clock_t espera_final = actual + (clock_t)tiempo_espera;
	while (clock() < espera_final)// Esperar...
	inicio = clock();
	return(inicio);
}

/*TIMER PARA DETERMINAR EL INTERVALO DE LOS MOVIMIENTOS DEL JUGADOR*/
int hasEnoughTimeElapsed(void)
{
    clock_t currentTime = clock();
    double elapsed = (double)(currentTime - lastKeyPressTime) / CLOCKS_PER_SEC;

    if (elapsed >= 0.0001)
    {
        lastKeyPressTime = currentTime;
        return 1; // Ha pasado suficiente tiempo
    }
    return 0; // No ha pasado suficiente tiempo
}