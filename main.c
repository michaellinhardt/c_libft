#include <stdio.h>
#include <ctype.h>
#include "libft.h"

#define OK		"\x1B[32m[ OK ]\x1B[37m"
#define FAIL	"\x1B[31m[ XX ]\x1B[37m"

void	dotest(void)
{
	char	*result;
	char	buff1[6];
	char	buff2[6];

	memset(buff1, 33, 6);
	memset(buff2, 33, 6);
	ft_strncpy(buff1, "abc", 6);
	strncpy(buff2, "abc", 6);

	result = FAIL ;
	if (memcmp(buff1, "abc\0\0", 6) == memcmp(buff2, "abc\0\0", 6))
		result = OK;
	
	printf("ft: %s\nc.: %s\n%s ft == c\n", buff1, buff2, result);
}

int		main(void)
{
	printf("%s\n", ft_strtrim("   45678  "));
	dotest();
	return (0);
}
