/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:15:10 by mclaver-          #+#    #+#             */
/*   Updated: 2024/02/13 15:03:05 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a)
{
	return (write(1, &a, 1));
}

int	ft_format(va_list args, char const fmt)
{
	int	reva;

	reva = 0;
	if (fmt == 'c')
		reva = ft_putchar(va_arg(args, int));
	else if (fmt == 's')
		reva = ft_putstr(va_arg(args, char *));
	else if (fmt == 'p')
		reva = ft_putptr(va_arg(args, void *));
	else if (fmt == 'd' || fmt == 'i')
		reva = ft_putnbr(va_arg(args, int));
	else if (fmt == 'u')
		reva = ft_putuint(va_arg(args, unsigned int));
	else if (fmt == 'x')
		reva = ft_phexmin(va_arg(args, unsigned int));
	else if (fmt == 'X')
		reva = ft_phexmaj(va_arg(args, unsigned int));
	else if (fmt == '%')
		reva = ft_printpercent();
	return (reva);
}

int	ft_process_format(const char *input, va_list args, int *i, int *retval)
{
	int	temp;

	temp = ft_format(args, input[*i + 1]);
	if (temp == -1)
		return (-1);
	*retval += temp;
	(*i)++;
	return (0);
}

int	ft_printf(char const *input, ...)
{
	int		retval;
	int		i;
	va_list	args;

	retval = 0;
	i = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			if (ft_process_format(input, args, &i, &retval) == -1)
				return (va_end(args), -1);
		}
		else
		{
			if (ft_putchar(input[i]) == -1)
				return (va_end(args), -1);
			retval++;
		}
		i++;
	}
	return (va_end(args), retval);
}
