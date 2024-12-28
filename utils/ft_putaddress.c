/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaestri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:27:09 by cmaestri          #+#    #+#             */
/*   Updated: 2024/02/15 14:28:14 by cmaestri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
