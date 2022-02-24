#include "get_next_line.h"

char	*trim_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	j = ft_strlen(buffer) - i;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	i += 1;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_nl(int fd, char *buffer)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (check_for_line_break(buffer) == -1 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			ft_error(buff);
		buff[i] = '\0';
		buffer = ft_strjoin(buffer, buff);
		if (!buffer)
			return (ft_error(buffer));
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer[OPEN_MAX - 1];

	if (fd < 0 || fd > OPEN_MAX || !fd || BUFFER_SIZE <= 0)
		return (ft_error(0));
	buffer = get_nl(fd, buffer[fd]);
	if (!buffer)
		return (NULL);
	line = ft_strdup_line(buffer);
	buffer = trim_buffer(buffer);
	return (line);
}