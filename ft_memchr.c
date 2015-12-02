/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 06:16:59 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/01 06:30:01 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmp;

	if (!(s) || n < 1)
		return (NULL);
	tmp = (unsigned char *)s;
	while(n--)
	{
		if(*tmp != (unsigned char)c)
			tmp++;
		else
			return (tmp);
	}
		return (NULL);
}
