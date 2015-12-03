/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 06:40:02 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/03 15:33:05 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*tmp1;
	const char	*tmp2;

	if (!(s1) || !(s2))
		return (0);
	tmp1 = s1;
	tmp2 = s2;
	i = 0;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
		i++;
	}
	return (0);
}
