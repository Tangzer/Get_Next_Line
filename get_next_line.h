
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 40

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_error(char *tmp);
int 	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*gnl(int fd, char *buffer, char *buff);
char	*ft_strjoin(char *s1, char *s2);
char	*trim_buffer(char *buff);
int		check_for_line_break(char *buffer);
char	*ft_strjoin_modified(char *buffer, char *buff, int k);
char	*ft_strdup_line(char *src);
void	ft_bzero(void *str, int n);

#endif