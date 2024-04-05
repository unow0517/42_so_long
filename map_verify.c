/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:21 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/05 22:47:12 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static int	mid_wall_check(char *str, int len)
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

int	northest_wall_check(char *str, int len)
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

static int	end_wall_check(char *str, int len)
{
	int	hasnl;
	int	i;
	int	isonlywall;

	hasnl = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == '\n')
			hasnl = 1;
	}
	if (hasnl == 1)
		return (0);
	i = 0;
	while (hasnl == 0 && str[i] != '\0')
	{
		if (str[i] != '1')
			isonlywall = 0;
		i++;
	}
	if (i != len || isonlywall == 0)
		return (-1);
	return (0);
}

static int	map_verify(char *str, int len)
{
	if (end_wall_check(str, len) == -1)
		ft_error("Error\nSouthest tile shoulde be always wall!");
	if (str && mid_wall_check(str, len) == -1)
		ft_error("Error\nOutest border shoulde be always wall!");
	return (0);
}

char	*map_verify_and_gnl(int src, int len)
{
	char	*gnl;

	gnl = get_next_line(src);
	map_verify(gnl, len);
	return (gnl);
}
