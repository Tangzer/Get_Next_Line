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

void ft_stradd(int fd, char *buff)
{

}