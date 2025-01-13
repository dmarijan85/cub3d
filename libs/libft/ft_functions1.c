/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:29:27 by mclaver-          #+#    #+#             */
/*   Updated: 2024/02/13 14:59:50 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (ft_putchar(s[i]) == -1)
				return (-1);
			i++;
		}
	}
	else
	{
		return (ft_putstr("(null)"));
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	return (write(1, "%", 1));
}
