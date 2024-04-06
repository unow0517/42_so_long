/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:17:13 by yowoo             #+#    #+#             */
/*   Updated: 2024/04/06 12:23:17 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_nlidx(const char *s)
{
	int	i;
	int	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		if (*(s + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*to_nl_plus_one(char *ptr)
{
	int		len;
	int		nl_idx;
	char	*temp;

	if (!ptr)
		return (0);
	len = ft_strlen(ptr);
	if (!len)
		return (free(ptr), NULL);
	nl_idx = ft_nlidx(ptr);
	if (nl_idx < 0 || len == (nl_idx + 1))
		return (free(ptr), NULL);
	len -= (nl_idx + 1);
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (0);
	ft_memcpy(temp, ptr + nl_idx + 1, len);
	temp[len] = '\0';
	free(ptr);
	ptr = temp;
	return (ptr);
}

char	*first_piece(char *ptr)
{
	char	*output;
	int		len;

	if (!ptr || *ptr == 0)
		return (0);
	else if (!ft_strchr(ptr, '\n'))
	{
		output = ft_strdup(ptr);
		return (output);
	}
	len = ft_strchr(ptr, '\n') - ptr;
	output = malloc((len + 1 + 1) * sizeof(char));
	if (!output)
		return (0);
	ft_memcpy(output, ptr, len + 1);
	output[len + 1] = '\0';
	return (output);
}

char	*till_buf_having_firstnl_or_end(char *stat, int fd)
{
	char	ptr[BUFFER_SIZE + 1];
	int		rd;
	char	*temp;

	rd = 1;
	if (ft_strchr(stat, '\n'))
		return (stat);
	while (rd > 0 && !ft_strchr(stat, '\n'))
	{
		rd = read(fd, ptr, BUFFER_SIZE);
		if (rd < 0)
		{
			free(stat);
			return (0);
		}
		ptr[rd] = '\0';
		temp = ft_strjoin(stat, ptr);
		free(stat);
		stat = temp;
	}
	return (stat);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!stat)
	{
		stat = malloc(sizeof(char));
		if (!stat)
			return (0);
		*stat = '\0';
	}
	if (!ft_strchr(stat, '\n'))
		stat = till_buf_having_firstnl_or_end(stat, fd);
	output = first_piece(stat);
	stat = to_nl_plus_one(stat);
	return (output);
}

// int	main(void)
// {
// 	int	src;
// 	int	i;

// 	i = 0;
// 	src = open("thisistest.txt", O_RDONLY);
// 	// printf("src:%d", src);
// 	// // get_next_line(src);
// 	while (i++ < 10)
// 		printf("result: %s", get_next_line(src));
// 	// get_next_line(src);
// 	// printf("output: %s", get_next_line(src));
// 	// const char *ptr = "Hello";
// 	// ft_substr(ptr,0,3);
// 	return (0);
// }

// ft_substr in first_piece does not return new pointer address, 
// so malloc + ft_memcpy is used instead.
// key point in this Fn = moving memory location with new ptr
// whenever an action on string is commited.