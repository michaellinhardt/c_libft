/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:05:58 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/03 20:27:12 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (f)(t_list *elem))
{
	t_list *list;

	if (lst)
	{
		list = lst;
		while (list)
		{
			f(list);
			list = list->next;
		}
	}
}
