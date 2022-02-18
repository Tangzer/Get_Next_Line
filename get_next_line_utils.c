#include "get_next_line.h"

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

char *ft_fill_line(char *src, char *dst, int n)
{
	int i;

	i = 0;
	while (src[n])
		dst[i++] = src[n++];
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	check_for_line_break(char *buffer)
{
	// renvoie la position a laquelle se trouve le '\n' - 1
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
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