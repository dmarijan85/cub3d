/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <mclaver-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:49:21 by mclaver-          #+#    #+#             */
/*   Updated: 2024/07/02 14:34:21 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readf(int fd, char **stat)
{
	char	*temp;
	int		byte_read;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (ft_free(&*stat));
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(temp, '\n'))
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp);
			return (ft_free(&*stat));
		}
		temp[byte_read] = '\0';
		*stat = ft_strjoin(*stat, temp);
	}
	free(temp);
	return (*stat);
}

char	*ft_line(char **buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[0][i] && buffer[0][i] != '\n')
		i++;
	if (buffer[0][i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (ft_free(&*buffer));
	i = 0;
	while (buffer[0][i] && buffer[0][i] != '\n')
	{
		line[i] = buffer[0][i];
		i++;
	}
	if (buffer[0][i] == '\n')
	{
		line[i] = buffer[0][i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next(char **buffer, int start, int buflen)
{
	int		i;
	int		j;
	char	*rest;

	rest = ft_calloc(buflen - start + 1, sizeof(char));
	if (!rest)
		return (ft_free(&*buffer));
	i = 0;
	j = 0;
	while (buffer[0][i])
	{
		if (i >= start)
		{
			rest[j] = buffer[0][i];
			j++;
		}
		i++;
	}
	rest[j] = '\0';
	ft_free(&*buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = ft_readf(fd, &buffer[fd]);
	if (buffer[fd] == NULL)
		return (ft_free(&buffer[fd]));
	line = ft_line(&buffer[fd]);
	if (buffer[fd])
		buffer[fd] = ft_next(&buffer[fd], \
				ft_strlen(line), ft_strlen(buffer[fd]));
	return (line);
}
