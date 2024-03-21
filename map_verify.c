/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/21 13:33:19 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	mid_wall_check(char *str, int len)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		return (-1);
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
		if ((str[i] == '\n' || str[i] == '\0') && str[i - 1] != '1')
		{
			i--;
			return (-1);
		}
	}
	if (i != len)
		return (-1);
	return (0);
}

int	end_wall_check(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	if (i != len)
		return (-1);
	return (0);
}

int	map_verify(char *str, char *laststr, int len)
{
	if (!str && end_wall_check(laststr, len) == -1)
		return (-1);
	if (str && mid_wall_check(str, len) == -1)
		return (-1);
	return (0);
}

char	*map_verify_and_gnl(int src, char *str, int len)
{
	char	*lastgnl;
	char	*gnl;

	lastgnl = str;
	gnl = get_next_line(src);
	if (map_verify(gnl, lastgnl, len) == -1)
		return (0);
	return (gnl);
}