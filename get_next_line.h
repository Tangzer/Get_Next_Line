
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_error(char *tmp);
int 	ft_strlen(char *str);
char	*get_next_line(int fd);
int		gnl(int fd, char *statik, char *buffer);
void	ft_fill_line(char *src, char *dst, int n);
char	*ft_strjoin(char *s1, char *s2);
void update_statik(char *statik, int k);
char *send_line(char *statik, int k);

#endif