/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:05:43 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:33:12 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
