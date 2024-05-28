#include "libft.h"
int	ft_putaddr_fd(unsigned long int n, int fd)
{
	static int	i;
	char		*base;
	base = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		ft_putaddr_fd(n / 16, fd);
	n %= 16;
	write (fd, &base[n], 1);
	return (i++);
}