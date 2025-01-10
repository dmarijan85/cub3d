/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:51:40 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/02 14:35:32 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char **buffer)
{
	if (*buffer && buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}
