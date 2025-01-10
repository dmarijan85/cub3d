/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:05:22 by mclaver-          #+#    #+#             */
/*   Updated: 2024/01/20 18:53:06 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		j;
	int		i;
	char	*dup;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (j < i)
	{
		dup[j] = s1[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
