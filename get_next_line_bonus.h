#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_error(char *tmp);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*get_nl(int fd, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*trim_buffer(char *buff);
int		check_for_line_break(char *buffer);
char	*ft_strdup_line(char *src);

#endif