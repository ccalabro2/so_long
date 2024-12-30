/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:48:19 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 16:48:20 by ccalabro         ###   ########.fr       */
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
