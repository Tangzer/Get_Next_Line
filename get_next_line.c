#include "get_next_line.h"
#include <stdio.h>

char *update_buffer(char *buffer, char *buff, int k)
{
	//ajoute le bon nombre de bytes du buff au buffer
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(buffer) + BUFFER_SIZE - k) + 1);
	if (!str)
		return (NULL);
	while (i < k)
	{
		str[i] = buff[i];
		i++;
	}
	//free(buffer);	--> leaks?
	return (str);
}

char *trim_buffer(char *buff, int n)
{
	//efface la partie 'saved' pour garder le reste
	int 	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(buff) - (n + 1)));
	if (!str)
		return (NULL);
	while (buff[n])
	{
		str[i++] = buff[n++];
	}
	//free(buffer);	--> leaks?
	return (str);
}

char	*gnl(int fd, char *saved, char *buffer, char *buff)
{
	int r;
	int k;

	r = read(fd, buff, BUFFER_SIZE);
//	printf("r = %d\n", r);
	while (r == BUFFER_SIZE)
	{
		k = check_for_line_break(buff);
//		printf("k = %d\n", k);
		if (k == 0)
			buffer = update_buffer(buffer, buff, BUFFER_SIZE);
		else if (k > 0)
		{
			saved = ft_strjoin_modified(buffer, buff, k);
			buffer = trim_buffer(buff, (k + 1));
			printf("saved final = %s\n", saved);
			printf("buffer after trim = %s\n", buffer);
			return (saved);
		}
		r = read(fd, buff, BUFFER_SIZE);
	}
	return (saved);
}

char 	*gnl_big_buff_size(int fd, char *saved, char *buffer, char *buff)
{
	int i;

	read(fd, buff, BUFFER_SIZE);
	i = check_for_line_break(buff);
	printf("%d\n", i);
	buffer = update_buffer(buffer, buff, i);
	buff = trim_buffer(buff, i);
	saved = buffer;
	return (saved);
}

char	*get_next_line(int fd)
{
	char 			*saved;
	char			buff[BUFFER_SIZE + 1];
	static char 	*buffer;

	if (fd < 0 || fd > 1024 || !fd || BUFFER_SIZE <= 0)
		return (ft_error(0));
	saved = NULL;
	if (BUFFER_SIZE > read(fd, buff, BUFFER_SIZE))
		return (gnl_big_buff_size(fd, saved, buffer, buff));
	else
		return (gnl(fd, saved, buffer, buff));
}

// Ou bien je garde les 2 gnl et qd BS est petit (certaines valeurs --> seg fault)
// Ou bien je garde que 1 gnl et ca bug de maniere random
// what about freeing some shit??
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	char *str;

	int fd = open("file", O_RDONLY);
	str = get_next_line(fd);
	printf("%s\n", str);

	free(str);

//	str = get_next_line(fd);
//	printf("%s\n", str);
//	printf("yoloooo");

	return (0);
}