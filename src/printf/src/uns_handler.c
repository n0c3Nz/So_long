#include "src.h"
int	uns_handler(unsigned int n, int fd, char *base)
{
	return (ft_putunbr_fd_base(n, fd, base) + 1);
}