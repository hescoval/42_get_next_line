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

int		ft_strlen(char *str);
char	*strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
#endif
