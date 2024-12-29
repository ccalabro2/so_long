#include "utils.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_array(char *c, unsigned int number, long int len)
{
	while (number > 0)
	{
		c[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char			*c;
	unsigned int	len;
	long int		number;

	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (c == NULL)
		return (NULL);
	c[len--] = '\0';
	if (n == 0)
	{
		c[0] = '0';
	}
	if (n < 0)
	{
		number = n * -1;
		c[0] = '-';
	}
	else
		number = n;
	c = ft_array(c, number, len);
	return (c);
}
