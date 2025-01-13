/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functionsuint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:26:26 by mclaver-          #+#    #+#             */
/*   Updated: 2024/02/13 15:00:56 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_nlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putuint(unsigned int n)
{
	int		rv;
	char	*num;

	rv = 0;
	if (n == 0)
		rv = write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		if (!num)
			return (-1);
		rv = ft_putstr(num);
		free(num);
	}
	return (rv);
}
