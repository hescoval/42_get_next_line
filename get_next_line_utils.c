#include "get_next_line.h"

size_t	ft_strlen(char *s)		//Straightforward strlen
{ 
	size_t	i;

	if (s == NULL)		//Make sure we check if its NULL before playing with it (Invalid read size 1)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
 } 

int	ft_strcontains(char *s, char c)		//Straightforward strchr
{
		unsigned int	i;

		if (s == NULL)
			return (0);
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (1);
			i++;
		}
		return (0);
}

char	*ft_strcpy_nl(char *dest, char *src, int nl_stop) 
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (nl_stop && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
		dest[i] = '\0';
		return (dest);
}

char	*ft_strjoin_special(char *s1, char *s2)	//	Straightforward strjoin, check for s1 == NULL and s2 == NULL in loops
{
	char	*join;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);		//	Calculate length of return string
	join = malloc(sizeof(char) * (len + 1));	//	Malloc with +1 for Null
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		join[i++] = s2[j++];
	join[len] = '\0';
	if (s1 != NULL)	// s1 is our buffer, its about to be replaced. free it
		free(s1);
	return (join);
}