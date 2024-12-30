/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalabro <ccalabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:47:58 by ccalabro          #+#    #+#             */
/*   Updated: 2024/12/30 16:47:59 by ccalabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_endcmp(char *s1, char *end)
{
	int	s1_len;
	int	end_len;

	s1_len = ft_strlen(s1);
	end_len = ft_strlen(end);
	if (s1_len <= end_len)
		return (1);
	s1 += s1_len - end_len;
	while (*s1)
	{
		if (*s1 != *end)
			return (1);
		s1++;
		end++;
	}
	return (0);
}
