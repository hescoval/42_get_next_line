/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:52:39 by hescoval          #+#    #+#             */
/*   Updated: 2023/10/16 17:52:40 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_remainder(char *buff)
{
	int		start;
	int		ret_size;
	char	*ret;
	int		i;

	start = ft_strchr(buff, '\n');
	if (start == -1)
		return (buff);
	start ++;
	ret_size = ft_strlen(buff) - start;
	ret = malloc(ret_size + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (start <= ft_strlen(buff))
	{
		ret[i] = buff[start];
		i ++;
		start ++;
	}
	free(buff);
	return (ret);
}

char	*get_l(char *buff)
{
	int		nl_i;
	char	*ret;
	int		i;

	nl_i = ft_strchr(buff, '\n');
	if (nl_i == -1)
		return (NULL);
	ret = malloc(nl_i + 2);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i <= nl_i)
	{
		ret[i] = buff[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*read_to_buff(char*buff, int fd)
{
	char	*curr_read;
	int		bytes;

	curr_read = malloc(BUFFER_SIZE + 1);
	if (curr_read == NULL)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && ft_strchr(buff, '\n') == -1)
	{
		bytes = read(fd, curr_read, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(buff);
			free(curr_read);
			return (NULL);
		}
		curr_read[bytes] = '\0';
		buff = strjoin(buff, curr_read);
	}
	free(curr_read);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FILEMAX];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer[fd] = read_to_buff(buffer[fd], fd);
	if (buffer[fd] == NULL)
		return (NULL);
	if (!*buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	ret = get_l(buffer[fd]);
	if (ret == NULL)
	{
		ret = buffer[fd];
		buffer[fd] = NULL;
	}
	else
		buffer[fd] = get_remainder(buffer[fd]);
	return (ret);
}
/* 
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int fd;
	if((fd = open("test.txt", O_RDONLY)) == -1)
		return (-1);
	char *res;
	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
} */
