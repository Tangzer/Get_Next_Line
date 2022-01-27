#include "get_next_line.h"

static char *ft_get_next_line(int fd, char *line, )
{

}

char	*get_next_line(int fd)
{
	char	*line;
	int		nbytes;

	line = NULL;
	nbytes = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (ft_error(0));
	return (ft_get_next_line(fd, buff, nbytes));
}