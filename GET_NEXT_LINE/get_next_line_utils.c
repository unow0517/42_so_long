/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:33:42 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/25 08:56:54 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *) str;
	while (*ptr != '\0')
	{
		if (*ptr != (char)c)
			ptr++;
		else
			return (ptr);
	}
	if (*ptr == (char)c)
	{
		return (ptr);
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = (unsigned char *)dest;
	ps = (const unsigned char *)src;
	if (pd == 0 && ps == 0)
		return (0);
	while (n)
	{
		*pd++ = *ps++;
		n--;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*res_ptr;

	result = (char *)malloc((ft_strlen(s1)+ft_strlen(s2)+1) * sizeof(char));
	if (!result)
		return (0);
	res_ptr = result;
	while (*s1 != '\0')
		*(res_ptr++) = *(s1++);
	while (*s1 == '\0' && *s2 != '\0')
		*(res_ptr++) = *(s2++);
	if (*s2 == '\0')
		*res_ptr = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	result = (char *)malloc((ft_strlen(src)+1) * sizeof(char));
	if (!result)
		return (0);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	j = 0;
	if (src[j] == '\0')
		result[j] = '\0';
	return (result);
}
