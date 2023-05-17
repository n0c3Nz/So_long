#include "so_long.h"
int check_file_extension(char *filename, char *extension)
{
	size_t len_filename;
    size_t len_extension;
    len_filename = ft_strlen(filename);
    len_extension = ft_strlen(extension);

	if (len_filename < len_extension)
	{
		perror("Fichero no válido");
		exit(1);
	}
	char *ptr = filename + (len_filename - len_extension);
	if (ft_strncmp(ptr, extension, len_extension) == 0)
	{
		return(0);
	}
	else
	{
		perror("Este fichero no tiene la extensión requerida");
		exit(1);
	}
}
int line_counter(int fd)
{
    char buffer[BUFFER_SIZE];
	int	line;
    ssize_t bytes_read;
	int i;
	
	i = 0;
	line = 0;
    while ((bytes_read = read(fd, &buffer[i], 1)) > 0)
    {
        if (buffer[i] == '\n')
            line++;
		i++;
    }
    if (bytes_read == -1)
    {
        perror("Error al leer el archivo");
        exit(1);
    }
	if (line < 2)
	{
		perror("Número de líneas insuficientes");
		exit(1);
	}
    return(line);
}
int map_validator(char *buffer, map *c)
{
	static int i;

	if (i == 0 && i < c->lines)
	{
		first_line_analyzer(buffer, c);
		i++;
	}
	else if (i > 0 && (i + 1) < c->lines)
	{
		body_line_analyzer(buffer, c);
		i++;
	}
	else if ((i + 1) == c->lines)
		last_line_analyzer(buffer, c);
	else
	{
		perror("Error, tremenda fumada");
		exit(1);
	}
	return(0);
}

int process_line(int fd, map *c)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
	int i;

	i = 0;
    while ((bytes_read = read(fd, &buffer[i], 1)) > 0)
    {
        if (buffer[i] == '\n')
            check_line(buffer, &i, c);
        else
            i++;
    }
    if (bytes_read == -1)
    {
        perror("Error al leer el archivo");
        exit(1);
    }
    return(0);
}

int process_map_file(int argc, char **argv, map *c)
{
	check_argc(argc);
	check_file_extension(argv[1], ".ber");
	int fd = open(c->map_name, O_RDONLY);
	c->lines = line_counter(fd);
	close(fd);
	int fd2 = open(c->map_name, O_RDONLY);
	c->coins = 0;
	c->startp = 0;
	c->zeros = 0;
	c->ones = 0;
	c->exitp = 0;
	process_line(fd2, c);
	if (c->coins < 1 || c->exitp != 1 || c->startp != 1)
	{
		perror("Mapa no válido, faltan C ó sobran P ó E");
		exit(1);
	}
	ft_printf("\nColumnas:\t\t%d\nFilas:\t\t\t%d\nCoins:\t\t\t%d\nUnos:\t\t\t%d\nCeros:\t\t\t%d\nPunto de entrada:\t%d\nPunto de salida:\t%d\n", c->columns, c->lines, c->coins, c->ones, c->zeros, c->startp, c->exitp);// DEBUG
	path_finder(c);
	close(fd2);
	return (0);
}