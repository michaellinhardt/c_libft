/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:50:05 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/03 19:39:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*ret;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	end = ft_strlen(s);
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	if (!(ret = ft_strsub(s, start, (end - start))))
		return (NULL);
	return (ret);
}
