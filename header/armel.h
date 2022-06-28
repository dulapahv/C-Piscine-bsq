/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duvibuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:31:36 by duvibuls          #+#    #+#             */
/*   Updated: 2022/06/27 20:31:38 by duvibuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARMEL_H
# define ARMEL_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		map_row;
	int		map_column;
	int		**arr;
	int		**obstacle_pos;
	int		**ans_pos;
	char	obstacle;
	char	free;
	char	square;
}	t_map;

/*** ft_readfile.c ***/
char	*ft_readfile(char *file_name);

/*** ft_spilt.c ***/
char	**ft_split(char *str, char spliter);

/*** utility.c ***/
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);

/*** ft_string.c ***/
int	ft_ptr_strlen(char **str, char c);
int	ft_nptr_strlen(char *str, char c);
int	ft_wordcount(char *str, char c);
int	ft_is_not_printable(char *str, char not);
int	ft_is_same(char *str);

#endif