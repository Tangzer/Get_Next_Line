#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

char *trim_buffer(char *buffer)
{
	int 	i;
	int 	j;
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

char	*gnl(int fd, char *buffer, char *buff)
{
	char *str;

	str = NULL;
	while (check_for_line_break(buffer) == 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		read(fd, buff, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, buff);
		if (!buffer)
			return (ft_error(buffer));
	}
	str = ft_strdup_line(buffer);
	buffer = trim_buffer(buffer);
	printf("buffer after trim = %s\n", buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char 	*buffer;

	if (fd < 0 || fd > OPEN_MAX || !fd || BUFFER_SIZE <= 0)
		return (ft_error(0));
	printf("buffer -start- = %s\n", buffer);
	return (gnl(fd, buffer, buff));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	char *str;

	int fd = open("file", O_RDONLY);
	str = get_next_line(fd);
	printf("res1 = %s\n", str);

	printf("||||||||||||||||||||||||||||||||||||||||||||\n");

	str = get_next_line(fd);
	printf("res 2 = %s\n", str);

	return (0);
}