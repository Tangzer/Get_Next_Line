/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:22:09 by tverdood          #+#    #+#             */
/*   Updated: 2022/02/24 12:23:55 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*trim_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	j = ft_strlen(buffer) - i;
	if (j <= 0)
	{
		free(buffer);
		return  NULL;
	}
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
		ft_bzero(buff, BUFFER_SIZE + 1);
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (ft_error(buff));
		if (i == 0)
		{
			ft_error(buff);
			return (buffer);
		}
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
	char *line;
	static char *buffer;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (ft_error(0));
	buffer = get_nl(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_strdup_line(buffer);
	buffer = trim_buffer(buffer);
//	printf("--buffer after trim = %s\n", buffer);
	if (line && !*line)
	{
		free(line);
		return NULL;
	}
	return (line);
}
/*
#include <stdio.h>

int main()
{
	char *str;

	int fd = open("file", O_RDONLY);
	while ((str = get_next_line(0)) != NULL)
	{
		if (!*str)
			printf("haha\n");
		printf("res = %s", str);
		free(str);
	}
	str = get_next_line(fd);
	return (0);
}*/