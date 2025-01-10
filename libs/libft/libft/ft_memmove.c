/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:24:18 by mclaver-          #+#    #+#             */
/*   Updated: 2024/01/17 15:28:33 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (dst);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst > src)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	else if (dst < src)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
