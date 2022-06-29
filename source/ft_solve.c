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

int	solve(t_map *map)
{
	reverse(map);
	back_traverse(map);
	find_max(map);
	find_ans_pos(map);
	swarm_row(map);
	swarm_col(map);
	adjust(map);
	printf("x = %d, y = %d\n", map->ans_pos_start[0], map->ans_pos_start[1]);
	printf("x = %d, y = %d\n", map->ans_pos_end[0], map->ans_pos_end[1]);
	ft_arr_print(map);
	return (0);
}


int	main() {
	t_map	*map;

	map = malloc(sizeof(map));
	map->arr = (int **)malloc(6 * sizeof(int *));
	for (int i=0; i<6; i++)
		map->arr[i] = (int *)malloc(6 * sizeof(int));
	map->obs_pos = (int **)malloc(6 * sizeof(int *));
	for (int i=0; i<6; i++)
		map->obs_pos[i] = (int *)malloc(6 * sizeof(int));
	map->ans_pos_start = (int *)malloc(2 * sizeof(int));
	map->ans_pos_end = (int *)malloc(2 * sizeof(int));

	map->arr[0][0] = 0; map->obs_pos[0][0] = 0;
	map->arr[0][1]= 0; map->obs_pos[0][1]= 0;
	map->arr[0][2]= 0; map->obs_pos[0][2]= 0;
	map->arr[0][3]= 0; map->obs_pos[0][3]= 0;
	map->arr[0][4]= 0; map->obs_pos[0][4]= 0;
	map->arr[1][0]= 0; map->obs_pos[1][0]= 0;
	map->arr[1][1]= 1; map->obs_pos[1][1]= 1;
	map->arr[1][2]= 0; map->obs_pos[1][2]= 0;
	map->arr[1][3] = 0; map->obs_pos[1][3] = 0;
	map->arr[1][4] = 0; map->obs_pos[1][4] = 0;
	map->arr[2][0] = 0; map->obs_pos[2][0] = 0;
	map->arr[2][1] = 0; map->obs_pos[2][1] = 0;
	map->arr[2][2] = 0; map->obs_pos[2][2] = 0;
	map->arr[2][3] = 0; map->obs_pos[2][3] = 0;
	map->arr[2][4] = 0; map->obs_pos[2][4] = 0;
	map->arr[3][0] = 0; map->obs_pos[3][0] = 0;
	map->arr[3][1] = 0; map->obs_pos[3][1] = 0;
	map->arr[3][2] = 0; map->obs_pos[3][2] = 0;
	map->arr[3][3] = 0; map->obs_pos[3][3] = 0;
	map->arr[3][4] = 0; map->obs_pos[3][4] = 0;
	map->arr[4][0] = 0; map->obs_pos[4][0] = 0;
	map->arr[4][1] = 0; map->obs_pos[4][1] = 0;
	map->arr[4][2] = 0; map->obs_pos[4][2] = 0;
	map->arr[4][3] = 0; map->obs_pos[4][3] = 0;
	map->arr[4][4] = 0; map->obs_pos[4][4] = 0;
	map->arr[5][0] = 0; map->obs_pos[5][0] = 0;
	map->arr[5][1] = 0; map->obs_pos[5][1] = 0;
	map->arr[5][2] = 0; map->obs_pos[5][2] = 0;
	map->arr[5][3] = 0; map->obs_pos[5][3] = 0;
	map->arr[5][4] = 0; map->obs_pos[5][4] = 0;
	map->arr[5][5] = 0; map->obs_pos[5][5] = 0;

	map->row = 5;
	map->col = 5;
	// map->free = '.';
	// map->obs = 'o';
	// map->square = '#';

	solve(map);

	if (map->ans_pos_start[0] == 0 && map->ans_pos_start[1] == 0)
		if (map->ans_pos_end[0] == 0 && map->ans_pos_end[1] == 0)
			printf("No Solution\n");
}

/*

{{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0}}

*/