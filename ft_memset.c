/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:42:14 by mlinhard          #+#    #+#             */
/*   Updated: 2015/11/28 13:42:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *byte;

	if (n == 0)
		return (s);
	byte = (char *)s;
	if (!byte)
		return (s);
	while (n--)
		*byte++ = (char)c;
	return (s);
}
