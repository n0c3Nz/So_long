#ifndef SRC_H
# define SRC_H
# include "../libft/libft.h"
int	char_handler(char c, int fd);
int	str_handler(char *s, int fd);
int	num_handler(int n, int fd, char *base);
int	uns_handler(unsigned int n, int fd, char *base);
int	addr_handler(void *ptr);
#endif