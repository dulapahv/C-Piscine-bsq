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
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (i == map->row - 1 && map->arr[i][j] == 0)
				map->arr[i][j] = 1;
			if (j == map->col - 1 && map->arr[i][j] == 0)
				map->arr[i][j] = 1;
			if (map->arr[i][j] == map->obs_pos[i][j])
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

	i = map->row - 1;
	while (i >= 0)
	{
		j = map->col - 1;
		while (j >= 0)
		{
			if (!map->obs_pos[i][j])
				if (i <= map->row - 2 && j <= map->col - 2)
					map->arr[i][j] = 1 + min3(map->arr[i][j + 1], map->arr[i + 1][j + 1], map->arr[i + 1][j]);
			j--;
		}
		i--;
	}
}

void	find_max(t_map *map)
{
	int	i;
	int	j;

	map->max = map->arr[0][0];
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->arr[i][j] > map->max)
				map->max = map->arr[i][j];
			j++;
		}
		i++;
	}
}

void	find_ans_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->arr[i][j] == map->max)
			{
				map->ans_pos[0] = i;
				map->ans_pos[1] = j;
			}
			j++;
		}
		i++;
	}
}

// void	swarm(t_map *map)
// {
	
// }


int	solve(t_map *map)
{
	reverse(map);
	back_traverse(map);
	find_max(map);
	find_ans_pos(map);
	//swarm(map);
	printf("x = %d, y = %d\n", map->ans_pos[0], map->ans_pos[1]);
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
	map->obs_pos = (int **)malloc(5 * sizeof(int *));
	for (int i=0; i<5; i++)
		map->obs_pos[i] = (int *)malloc(5 * sizeof(int));
	map->ans_pos = (int *)malloc(2 * sizeof(int));

	map->arr[0][0] = 0; map->obs_pos[0][0] = 0;
	map->arr[0][1] = 1; map->obs_pos[0][1] = 1;
	map->arr[0][2] = 0; map->obs_pos[0][2] = 0;
	map->arr[0][3] = 0; map->obs_pos[0][3] = 0;
	map->arr[0][4] = 0; map->obs_pos[0][4] = 0;
	map->arr[1][0] = 0; map->obs_pos[1][0] = 0;
	map->arr[1][1] = 0; map->obs_pos[1][1] = 0;
	map->arr[1][2] = 0; map->obs_pos[1][2] = 0;
	map->arr[1][3] = 0; map->obs_pos[1][3] = 0;
	map->arr[1][4] = 0; map->obs_pos[1][4] = 0;
	map->arr[2][0] = 1; map->obs_pos[2][0] = 1;
	map->arr[2][1] = 0; map->obs_pos[2][1] = 0;
	map->arr[2][2] = 0; map->obs_pos[2][2] = 0;
	map->arr[2][3] = 0; map->obs_pos[2][3] = 0;
	map->arr[2][4] = 0; map->obs_pos[2][4] = 0;
	map->arr[3][0] = 0; map->obs_pos[3][0] = 0;
	map->arr[3][1] = 0; map->obs_pos[3][1] = 0;
	map->arr[3][2] = 0; map->obs_pos[3][2] = 0;
	map->arr[3][3] = 0; map->obs_pos[3][3] = 0;
	map->arr[3][4] = 1; map->obs_pos[3][4] = 1;
	map->arr[4][0] = 0; map->obs_pos[4][0] = 0;
	map->arr[4][1] = 0; map->obs_pos[4][1] = 0;
	map->arr[4][2] = 1; map->obs_pos[4][2] = 1;
	map->arr[4][3] = 0; map->obs_pos[4][3] = 0;
	map->arr[4][4] = 0; map->obs_pos[4][4] = 0;

	map->row = 5;
	map->col = 5;

	solve(map);
}

/*

{{0, 1, 0, 0, 0},
{0, 0, 0 ,0 ,0},
{1, 0, 0, 0, 0},
{0, 0, 0, 0, 1},
{0, 0, 1, 0, 0}}

*/