#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!(dest) || !(src))
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((char *)dest)[i] == c)
			return (&((char *)dest)[(i + 1)]);
		i++;
	}
	return (NULL);
}
