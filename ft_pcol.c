/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:18:50 by mlinhard          #+#    #+#             */
/*   Updated: 2015/12/11 12:41:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pcol(char *s)
{
	if (strcmp(s, "RE") == 0)
		return ("\033[0;31m");
	if (strcmp(s, "GR") == 0)
		return ("\033[0;32m");
	if (strcmp(s, "YE") == 0)
		return ("\033[0;33m");
	if (strcmp(s, "BL") == 0)
		return ("\033[0;34m");
	if (strcmp(s, "WH") == 0)
		return ("\033[0;38m");
	if (strcmp(s, "OK") == 0)
		return ("\033[0;38m[\033[0;32m OK \033[0;38m]");
	if (strcmp(s, "KO") == 0)
		return ("\033[0;38m[\033[0;31m KO \033[0;38m]");
	return ("");
}
