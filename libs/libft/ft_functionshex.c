/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functionshex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:30:51 by mclaver-          #+#    #+#             */
/*   Updated: 2024/02/13 15:06:54 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phexmaj(unsigned int n)
{
	int	rv;

	rv = 0;
	if ((n / 16) > 0)
	{
		rv += ft_phexmaj(n / 16);
		if (rv == -1)
			return (-1);
	}
	if ((n % 16) > 9 && (n % 16) < 16)
	{
		rv += ft_putchar('A' + ((n % 16) - 10));
		if (rv == -1)
			return (-1);
	}
	else
	{
		rv += ft_putchar('0' + (n % 16));
		if (rv == -1)
			return (-1);
	}
	return (rv);
}

int	ft_phexmin(unsigned int n)
{
	int	rv;

	rv = 0;
	if ((n / 16) > 0)
	{
		rv += ft_phexmin(n / 16);
		if (rv == -1)
			return (-1);
	}
	if ((n % 16) > 9 && (n % 16) < 16)
	{
		rv += ft_putchar('a' + ((n % 16) - 10));
		if (rv == -1)
			return (-1);
	}
	else
	{
		rv += ft_putchar('0' + (n % 16));
		if (rv == -1)
			return (-1);
	}
	return (rv);
}
