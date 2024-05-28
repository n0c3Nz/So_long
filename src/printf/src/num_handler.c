#include "src.h"
int	num_handler(int n, int fd, char *base)
{
	ft_putnbr_fd_base(n, fd, base);
	return (ft_numlen(n, base));
}