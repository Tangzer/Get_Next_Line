#include "get_next_line.h"

static char *update_line(char *read_line, int i)
{
	int j;

	j = 0;
	while (read_line[i] != '\n')
		j++;
	read_line = malloc(sizeof(char) * j + 1);
	if (!read_line)
		return (ft_error(read_line));
	return (read_line);
}

static char *ft_get_next_line(char *line, char *read_line)
{
	int i;

	i = 0;
	while (read_line[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (ft_error(read_line));
	ft_memcpy(line, read_line, i);
//	i = 0;
//	while (read_line[i] != '\n')
//	{
//		line[i] = read_line[i];
//		i++;
//	}
	i++;
	read_line = update_line(read_line, i);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*read_line;
	int				nb_bytes;

	line = NULL;
	nb_bytes = read(fd, read_line, BUFFER_SIZE);
	if (!read_line)
		return (ft_error(0));
	if (fd < 0 || fd > 1024 || !fd || BUFFER_SIZE <= 0)
		return (ft_error(read_line));
	return (ft_get_next_line(line, read_line));
}

int 	main(void)
{
	
}