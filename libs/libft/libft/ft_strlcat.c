/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:24:17 by mclaver-          #+#    #+#             */
/*   Updated: 2024/01/20 18:49:48 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = d;
	if (dstsize == 0)
		return (s);
	while (*src != '\0' && i < dstsize - 1)
		*(dst + i++) = *src++;
	*(dst + i) = '\0';
	if (dstsize > d)
		return (d + s);
	else
		return (dstsize + s);
}
