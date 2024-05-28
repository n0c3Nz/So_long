#include "ft_printf.h"
int	get_size(va_list content, char type)
{
	if (type == 'c')
		return (char_handler(va_arg(content, int), 1));
	else if (type == 's')
		return (str_handler(va_arg(content, char *), 1));
	else if (type == 'p')
		return (addr_handler(va_arg(content, void *)));
	else if (type == 'd' || type == 'i')
		return (num_handler(va_arg(content, int), 1, "0123456789"));
	else if (type == 'u')
		return (uns_handler(va_arg(content, int), 1, "0123456789"));
	else if (type == 'x')
		return (uns_handler(va_arg(content, int), 1, "0123456789abcdef"));
	else if (type == 'X')
		return (uns_handler(va_arg(content, int), 1, "0123456789ABCDEF"));
	else if (type == '%')
		return (char_handler('%', 1));
	return (0);
}
int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		n;
	int		size;
	va_start (ap, fmt);
	n = 0;
	size = 0;
	while (fmt[n])
	{
		if (fmt[n] == '%')
		{
			n++;
			size += get_size(ap, fmt[n]);
		}
		else
			size += write(1, &fmt[n], 1);
		n++;
	}
	va_end (ap);
	return (size);
}