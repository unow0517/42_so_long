/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:08:31 by yowoo             #+#    #+#             */
/*   Updated: 2024/03/16 17:25:15 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst || !lst)
	{
		*lst = new;
	}
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}

//lst = pointer to list
//*lst = pointer to node
//accessing content of list with pointer to node