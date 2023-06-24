


int funcion(in *fw){
	int unidad, centena, decena;
	unidad = 96;
	decena = 64;
	centena = 32;    
	if (fw->map->moves < 10) {
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + centena), (fw->map->lines - 0.92) * BPP);
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + decena), (fw->map->lines - 0.92) * BPP);
		put_number(fw, fw->map->moves, unidad)
	}
	if (fw->map->moves < 100){
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + centena), (fw->map->lines - 0.92) * BPP);
		put_number(fw, (fw->map->moves / 10) % 10, decena)
		put_number(fw, fw->map->moves % 10, unidad)
	else{
		put_number((fw, fw->map->moves / 10) % 10, centena)
		put_number(fw, fw->map->moves % 10, decena)
		put_number(fw, fw->map->moves / 100, unidad)
	}
}

void put_number(in *fw, int number, int x, int position){
	if (number == 0)
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
    else if (number == 1)
		draw_image(fw, fw->count->one_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
    else if (number == 2)
		draw_image(fw, fw->count->two_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
    else if (number == 3)
		draw_image(fw, fw->count->three_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
    else if (number == 4)
		draw_image(fw, fw->count->four_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
    else if (number == 5)
		draw_image(fw, fw->count->five_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
    else if (number == 6)
		draw_image(fw, fw->count->six_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
    else if (number == 7)
		draw_image(fw, fw->count->seven_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
	else if (number == 8)
		draw_image(fw, fw->count->eight_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
	else if (number == 9)
		draw_image(fw, fw->count->nine_ptr, (fw->map->columns * BPP / 2 + position), (fw->map->lines - 0.92) * BPP);
}