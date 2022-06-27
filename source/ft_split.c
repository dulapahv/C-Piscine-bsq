

#include "../header/armel.h"

char	**ft_allocate(char **bigbox, char *str, char c)
{
	int	size;
	int	sptcount;

	sptcount = ft_wordcount(str, c);
	bigbox = malloc(sizeof(char *) * (sptcount + 1));
	while (str[0])
	{
		str++;
	}
}

char	**ft_split(char *str, char spliter)
{
	int		size;
	int		i;
	int		sptcount;
	char	**bigbox;

	

}