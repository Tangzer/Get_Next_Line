#include "get_next_line.h"
#include <stdio.h>

char *ft_error(char *tmp)
{
	if (tmp)
		free(tmp);
	return (NULL);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	check_for_line_break(char *buffer)
{
	int i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_modified(char *buffer, char *buff, int k)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(buffer) + k));
	if (!str)
		return (NULL);
	while (buffer[j])
		str[i++] = buffer[j++];
	j = 0;
	while (j < k)
		str[i++] = buff[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_line(char *src, int x)
{
	char	*duplicate;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	x = 0;
	while (src[i] && src[i] != '\n')
	{
		i++;
	}
	if (src[i] == '\n')
		i++;
	duplicate = malloc(sizeof(char) * i + 1);
	if (!duplicate)
		return (NULL);
	while (j < i)
	{
		duplicate[j] = src[j];
		j++;
	}
	duplicate[j] = '\0';
	return (duplicate);
}

void	ft_bzero(void *str, int n)
{
	int 			i;
	unsigned char	*p;

	p = (unsigned char *)str;
	if (n == 0)
		return ;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}