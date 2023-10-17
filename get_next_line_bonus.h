/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:53:03 by hescoval          #+#    #+#             */
/*   Updated: 2023/10/16 17:53:03 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FILEMAX
#  define FILEMAX 1024
# endif

size_t	ft_strlen(char *s);
int		ft_strcontains(char *s, char c);
char	*ft_strcpy_nl(char *dest, char *src, int nl_stop);
char	*ft_strjoin_special(char *s1, char *s2);
char	*get_next_line(int fd);
#endif
