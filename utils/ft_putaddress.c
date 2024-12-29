#include "utils.h"

int	ft_putaddress(void *p)
{
	int	i;

	i = 0;
	if (p == NULL)
	{
		return (ft_putstr("0x0"));
	}
	i += ft_putstr("0x");
	i += ft_puthex((unsigned long) p, 'x');
	return (i);
}
