/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:19:45 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/03 13:48:11 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(char const *input, ...);
int		ft_putchar(int a);
int		ft_format(va_list args, char const fmt);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_printpercent(void);
int		ft_phexmaj(unsigned int n);
int		ft_phexmin(unsigned int n);
int		ft_putptr(void *ptr);
char	*ft_itoa(int n);
int		ft_putuint(unsigned int n);

#endif
