#include "get_next_line.h"
#include <stdio.h>

void update_statik(char *statik, int k)
{
	int 	i;
	int 	n;
	char	*tmp;

	n = ft_strlen(statik);
	tmp = malloc(sizeof(char) * n);
	if (!tmp)
		free(tmp);
	ft_fill_line(statik, tmp, n);
	i = 0;
	while (k < n)
		statik[i++] = tmp[k++];
	free(tmp);
}

char *send_line(char *statik, int k)
{
	char	*line;
	int 	i;

	i = 0;
	line = malloc(sizeof(char) * k + 1);
	if (!line)
		return (ft_error(line));
	ft_fill_line(statik, line, k);
	return (line);
}

int	ft_find_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			printf(" i = %d\n", i);
			return (i);
		}
		i++;
	}
	printf(" i = %d\n", i);
	return (0);
}

int gnl(int fd, char *statik, char *buffer)
{
	int r;
	int k;

	k = 0;
	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		if (ft_find_line(ft_strjoin(statik, buffer)))
		{
			k = ft_find_line(ft_strjoin(statik, buffer));
			printf(" k = %d\n", k);
			return (k);
		}
		r = read(fd, buffer, BUFFER_SIZE);
	}
	printf(" k = %d\n", k);
	return (k);
}

char *get_next_line(int fd)
{
	static char statik[10000];
	char 		buffer[BUFFER_SIZE + 1];
	char 		*line;
	int			k;

	if (fd < 0 || fd > 1024 || !fd || BUFFER_SIZE <= 0)
		return (ft_error(0));
	k = gnl(fd, statik, buffer);
	printf(" last k = %d\n", k);
	//Fct qui extrait la ligne de la statik
	line = send_line(statik, k);
	//Fct qui trimn la statik
	update_statik(statik, k);
	return (line);
}
////////////////////////////////////////////////////////////////////////////
int main()
{
	char *str;

	int fd = open("file", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);

	str = get_next_line(fd);
	printf("%s", str);

	return (0);
}