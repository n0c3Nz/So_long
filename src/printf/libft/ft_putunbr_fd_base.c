#include "libft.h"
int	ft_putunbr_fd_base(unsigned int n, int fd, char *base)
{
	size_t		m;
	size_t		base_size;
	static int	i;
	m = (size_t)n;
	base_size = 0;
	base_size = ft_strlen(base);
	i = 0;
	if (m >= base_size)
		ft_putunbr_fd_base(m / base_size, fd, base);
	m %= base_size;
	write (fd, &base[m], 1);
	return (i++);
}