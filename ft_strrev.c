/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:53:19 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/16 18:33:28 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	*str_end;
	char	c;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	str_end = str;
	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i++] = str_end[j];
		str_end[j--] = c;
	}
	return (str);
}
