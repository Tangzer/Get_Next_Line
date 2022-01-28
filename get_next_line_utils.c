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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*destination;

	if (dst == NULL && src == NULL)
		return (NULL);
	str = (unsigned char *)src;
	destination = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		destination[i] = str[i];
		i++;
	}
	return (destination);
}