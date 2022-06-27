/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duvibuls <duvibuls@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:16:08 by duvibuls          #+#    #+#             */
/*   Updated: 2022/06/28 02:16:13 by duvibuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/armel.h"
#include <stdio.h>

void	reverse(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_row)
	{
		j = 0;
		while (j < map->map_column)
		{
			if (i == map->map_row - 1 && map->arr[i][j] == 0)
				map->arr[i][j] = 1;
			if (j == map->map_column - 1 && map->arr[i][j] == 0)
				map->arr[i][j] = 1;
			if (map->arr[i][j] == map->obstacle_pos[i][j])
				map->arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	min3(int a, int b, int c)
{
	int min;
	
	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}

void	back_traverse(t_map *map)
{
	int	i;
	int	j;

	i = map->map_row - 1;
	while (i >= 0)
	{
		j = map->map_column - 1;
		while (j >= 0)
		{
			if (i <= map->map_row - 2 && j <= map->map_column - 2 && !map->obstacle_pos[i][j])
				map->arr[i][j] = 1 + min3(map->arr[i][j + 1], map->arr[i - 1][j - 1], map->arr[i - 1][j]);
			j--;
		}
		i--;
	}
}

int	solve(t_map *map)
{
	reverse(map);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
		{
			printf("%d", map->arr[i][j]);
		}
		printf("\n");
	}

	return (1);
}


int main() {
	t_map *map;
	map = malloc(sizeof(map));
	map->arr = (int **)malloc(5 * sizeof(int *));
	for (int i=0; i<5; i++)
		map->arr[i] = (int *)malloc(5 * sizeof(int));
	map->obstacle_pos = (int **)malloc(5 * sizeof(int *));
	for (int i=0; i<5; i++)
		map->obstacle_pos[i] = (int *)malloc(5 * sizeof(int));

	map->arr[0][0] = 0;
	map->arr[0][1] = 1; map->obstacle_pos[0][1] = 1;
	map->arr[0][2] = 0;
	map->arr[0][3] = 0;
	map->arr[0][4] = 0;
	map->arr[1][0] = 0;
	map->arr[1][1] = 0;
	map->arr[1][2] = 0;
	map->arr[1][3] = 0;
	map->arr[1][4] = 0;
	map->arr[2][0] = 1; map->obstacle_pos[2][0] = 1;
	map->arr[2][1] = 0;
	map->arr[2][2] = 0;
	map->arr[2][3] = 0;
	map->arr[2][4] = 0;
	map->arr[3][0] = 0;
	map->arr[3][1] = 0;
	map->arr[3][2] = 0;
	map->arr[3][3] = 0;
	map->arr[3][4] = 1; map->obstacle_pos[3][4] = 1;
	map->arr[4][0] = 0;
	map->arr[4][1] = 0;
	map->arr[4][2] = 1; map->obstacle_pos[4][2] = 1;
	map->arr[4][3] = 0;
	map->arr[4][4] = 0;

	map->map_row = 5;
	map->map_column = 5;


	solve(map);
}

/*

{{0, 1, 0, 0, 0},
{0, 0, 0 ,0 ,0},
{1, 0, 0, 0, 0},
{0, 0, 0, 0, 1},
{0, 0, 1, 0, 0}}

*/