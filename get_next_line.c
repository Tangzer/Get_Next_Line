#include "get_next_line.h"

static char	*update_static_buff(char *buff, int i)
{
	int j;
	int new_size;
	char *updated_buff;

	j = ft_strlen(buff);
	new_size = j - i;
	updated_buff = malloc(sizeof(char) * new_size);
	// + 1 le malloc??
	while (new_size >= i)
		updated_buff[new_size--] = buff[j--];
	free(buff);
	return (updated_buff);
}

static void ft_read(int fd, char *buff, int size)
{
	int i;

	i = 0;
	while (fd[i] != '\n')
		ft_stradd(fd[i], buff);
}

static int find_line_length(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	return (i);
}

static void *fct_line(int i, char *buff)
{
	int j;
	char *line;

	line = malloc(sizeof(char) * i + 1);
	j = 0;
	while (j <= i)
		line[j] = buff[j];
	update_static_buff(buff, i);
}

char *get_next_line(int fd)
{
	int i;
	static char *already_read_line;
	char *line;

	ft_read(fd, already_read_line, BUFFER_SIZE);
	i = find_line_length(already_read_line);
	line = fct_line(i, already_read_line);
	already_read_line = update_static_buff(already_read_line);
	return (line);
}