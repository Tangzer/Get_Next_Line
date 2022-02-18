
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 12

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_error(char *tmp);
int 	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*gnl(int fd, char *saved, char *buffer, char *buff);
char 	*gnl_big_buff_size(int fd, char *saved, char *buffer, char *buff);
char	*ft_fill_line(char *src, char *dst, int n);
char	*ft_strjoin(char *s1, char *s2);
char 	*update_buffer(char *buffer, char *buff, int k);
char	*trim_buffer(char *buff, int i);
int		check_for_line_break(char *buffer);
char	*ft_strjoin_modified(char *buffer, char *buff, int k);

#endif