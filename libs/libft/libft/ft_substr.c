/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:52:40 by mclaver-          #+#    #+#             */
/*   Updated: 2024/01/20 18:53:19 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;
	size_t	j;
	size_t	l;

	l = len;
	if (start + l > ft_strlen(s) && start < ft_strlen(s))
		l = ft_strlen(s) - start;
	if (l > ft_strlen(s))
		l = ft_strlen(s);
	ns = malloc(sizeof(char) * (l + 1));
	if (!ns)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < l)
			ns[j++] = s[i];
		i++;
	}
	ns[j] = '\0';
	return (ns);
}
