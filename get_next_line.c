#include "get_next_line.h" 

char	*ft_fill(int fd, char *data)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);		// Allocate enough memory for all we want to read, plus the '/0'
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;			// Jumpstart the loop
	while (!ft_strcontains(data, '\n') && bytes_read != 0)		//strchr(buff, \n) && read more than one byte
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)		//Deal with error thrown by read
		{
			free(buffer);			//Free our buffer
			if (data != NULL)		//If data is not already NULL, free.
				free(data);
			return (NULL);
		}
			buffer[bytes_read] = '\0';	//Put the NULL at the end of our buffer
			data = ft_strjoin_special(data, buffer);		//strjoin our static var with buffer
	}
	free(buffer);		//Buffer done its job, free.
	return (data);
}

char		*ft_extract_line(char *data)
{
	char		*line;
	size_t		len;
	int			i;

	if (data[0] == '\0')	//If the first character of the static var is a '\0', the file is over, return NULL.
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')	// Copy until we reach either a '\0' or a '\n'
		i++;
	len = i;
	if(data[i] == '\n')	// As requested, if the line ends in a new line, we must include it.
		len++;
	line = malloc(len + 1);	// Normal malloc
	if (line == NULL)
		return (NULL);
	ft_strcpy_nl(line, data, 1); // Copy everything up until the newline
	return (line);
}

char	*ft_update_data(char *old_data)
{
	char		*new_data;
	int			start;

	start = 0;									//Simple way to check if everything was printed or not.
	while (old_data[start] != '\0' && old_data[start] != '\n')			//Updating data	
		start++;								//Old data is "Simple\nTest"	//Old data is "SimpleTest"
	if (old_data[start] == '\0')							//Line was Simple\n		//Line was SimpleTest
	{										//New data should be Test	//New data shoulde be NULL
		free(old_data);												//since everything was printed
		return (NULL);
	}
	new_data = malloc(sizeof(char) * (ft_strlen(old_data + start) + 1));	//Calculate the length of the string at the start point.
	if (new_data == NULL)
		return (NULL);
	ft_strcpy_nl(new_data, old_data + start + 1, 0);	//Copy the string into the new malloc from the position after '\n'
	free(old_data);						//free old buffer, since its being replaced.
	return (new_data);
}

char	*get_next_line(int fd)
{ 
		char		*line;
		static char	*data;

		if (fd < 0 || BUFFER_SIZE <= 0) // Deal with invalid fd and buffer sizes
				return (NULL);
		data = ft_fill(fd, data);		// Fill up our static var
		if (data == NULL)				// If static var return NULL, return NULL.
			return (NULL);
		line = ft_extract_line(data);	// Get the line that user wants returned
		data = ft_update_data(data);	// Update the Static var with rest of content
		return (line);
}
