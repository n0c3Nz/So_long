#include <stdio.h>
#include <stdlib.h>
char* agregarCeros(in *fw) {
    char* resultado[4];
	if (fw->map->moves < 0 || fw->map->moves > 999) {
        printf("El número está fuera del rango válido (0-999).\n");
        resultado[0] = '\0';  // Establecer el resultado como una cadena vacía
        exit();//ESTO PODRIA FALLAR CUIDADITO.
    }
    if (fw->map->moves < 10) {
		draw_image(fw, fw->map->zero_ptr, 80, (fw->map->lines - 1) * BPP);
		draw_image(fw, fw->map->coin_ptr, 100, (fw->map->lines - 1) * BPP);
        if (fw->map->moves == 0)
			draw_image(fw, fw->map->zero_ptr, 120, (fw->map->lines - 1) * BPP);
        else if (fw->map->moves == 1)
			draw_image(fw, fw->map->one_ptr, 120, (fw->map->lines - 1) * BPP);
        else if (fw->map->moves == 2)
			draw_image(fw, fw->map->two_ptr, 120, (fw->map->lines - 1) * BPP);
        else if (fw->map->moves == 3)
			draw_image(fw, fw->map->three_ptr, 120, (fw->map->lines - 1) * BPP);
        else if (fw->map->moves == 4)
			draw_image(fw, fw->map->four_ptr, 120, (fw->map->lines - 1) * BPP);
        else if (fw->map->moves == 5)
			draw_image(fw, fw->map->five_ptr, 120, (fw->map->lines - 1) * BPP);
        else if (fw->map->moves == 6)
			draw_image(fw, fw->map->six_ptr, 120, (fw->map->lines - 1) * BPP);
        else if (fw->map->moves == 7)
			draw_image(fw, fw->map->seven_ptr, 120, (fw->map->lines - 1) * BPP);
		else if (fw->map->moves == 8)
			draw_image(fw, fw->map->eight_ptr, 120, (fw->map->lines - 1) * BPP);
		else if (fw->map->moves == 9)
			draw_image(fw, fw->map->nine_ptr, 120, (fw->map->lines - 1) * BPP);
    } else if (fw->map->moves < 100) {
        sprintf(resultado, "0%d", fw->map->moves);
    } else {
        sprintf(resultado, "%d", fw->map->moves);
    }
    return resultado;
}
int main() {
    int fw->map->moves;
    char resultado[4];
    char* valor = agregarCeros(fw->map->moves, resultado);
    if (valor[0] != '\0') {
        printf("Resultado: %s\n", valor);
    }
    return 0;
}