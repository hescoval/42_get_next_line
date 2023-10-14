#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef BUFSIZE
# define BUFSIZE 1
# endif

int		ft_strlen(char *str);
char	*strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
#endif
