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
	map->map_row = 0;
	map->map_column = 0;
	map->arr = NULL;
	map->obstacle_pos = NULL;
	map->ans_pos = NULL;
	map->obstacle = '\0';
	map->free = '\0';
	map->square = '\0';
}

void	setup_char(t_map *map, char obstacle, char free, char square)
{
	map->obstacle = obstacle;
	map->free = free;
	map->square = square;
}

void	setup_map(t_map *map, int map_row, int map_column, int **arr)
{
    int	i;
	int	j;

	i = 0;
	j = 0;
	map->arr = (int **)malloc(map_row * sizeof(int *));
	for (int i=0; i<5; i++)
		map->arr[i] = (int *)malloc(map_column * sizeof(int));
	map->map_row = map_row;
    map->map_column = map_column;
	while (i < map_row)
	{
		while (j < map_column)
		{
			map->arr[i][j] = arr[i][j];
			j++;
		}
		i++;
	}
}