/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:11:35 by mclaver-          #+#    #+#             */
/*   Updated: 2024/02/13 14:58:49 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	str_size(int n)
{
	size_t	size;

	if (n > 0)
		size = 0;
	else
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	nbr = n;
	if (n < 0)
		nbr = -nbr;
	size = str_size(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}
