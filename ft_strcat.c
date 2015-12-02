/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:09:12 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/02 16:33:59 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char	*ret;

	if (!s2)
		return (NULL);
	ret = s1;
	while (*s1)
		s1++;
	ft_strcpy(s1, s2);
	return (ret);
}
