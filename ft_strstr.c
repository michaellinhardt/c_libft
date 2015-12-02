/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:38:44 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/02 18:54:07 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*tmp_s1;
	const char	*tmp_s2;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		tmp_s1 = s1;
		tmp_s2 = s2;
		while (*tmp_s2 != '\0' && *tmp_s1 == *tmp_s2)
		{
			tmp_s1++;
			tmp_s2++;
		}
		if (*tmp_s2 == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
