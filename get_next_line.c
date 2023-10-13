#define BUFSIZE 42

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
	if(!str)
		return 0;
	int i = 0;
	while(str[i])
		i++;
	return i;
}
int ft_strchr(char *s, int c)
{
	int i = 0;
	if(!s)
		return (-1);
	while(s[i])
	{
		if(s[i] == c)
			return i;
		i++;
	}
	return (-1);
}
char *strjoin(char *s1, char *s2)
{
	char *line;
	line = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(line == NULL)
		return (NULL);
	int i = 0;
	int j = 0;

	if(s1)
	{
		while (s1[i])
		{
			line[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		line[i] = s2[j];
		i++;
		j++;
	}
	line[i] = '\0';

	return (line);
}

// UTILITIES UP
// GET_NEXT_LINE RELATED DOWN
char    *get_remainder(char *buff)
{
	int nl_i = ft_strchr(buff, '\n');
		if(nl_i == -1)
			return NULL;
	int ret_size = ft_strlen(buff) - nl_i;
	char *ret = malloc(ret_size + 1);
	int i = 0;
	while(nl_i < ret_size)
	{
		ret[i] = buff[nl_i];
		i ++;
		nl_i ++;
	}
	ret[i] = '\0';
	return(ret);
}
char    *get_line(char *buff)
{
	int nl_i = ft_strchr(buff, '\n');
		if(nl_i == -1)
			return NULL;
	char *ret = malloc(nl_i + 1);
	int i;
	i = 0;
	while(i < nl_i)
	{
		ret[i] = buff[i];
		i++;
	}
	ret[i] = '\0';
	return(ret);
}
char *read_to_buff(char *buff, int fd)
{
	char *curr_read = malloc(BUFSIZE + 1);
	if(curr_read == NULL)
		return(NULL);
	int bytes;

	bytes = 1;
	while(bytes > 0 && ft_strchr(buff, '\n') == -1)
	{
		bytes = read(fd, curr_read, BUFSIZE);
		if(bytes == 0) // End of File reached
			break;
		if(bytes == -1) // Read threw an error
		{
			free(curr_read);
			return (NULL);
		}
		curr_read[BUFSIZE] = '\0';
		buff = strjoin(buff, curr_read);
	}
	free(curr_read);
	return(buff);
}

char *get_next_line(int fd)
{
	static char *buffer; //static that will hold my buffers indefinitely
	char *ret;
	buffer = read_to_buff(buffer, fd); // Returns buffer with atleast one /n or EOF
	ret = get_line(buffer);
	buffer = get_remainder(buffer);
	return(ret);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int fd;
	if((fd = open("test.txt", O_RDONLY)) == -1)
		return (-1);

	char *res;
	res = get_next_line(fd);
	printf("%s", res);
}