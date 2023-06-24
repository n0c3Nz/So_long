


int funcion(in *fw){
        
	if (fw->map->moves < 10) {
		(pongo un cero)
		(pongo otro cero)
		put_number(fw, fw->map->moves)
	}
	if (fw->map->moves < 100){
		(pongo un cero)
		put_number((fw, fw->map->moves / 10) % 10)
		put_number(fw, fw->map->moves % 10)
	else{
		put_number((fw, fw->map->moves / 10) % 10)
		put_number(fw, fw->map->moves % 10)
		put_number(fw, fw->map->moves / 100)
	}
}

void put_number(in *fw, int number, int x){
	if (number == 0)
		draw_image(fw, fw->count->zero_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
    else if (number == 1)
		draw_image(fw, fw->count->one_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
    else if (number == 2)
		draw_image(fw, fw->count->two_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
    else if (number == 3)
		draw_image(fw, fw->count->three_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
    else if (number == 4)
		draw_image(fw, fw->count->four_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
    else if (number == 5)
		draw_image(fw, fw->count->five_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
    else if (number == 6)
		draw_image(fw, fw->count->six_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
    else if (number == 7)
		draw_image(fw, fw->count->seven_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
	else if (number == 8)
		draw_image(fw, fw->count->eight_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
	else if (number == 9)
		draw_image(fw, fw->count->nine_ptr, (fw->map->columns * BPP / 2 + 96), (fw->map->lines - 0.92) * BPP);
}