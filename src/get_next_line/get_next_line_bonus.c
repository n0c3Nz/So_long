/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:21:50 by guortun-          #+#    #+#             */
/*   Updated: 2023/03/29 17:22:34 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	find_nl(char *ptr)
{
	ssize_t	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_getline(char *buffer, ssize_t size)
{
	char	*line;

	if (ft_strlen(buffer) == 0)
		return (NULL);
	line = (char *)ft_calloc(size + 2, sizeof(char));
	if (!line)
		return (NULL);
	line[size + 1] = '\0';
	line = ft_memcpy(line, buffer, size + 1);
	return (line);
}

char	*fill_buffer(int fd, char *buffer)
{
	ssize_t		nr;
	ssize_t		nl;
	char		*ptr;

	ptr = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	nr = 1;
	nl = 1;
	while (nr != 0 && nl == nr)
	{
		nr = read(fd, ptr, BUFFER_SIZE);
		if (nr == -1)
		{
			free(ptr);
			free(buffer);
			return (NULL);
		}
		ptr[nr] = '\0';
		nl = find_nl(ptr);
		buffer = ft_strjoin(buffer, ptr);
	}
	free (ptr);
	ptr = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1000000];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = fill_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_getline(buffer[fd], find_nl(buffer[fd]));
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = realloc_buffer(buffer[fd], ft_strlen(buffer[fd]), \
		ft_strlen(line));
	return (line);
}
