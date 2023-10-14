#include "get_next_line.h"

char    *get_remainder(char *buff)
{
	int start;
	int ret_size;
	char *ret;
	int i;

	start = ft_strchr(buff, '\n');
	if(start == -1)
		return buff;
	start += 1;
	ret_size = ft_strlen(buff) - start;
	ret = malloc(ret_size + 1); 	
	if(ret == NULL)
		return(NULL);
	i = 0;
	while(start <= ft_strlen(buff))
	{
		ret[i] = buff[start];
		i ++;
		start ++;
	}
	free(buff);
	return(ret);
}

char    *get_line(char *buff)
{
	int nl_i;
	char *ret;
	int i;

	nl_i = ft_strchr(buff, '\n');
	if (nl_i == -1)
		return NULL;
	ret = malloc(nl_i + 2);
	if(ret == NULL)
		return(NULL);
	i = 0;
	while(i <= nl_i)
	{
		ret[i] = buff[i];
		i++;
	}
	ret[i] = '\0';
	return(ret);
}

char *read_to_buff(char*buff, int fd)
{
	char *curr_read;
	int bytes;

	curr_read = malloc(BUFSIZE + 1);
	if(curr_read == NULL)
		return(NULL);
	bytes = 1;
	while(bytes > 0 && ft_strchr(buff, '\n') == -1)
	{
		bytes = read(fd, curr_read, BUFSIZE);
		if(bytes == 0) // End of File reached
			break;
		if(bytes == -1) // Read threw an erroru6o
		{
			free(curr_read);
			return (NULL);
		}
		curr_read[bytes] = '\0';
		buff = strjoin(buff, curr_read);
	}
	free(curr_read);
	return(buff);
}

char *get_next_line(int fd)
{
	static char *buffer; //static that will hold my buffers indefinitely
	char *ret;
	if(fd < 0 || BUFSIZE < 0)
		return(NULL);
	buffer = read_to_buff(buffer, fd); // Returns buffer with atleast one /n or EOF
	if(buffer == NULL)
		return(NULL);
	ret = get_line(buffer);
	buffer = get_remainder(buffer);
	return(ret);
}

/*  int main(int argc, char **argv)
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