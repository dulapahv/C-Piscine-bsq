/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_obs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:08:37 by tponutha          #+#    #+#             */
/*   Updated: 2022/06/29 12:08:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/armel.h"

int	ft_free_obs(int ***obs_pos)
{
    int i;

    i = 0;
    while (obs_pos[0][i])
    {
        free(obs_pos[0][i]);
        i++;
    }
    free(obs_pos);
	return (1);
}

int ft_count_obs(t_map *pmap, char **box)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (i < pmap->row)
    {
        j = 0;
        while (j < pmap->col)
        {
            if (box[i][j] == pmap->obs)
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int ft_allocate_obs(t_map *pmap, char **box)
{
    int i;
    int size;

    size = ft_count_obs(pmap, box);
    pmap->obs_pos = malloc(sizeof(int *) * (size + 1));
    if (!pmap->obs_pos)
        return (1);
    i = 0;
    pmap->obs_pos[size] = NULL;
    while (i < size)
    {
        pmap->obs_pos[i] = (int *)malloc(sizeof(int) * 2);
        if (!pmap->obs_pos[i])
			return (ft_free_obs(&pmap->obs_pos));
        i++;
    }
	return (0);
}

void	ft_norm_obs(t_map *pmap, char **box)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i < pmap->row)
	{
		j = 0;
		while (j < pmap->col)
		{
			if (box[i][j] == pmap->obs)
			{
				pmap->obs_pos[n][0] = i;
				pmap->obs_pos[n][1] = j;
				n++;
			}
			j++;
		}
		i++;
	}
}

int	ft_locate_obs(t_map *pmap, char **box)
{
	if (ft_allocate_obs(pmap, box))
		return (1);
	ft_norm_obs(pmap, box);
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char *read = ft_readfile("../map1");
	char **b = ft_split(read, '\n');
	t_map map;
	map.row = 10;
	map.col = 10;
	map.obs = 'o';
	ft_locate_obs(&map, &b[1]);
	int i = 0;
	printf("-------------------------------\n");
	while (map.obs_pos[i])
	{
		printf("[%d,%d]\n",map.obs_pos[i][0],map.obs_pos[i][1]);
		i++;
	}
}
*/