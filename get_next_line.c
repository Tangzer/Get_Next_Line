#include "get_next_line.h"

static char *next_line(char read_line, int i)
{
	int j;

	i++;
	j = 0;
	while (read_line[i] != '\n')
		j++;
	read_line = malloc(sizeof(char) * j + 1);
	if (!read_line)
		return (0);
	return (read_line);
}

static char *ft_get_next_line(int fd, char *line, char *read_line)
{
	int i;

	i = 0;
	while (read_line[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (0);
	i = 0;
	while (read_line[i] != '\n')
	{
		line[i] = read_line[i];
		i++;
	}
	read_line = next_line(read_line, i);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*read_line;

	line = NULL;
	read_line = read(fd, read_line, BUFFER_SIZE);
	if (!read_line)
		return (0);
	if (fd < 0 || fd > 1024 || !fd || BUFFER_SIZE <= 0)
		return (ft_error(0));
	return (ft_get_next_line(fd, line, read_line));
}