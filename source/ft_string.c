

#include "../header/armel.h"

int	ft_wordcount(char *str, char c)
{
	int	count;

	count = 0;
	while (str[0])
	{
		if (str[0] == c)
			count++;
		str++;
	}
	return (count);
}

int	ft_spec_strlen(char *str, char c)
{
	int	len;

	len = 0;
	while (str[0] != c && str[0] != 0)
		len++;
	return (len);
}