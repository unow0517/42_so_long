/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/21 12:04:16 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// int	end_wall_check(char *str, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (*str != '\n')
// 	{
// 		if (*str != 1)
// 			return (-1);
// 		str++;
// 		i++;
// 	}
// 	if (i != len)
// 		return (-1);
// 	return (0);
// }

// int	mid_wall_check(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i] != 1)
// 		return (-1);
// 	while (str[i] != '\n')
// 	{
// 		i++;
// 		if (str[i] == '\n' && str[i - 1] != 1)
// 			return (-1);
// 	}
// 	return (0);
// }

// int	map_verify(char *str)
// {
// 	int		width;
// 	char	*gnl;
// 	char	*lastgnl;

// 	if (!str)
// 		return (-1);
// 	width = ft_strlen(gnl);
// 	if (end_wall_check(gnl, width) == -1)
// 		return (-1);
// 	while (gnl)
// 	{
// 		lastgnl = gnl;
// 		gnl = get_next_line(src);
// 		if (!gnl)
// 			if (wall_check(lastgnl) == -1)
// 				return (-1);
// 		if (mid_wall_check(gnl) == -1)
// 			return (-1);
// 	}
// 	return (0);
// }
