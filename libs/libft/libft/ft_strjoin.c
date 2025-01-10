/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:04:58 by mclaver-          #+#    #+#             */
/*   Updated: 2024/01/20 18:53:29 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		i;
	int		j;

	ns = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !ns)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ns[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ns[i] = s2[j];
		i++;
		j++;
	}
	ns[i] = '\0';
	return (ns);
}
