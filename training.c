# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int 	check_for_break(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] && buffer)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char *gnl(int fd, char	*buffer)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!check_for_break(buffer) && i != 0)
	{

	}
}

char	*get_next_line(int fd)
{
	char *line;
	char *buffer;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gnl(fd, buffer);
//	line = get_line(buffer);
//	if (line && !*line)
//	{
//		free(line);
//		return (NULL);
//	}
//	buffer = trim_buffer(buffer);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *line;
	int fd;

	fd = open("file", O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);

	free(line);
	return (0);
}