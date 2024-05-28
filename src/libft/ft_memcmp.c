#include "libft.h"
int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
		i++;
	}
	return (0);
}