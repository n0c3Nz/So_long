#include "libft.h"
void
	ft_putendl_fd(char *s, int fd)
{
	const char	nl = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &nl, 1);
}