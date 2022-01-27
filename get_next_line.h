
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char 	*ft_error(char *tmp);
int 	ft_strlen(char *str);

#endif