/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaestri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:27:42 by cmaestri          #+#    #+#             */
/*   Updated: 2024/02/15 14:26:25 by cmaestri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putstr("4294967276");
	}
	else if (n > 9)
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
