#include "src.h"
int	str_handler(char *s, int fd)
{
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, fd);
	return (ft_strlen(s));
}