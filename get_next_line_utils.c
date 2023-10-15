#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if(!str)
		return 0;
	while(str[i])
		i++;
	return i;
}
int ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	if(s == NULL)
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
	int i;
	int j;

	i = 0;
	j = 0;
	line = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (line == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			line[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		line[i++] = s2[j++];
	line[i] = '\0';
	free(s1);
	return (line);
}
