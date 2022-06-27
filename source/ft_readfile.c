
#include "../header/armel.h"
#define BUFFER 10240

void	*ft_error(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}

char	*ft_readfile(char *file_name)
{
    int		fd;
    int		filelen;
    char	*content;

	content = (char *)malloc(sizeof(char) * BUFFER + 1);
	if (!content)
		return (ft_error());
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free(content);
		return (ft_error());
	}
	filelen = read(fd, content, BUFFER);
	content[filelen] = 0;
	return (content);
}

#include <stdio.h>
int	main()
{
	char *a = ft_readfile("bruh.txt");
	printf("%s\n",a);
}