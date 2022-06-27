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

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		msg_error();
		return (0);
	}
	else
	{
		while (i < argc)
		{
			if (read_file(argc, argv[i]) == 0)
			{
				msg_error();
				break ;
			}
			i++;
		}
	}
	return (0);
}
