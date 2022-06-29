/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duvibuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:30:23 by duvibuls          #+#    #+#             */
/*   Updated: 2022/06/28 01:28:51 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/armel.h"

int	msg_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_if_fail(t_map *pmap,char *content)
{
	if (!content)
		write(1, "Error\n", 6);
	if (ft_check_file(content) || !pmap)
	{
		write(1, "Error\n", 6);
		free(content);
	}
	return (!content || ft_check_file(content) || !pmap);
}

void	ft_run_program(int argc, char **argv)
{
	int		i;
	char	*content;
	t_map	*map;

	i = 1;
	while (i < argc)
	{
		content = ft_readfile(argv[i]);
		map = ft_create_map(content);
		if (!ft_if_fail(map, content))
		{
			ft_free_complete_map(&map);
		}
		i++;
		free(content);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (msg_error());
	ft_run_program(argc, &argv[1]);
	return (0);
}
