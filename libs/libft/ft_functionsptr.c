/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functionsptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:17:14 by mclaver-          #+#    #+#             */
/*   Updated: 2024/02/13 12:46:59 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long value)
{
	int	i;

	i = 0;
	while (value)
	{
		value = value / 16;
		i++;
	}
	return (i);
}

static void	ft_hexptrfill(unsigned long long value, char *hexptr)
{
	static const char	*hexsys;
	int					len;

	hexsys = "0123456789abcdef";
	len = ft_ptrlen (value) + 2;
	hexptr[len] = '\0';
	len--;
	while (len)
	{
		hexptr[len] = hexsys[value % 16];
		len--;
		value /= 16;
	}
	hexptr[0] = '0';
	hexptr[1] = 'x';
}

int	ft_putptr(void *ptr)
{
	unsigned long long	value;
	char				*hexptr;
	int					rv;

	if (!ptr)
		return (ft_putstr("0x0"));
	value = (unsigned long long)ptr;
	hexptr = malloc(sizeof(void) * ft_ptrlen(value) + 3);
	if (!hexptr)
		return (-1);
	ft_hexptrfill(value, hexptr);
	rv = ft_putstr(hexptr);
	free (hexptr);
	return (rv);
}
