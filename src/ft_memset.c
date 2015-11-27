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
