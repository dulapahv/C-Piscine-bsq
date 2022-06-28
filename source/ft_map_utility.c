/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duvibuls <duvibuls@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:32:34 by duvibuls          #+#    #+#             */
/*   Updated: 2022/06/28 02:32:35 by duvibuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/armel.h"

void	create_map(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->arr = NULL;
	map->obs_pos = NULL;
	map->ans_pos = NULL;
	map->obs = '\0';
	map->free = '\0';
	map->square = '\0';
}

void	setup_char(t_map *map, char obs, char free, char square)
{
	map->obs = obs;
	map->free = free;
	map->square = square;
}

void	setup_map(t_map *map, int row, int column, int **arr)
{
    int	i;
	int	j;

	i = 0;
	j = 0;
	map->arr = (int **)malloc(row * sizeof(int *));
	for (int i=0; i<5; i++)
		map->arr[i] = (int *)malloc(column * sizeof(int));
	map->row = row;
    map->col = column;
	while (i < row)
	{
		while (j < column)
		{
			map->arr[i][j] = arr[i][j];
			j++;
		}
		i++;
	}
}