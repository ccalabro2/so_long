#include "utils.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		count++;
	}
	return (count);
}
