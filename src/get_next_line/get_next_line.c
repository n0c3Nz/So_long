#include "get_next_line.h"
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
	static char	*buffer;
	char		*line;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
		buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = fill_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer, find_nl(buffer));
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = realloc_buffer(buffer, ft_strlen(buffer), \
		ft_strlen(line));
	return (line);
}