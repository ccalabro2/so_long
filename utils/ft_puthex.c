#include "utils.h"

int	ft_puthex(unsigned long n, char format)
{
	char	*base;
	int		i;

	i = 0;
	if (format == 'x')
	{
		base = "0123456789abcdef";
	}
	else
	{
		base = "0123456789ABCDEF";
	}
	if (n >= 16)
	{
		i += ft_puthex(n / 16, format);
	}
	i += ft_putchar(*(base + (n % 16)));
	return (i);
}
