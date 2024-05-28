#include "src.h"
int	addr_handler(void *ptr)
{
	write(1, "0x", 2);
	return (ft_putaddr_fd((unsigned long int)ptr, 1) + 3);
}