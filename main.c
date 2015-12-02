#include <stdio.h>
#include <ctype.h>
#include "libft.h"

#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define WHITE	"\x1B[37m"
#define OK		"\x1B[32m[ OK ]\x1B[37m"
#define FAIL	"\x1B[31m[ XX ]\x1B[37m"

int		test_run(void);
void	test_display_result(char *s, int nb_err);
void	test_display_title(char *s);
void	test_pressenter();

int		test_isalpha(void);
int		test_isalpha_(int c);

int		test_strlen(void);
int		test_strlen_(char *str);
int		test_putchar_putstr_putnbr(void);

int		test_toupper_tolower(void);
int		test_toupper_(int c);
int		test_tolower_(int c);

int		test_memset(void);
int		test_memset_(void *s, int c, size_t n);
int		test_bzero(void);
int		test_bzero_(void *s, size_t n);
int		test_memcpy(void);
int		test_memcpy_(void *dest, const void *src, size_t n);
int		test_memccpy(void);
int		test_memccpy_(void *dest, const void *src, int c, size_t n);
int		test_memmove(void);
int		test_memmove_(void *dest, const void *src, size_t n);
int		test_memchr(void);
int		test_memchr_(const void *s, int c, size_t n);
int		test_memcmp(void);
int		test_memcmp_(const void *dest, const void *src, size_t n);

int		test_strcpy(void);
int		test_strcpy_(char *dest, const char *src);
int		test_strncpy(void);
int		test_strncpy_(char *dest, const char *src, size_t n);
int		test_strdup(void);
int		test_strdup_(const char *s1);
int		test_strcat(void);
int		test_strcat_(char *s1, const char *s2);
int		test_strncat(void);
int		test_strncat_(char *s1, const char *s2, size_t n);


int		mode = 0;

int		main(int argc, char **argv)
{
	if (argc > 1 && strcmp(argv[1], "pause") == 0)
		mode = 1;
	test_run();
	return (0);
}

void	test_pressenter(void)
{
	if (mode == 1)
	{
		printf("\n\n\t- Press [enter] to continue...");
		char enter = 0;
		while (enter != '\r' && enter != '\n') { enter = getchar(); }
	}
}

int		test_run(void)
{	
	int		nb_err;
	int		nb_err_total;
	
	nb_err_total = 0;
	nb_err = 0;

	// STRLEN
	nb_err_total = (nb_err_total + test_strlen());
	// TOUPPER & TOLOWER
	nb_err_total = (nb_err_total + test_toupper_tolower());

	/****************************
	 * 		IS ???				*
	 ****************************/
	nb_err_total = (nb_err_total + test_isalpha());

	/****************************
	 * 		MEM FUNCTION		*
	 ****************************/
	 // MEMSET
	nb_err_total = (nb_err_total + test_memset());
	// BZERO
	nb_err_total = (nb_err_total + test_bzero());
	// MEMCPY
	nb_err_total = (nb_err_total + test_memcpy());
	// MEMCCPY
	nb_err_total = (nb_err_total + test_memccpy());
	// MEMMOVE
	nb_err_total = (nb_err_total + test_memmove());
	// MEMCHR
	nb_err_total = (nb_err_total + test_memchr());
	// MEMCMP
	nb_err_total = (nb_err_total + test_memcmp());

	// STRCPY
	nb_err_total = (nb_err_total + test_strcpy());
	// STRNCPY
	nb_err_total = (nb_err_total + test_strncpy());
	// STRDUP
	nb_err_total = (nb_err_total + test_strdup());
	// STRCAT
	nb_err_total = (nb_err_total + test_strcat());
	// STRNCAT
	nb_err_total = (nb_err_total + test_strncat());

	// PUTCHAR & PUTCHAR_FD
	test_putchar_putstr_putnbr();


	// RESULTAT FINAL
	nb_err_total = (nb_err_total + nb_err);
	printf("[TOTAL] - %i erreur(s)\n", nb_err_total);
	return(nb_err_total);
}

void	test_display_title(char *s)
{
	printf("%s%s%s\n", BLUE, s, WHITE);
	printf("%s***************************%s\n", YELLOW, WHITE);
}

void	test_display_result(char *s, int nb_err)
{
	char *color;

	printf("%s***************************%s\n", YELLOW, WHITE);
	if (nb_err == -1)
		printf("%s[%s] - ?? erreur(s) (verif manuel)%s", BLUE, s, WHITE);
	else
	{
		color = (nb_err == 0) ? GREEN : RED ;
		printf("%s[%s] - %i erreur(s)%s", color, s, nb_err, WHITE);
	}
	test_pressenter();
	printf("\n\n\n");
}

int		test_strlen(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_STRLEN");
	nb_err = (nb_err + test_strlen_("@-?.\\lol		hi"));
	nb_err = (nb_err + test_strlen_("blabla"));
	nb_err = (nb_err + test_strlen_("	ojjohj 	jhi ojh	ihiz zeiflh ziefh z fzihfoizh	 zifhzifh zihzeif 	ioh zfih ze 	oih zihf z zoifh 	 onceih izhf zifdh 	 izohfoizh fzihf 	oih fi zifh zifh zoifh zidh 	ioh zoifh ziohf zoi zofhzoihfezoi h	ih oizhfoizhfoizh foizhfoh	 zoiuehf zoihf oizh 	oi zoifhzoifh ifh zfih zoifeh zoifh 	i hizfh oizefh i 	i zoiefh zohf ziohf zoih	ih zihf oizhf 	oihf ih"));
	nb_err = (nb_err + test_strlen_(" "));
	nb_err = (nb_err + test_strlen_(""));
	test_display_result("FT_STRLEN", nb_err);
	
	return(nb_err);
}

int		test_strlen_(char *str)
{
	int		i;
	char	*result;

	i = (strlen(str) - ft_strlen(str));
	result = (i == 0) ? OK : FAIL ;
	printf("%s\t[%zu]\t[%zu]\t\"%s\"\n", result, strlen(str), ft_strlen(str), str);
	if (i == 0)
		return (0);
	else
		return (1);
}

int		test_putchar_putstr_putnbr(void)
{
	// PUTCHAR & PUTCHAR_FD
	test_display_title("FT_PUTCHAR");
	printf("123 \t4\n");
	ft_putchar('1');ft_putchar('2');ft_putchar('3');ft_putchar(' ');ft_putchar('\t');ft_putchar('4');ft_putchar('\n');
	test_display_result("FT_PUTCHAR", -1);
	test_display_title("FT_PUTCHAR_FD");
	ft_putchar_fd('F', 1);ft_putchar_fd('D', 1);ft_putchar_fd('=', 1);ft_putchar_fd('1', 1);ft_putchar_fd('\n', 1);
	ft_putchar_fd('F', 2);ft_putchar_fd('D', 2);ft_putchar_fd('=', 2);ft_putchar_fd('2', 2);ft_putchar_fd('\n', 2);
	ft_putchar_fd('F', 3);ft_putchar_fd('D', 3);ft_putchar_fd('=', 3);ft_putchar_fd('3', 3);ft_putchar_fd('\n', 3);
	test_display_result("FT_PUTCHAR_FD", -1);

	// PUTSTR & PUTSTR_FD
	test_display_title("FT_PUTSTR");
	ft_putstr("Ceci est une chaine de test\n");
	test_display_result("FT_PUTSTR", -1);
	test_display_title("FT_PUTSTR_FD");
	ft_putstr_fd("Cette chaine est sur le FD 1\n", 1);
	ft_putstr_fd("Cette chaine est sur le FD 2\n", 2);
	ft_putstr_fd("Cette chaine est sur le FD 3\n", 3);
	test_display_result("FT_PUTSTR_FD", -1);

	// PUTNBR & PUTNBR FD
	test_display_title("FT_PUTNBR");
	ft_putnbr(-1); write(1, "\t-1\n", 4);
	ft_putnbr(0); write(1, "\t0\n", 3);
	ft_putnbr(1); write(1, "\t1\n", 3);
	ft_putnbr(-47895); write(1, "\t-47895\n", 8);
	test_display_result("FT_PUTNBR", -1);
	test_display_title("FT_PUTNBR_FD");
	ft_putnbr_fd(-1, 1); write(1, "\t-1\tFD=1\n", 9);
	ft_putnbr_fd(0, 1); write(1, "\t0\tFD=1\n", 8);
	ft_putnbr_fd(1, 1); write(1, "\t1\tFD=1\n", 8);
	ft_putnbr_fd(-47895, 1); write(1, "\t-47895\tFD=1\n", 13);
	ft_putnbr_fd(47895, 1); write(1, "\t47895\tFD=1\n", 12);
	ft_putnbr_fd(47895, 2); write(2, "\t47895\tFD=2\n", 12);
	ft_putnbr_fd(47895, 3); write(3, "\t47895\tFD=3\n", 12);
	test_display_result("FT_PUTNBR_FD", -1);

	return (0);
}


int		test_isalpha(void)
{
	int		nb_err;

	nb_err = 0;

	// ISALPHA
	test_display_title("FT_ISALPHA");
	nb_err = (nb_err + test_isalpha_('a'));
	nb_err = (nb_err + test_isalpha_('+'));
	nb_err = (nb_err + test_isalpha_('7'));
	nb_err = (nb_err + test_isalpha_('z'));
	test_display_result("FT_ISALPHA", nb_err);

	return (nb_err);
}

int		test_isalpha_(int c)
{
	if ((isalpha(c) - ft_isalpha(c)) == 0)
	{
		printf("%s ft_isalpha(%c) [ %d ]\n", OK, c, ft_isalpha(c));
		return (0);
	}
	else
	{
		printf("%s ft_isalpha(%c) [ %d ]\n", FAIL, c, ft_isalpha(c));
		return (1);
	}
}

int		test_toupper_tolower(void)
{
	int		nb_err;
	int		nb_err_total;

	nb_err = 0;
	nb_err_total = 0;

	// TOUPPER
	test_display_title("FT_TOUPPER");
	nb_err = (nb_err + test_toupper_('a'));
	nb_err = (nb_err + test_toupper_('Q'));
	nb_err = (nb_err + test_toupper_('7'));
	nb_err = (nb_err + test_toupper_('z'));
	test_display_result("FT_TOUPPER", nb_err);

	// TOLOWER
	nb_err_total = nb_err; nb_err = 0;
	test_display_title("FT_TOLOWER");
	nb_err = (nb_err + test_tolower_('Q'));
	nb_err = (nb_err + test_tolower_('a'));
	nb_err = (nb_err + test_tolower_('0'));
	nb_err = (nb_err + test_tolower_('L'));
	test_display_result("FT_TOLOWER", nb_err);
	nb_err_total = (nb_err_total + nb_err);

	return (nb_err_total);
}

int		test_toupper_(int c)
{
	if ((toupper(c) - ft_toupper(c)) == 0)
	{
		printf("%s ft_toupper(%c) [ %c ]\n", OK, c, ft_toupper(c));
		return (0);
	}
	else
	{
		printf("%s ft_toupper(%c) [ %c ]\n", FAIL, c, ft_toupper(c));
		return (1);
	}
}

int		test_tolower_(int c)
{
	if ((tolower(c) - ft_tolower(c)) == 0)
	{
		printf("%s ft_tolower(%c) [ %c ]\n", OK, c, ft_tolower(c));
		return (0);
	}
	else
	{
		printf("%s ft_tolower(%c) [ %c ]\n", FAIL, c, ft_tolower(c));
		return (1);
	}
}

int		test_memset(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_MEMSET");
	
	nb_err = (nb_err + test_memset_("Test with to long n", '-', 22));
	nb_err = (nb_err + test_memset_("Test with normal sentence and n", '$', 7));
	nb_err = (nb_err + test_memset_("Test with n = 0", '$', 0));
	nb_err = (nb_err + test_memset_("", '0', 4));
	nb_err = (nb_err + test_memset_("aa\0aa", '?', 3));

	test_display_result("FT_MEMSET", nb_err);
	return (nb_err);
}

int		test_memset_(void *s, int c, size_t n)
{
	int		nb_err;
	int		compare;
	char	*str;
	char	*str2;

	nb_err = 0;

	str = strdup(s);	
	str2 = strdup(s);
	printf("->(\"%s\", '%c', %zu);\n", str, c, n);
	memset(str, c, n);
	ft_memset(str2, c, n);
	printf(" [...memset]\t%s\n", str);
	printf(" [ft_memset]\t%s\n", str2);
	compare = strcmp(str, str2);
	if (compare == 0)
		printf("%s strcmp = %d\n", OK, compare);
	else
	{
		printf("%s strcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}

int		test_bzero(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_BZERO");
	
	nb_err = (nb_err + test_bzero_("Test with to long n", 22));
	nb_err = (nb_err + test_bzero_("Test with normal sentence and n", 7));
	nb_err = (nb_err + test_bzero_("Test with n = 0", 0));
	nb_err = (nb_err + test_bzero_("", 4));
	nb_err = (nb_err + test_bzero_("aa\0aa", 3));

	test_display_result("FT_BZERO", nb_err);
	return (nb_err);
}

int		test_bzero_(void *s, size_t n)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	*str;
	char	*str2;


	nb_err = 0;

	str = strdup(s);	
	str2 = strdup(s);
	str_len = ( n > strlen(str)) ? n : strlen(str);
	printf("->(\"%s\", %zu);\n", str, n);
	bzero(str, n);
	ft_bzero(str2, n);
	printf(" [...bzero]\t%s\n", str);
	printf(" [ft_bzero]\t%s\n", str2);
	compare = memcmp(str, str2, str_len);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}

int		test_memcpy(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_MEMCPY");
	
	nb_err = (nb_err + test_memcpy_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", 5));
	nb_err = (nb_err + test_memcpy_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", 25));
	nb_err = (nb_err + test_memcpy_("TEST", "Test.string 1 bloblo", 6));

	test_display_result("FT_MEMCPY", nb_err);
	return (nb_err);
}


int		test_memcpy_(void *dest, const void *src, size_t n)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	*dest_1;
	char	*dest_2;
	char	*src_1;


	nb_err = 0;

	dest_1 = strdup(dest);	
	dest_2 = strdup(dest);	
	src_1 = strdup(src);
	str_len = ( n > strlen(dest_1)) ? n : strlen(dest_1);
	printf("->(\"%s\", \"%s\", %zu);\n", dest_1, src_1, n);
	memcpy(dest_1, src_1, n);
	ft_memcpy(dest_2, src_1, n);
	printf(" [...memcpy]\t%s\n", dest_1);
	printf(" [ft_memcpy]\t%s\n", dest_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);

}


int		test_memccpy(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_MEMCCPY");
	
	nb_err = (nb_err + test_memccpy_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", '.', 3));
	nb_err = (nb_err + test_memccpy_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", 'r', 25));
	nb_err = (nb_err + test_memccpy_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", '?', 25));
	nb_err = (nb_err + test_memccpy_("TEST", "Test.string 1 bloblo", 'g', 6));

	test_display_result("FT_MEMCCPY", nb_err);
	return (nb_err);
}


int		test_memccpy_(void *dest, const void *src, int c, size_t n)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	*dest_1;
	char	*dest_2;
	char	*src_1;
	char	*ret_1;
	char	*ret_2;


	nb_err = 0;

	dest_1 = strdup(dest);	
	dest_2 = strdup(dest);	
	src_1 = strdup(src);
	str_len = ( n > strlen(dest_1)) ? n : strlen(dest_1);
	printf("->(\"%s\", \"%s\", '%c', %zu);\n", dest_1, src_1, c, n);
	ret_1 = memccpy(dest_1, src_1, c, n);
	ret_2 = ft_memccpy(dest_2, src_1, c, n);
	printf(" [...memccpy]\t%s\n", dest_1);
	printf(" [...return]\t%s\n", ret_1);
	printf(" [ft_memccpy]\t%s\n", dest_2);
	printf(" [ft_return]\t%s\n", ret_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (ret_1 && ret_2)
		compare = (compare + memcmp(ret_1, ret_2, str_len));
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);

}

int		test_memmove(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_MEMMOVE");
	
	nb_err = (nb_err + test_memmove_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", 3));
	nb_err = (nb_err + test_memmove_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", 25));
	nb_err = (nb_err + test_memmove_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", 25));
	nb_err = (nb_err + test_memmove_("TEST", "Test.string 1 bloblo", 6));

	test_display_result("FT_MEMMOVE", nb_err);
	return (nb_err);
}


int		test_memmove_(void *dest, const void *src, size_t n)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	*dest_1;
	char	*dest_2;
	char	*src_1;
	char	*ret_1;
	char	*ret_2;


	nb_err = 0;

	dest_1 = strdup(dest);	
	dest_2 = strdup(dest);	
	src_1 = strdup(src);
	str_len = ( n > strlen(dest_1)) ? n : strlen(dest_1);
	printf("->(\"%s\", \"%s\", %zu);\n", dest_1, src_1, n);
	ret_1 = memmove(dest_1, src_1, n);
	ret_2 = ft_memmove(dest_2, src_1, n);
	printf(" [...memmove]\t%s\n", dest_1);
	printf(" [...return]\t%s\n", ret_1);
	printf(" [ft_memmove]\t%s\n", dest_2);
	printf(" [ft_return]\t%s\n", ret_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (ret_1 && ret_2)
		compare = (compare + memcmp(ret_1, ret_2, str_len));
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);

}

int		test_memchr(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_MEMCHR");
	
	nb_err = (nb_err + test_memchr_("TEST STRING 1 BLABLA", 'T', 10));
	nb_err = (nb_err + test_memchr_("TEST STRING 1 BLABLA", 'E', 10));
	nb_err = (nb_err + test_memchr_("TEST STRING 1 BLABLA", 'S', 10));
	nb_err = (nb_err + test_memchr_("TEST STRING 1 BLABLA", 't', 10));
	nb_err = (nb_err + test_memchr_("TEST STRING 1 BLABLA", ' ', 3));

	test_display_result("FT_MEMCHR", nb_err);
	return (nb_err);
}


int		test_memchr_(const void *s, int c, size_t n)
{
	int		nb_err;
	int		compare;
	char	*src_1;
	char	*ret_1;
	char	*ret_2;


	nb_err = 0;
	compare = 0;
	src_1 = strdup(s);
	printf("->(\"%s\", \"%c\", %zu);\n", src_1, c, n);
	ret_1 = memchr(src_1, c, n);
	ret_2 = ft_memchr(src_1, c, n);
	printf(" [...memmove return]\t%s\n", ret_1);
	printf(" [ft_memmove return]\t%s\n", ret_2);
	if (ret_1 && ret_2)
		compare = memcmp(ret_1, ret_2, strlen(ret_1));
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}

int		test_memcmp(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_MEMCMP");
	
	nb_err = (nb_err + test_memcmp_("Test,sTRING 1 BLABLA", "Test.string 1 bloblo", 5));
	nb_err = (nb_err + test_memcmp_("TEST STRING 1 BLABLA", "Test.string 1 bloblo", 25));
	nb_err = (nb_err + test_memcmp_("Test.string 1", "Test.string 1 bloblo", 6));

	test_display_result("FT_MEMCMP", nb_err);
	return (nb_err);
}


int		test_memcmp_(const void *s1, const void *s2, size_t n)
{
	int		nb_err;
	int		compare;
	int		ret_1;
	int		ret_2;

	nb_err = 0;

	printf("->(\"%s\", \"%s\", %zu);\n", s1, s2, n);
	ret_1 = memcmp(s1, s2, n);
	ret_2 = ft_memcmp(s1, s2, n);
	printf(" [...memcmp]\t%d\n", ret_1);
	printf(" [ft_memcmp]\t%d\n", ret_2);
	compare = (ret_1 - ret_2);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);

}

int		test_strcpy(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_STRCPY");
	
	nb_err = (nb_err + test_strcpy_("TEST STRING 1 BLABLA", "Test.string 1 bloblo"));
	nb_err = (nb_err + test_strcpy_("TEST STRING 1 BLABLAioooooooo", "Test"));
	nb_err = (nb_err + test_strcpy_("TEST", "Test.string 1 bloblo"));
	nb_err = (nb_err + test_strcpy_("TEST", ""));
	nb_err = (nb_err + test_strcpy_("", "TEST"));

	test_display_result("FT_STRCPY", nb_err);
	return (nb_err);
}


int		test_strcpy_(char *dest, const char *src)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	*dest_1;
	char	*dest_2;
	char	*src_1;


	nb_err = 0;

	dest_1 = strdup(dest);	
	dest_2 = strdup(dest);	
	src_1 = strdup(src);
	str_len = strlen(dest_1);
	printf("->(\"%s\", \"%s\");\n", dest_1, src_1);
	strcpy(dest_1, src_1);
	ft_strcpy(dest_2, src_1);
	printf(" [...strcpy]\t%s\n", dest_1);
	printf(" [ft_strcpy]\t%s\n", dest_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}

int		test_strncpy(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_STRNCPY");
	
	nb_err = (nb_err + test_strncpy_("String 1 blabla", "olol", 3));
	nb_err = (nb_err + test_strncpy_("String 2 blabla", "olol", 6));
	nb_err = (nb_err + test_strncpy_("String 3 blabla", "sTRING 3 BLABLABLA", 18));
	nb_err = (nb_err + test_strncpy_("", "sTRING 4 BLABLABLA", 3));
	nb_err = (nb_err + test_strncpy_("String 5 blabla", "to short", 10));

	test_display_result("FT_STRNCPY", nb_err);
	return (nb_err);
}


int		test_strncpy_(char *dest, const char *src, size_t n)
{
	int		nb_err;
	int		compare;
	size_t		str_len;
	char	dest_1[100];
	char	dest_2[100];
	char	*src_1;


	nb_err = 0;

	strcpy(dest_1, dest);
	strcpy(dest_2, dest);
	//dest_1 = strdup(dest);
	//dest_2 = strdup(dest);
	src_1 = strdup(src);
	str_len = strlen(dest_1);
	if (n > str_len)
		str_len = n;
	printf("->(\"%s\", \"%s\", %zu);\n", dest_1, src_1, n);
	strncpy(dest_1, src_1, n);
	ft_strncpy(dest_2, src_1, n);
	printf(" [...strncpy]\t%s\n", dest_1);
	printf(" [ft_strncpy]\t%s\n", dest_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}

int		test_strcat(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_STRCAT");
	
	nb_err = (nb_err + test_strcat_("Chaine 1", " - ajout 1"));
	nb_err = (nb_err + test_strcat_("Chaine 2", " - add !!"));

	test_display_result("FT_STRCAT", nb_err);
	return (nb_err);
}


int		test_strcat_(char *s1, const char *s2)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	dest_1[100];
	char	dest_2[100];
	char	*src_1;

	nb_err = 0;

	memset(dest_1, 'a', 100);
	memset(dest_2, 'a', 100);
	strcpy(dest_1, s1);
	strcpy(dest_2, s1);
	src_1 = strdup(s2);
	str_len = 100;
	printf("->(\"%s\", \"%s\");\n", dest_1, src_1);
	strcat(dest_1, src_1);
	ft_strcat(dest_2, src_1);
	printf(" [...strcat]\t%s\n", dest_1);
	printf(" [ft_strcat]\t%s\n", dest_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}

int		test_strncat(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_STRNCAT");
	
	nb_err = (nb_err + test_strncat_("Chaine 1", "-ajout 1", 3));
	nb_err = (nb_err + test_strncat_("Chaine 2", "-add !!", 10));

	test_display_result("FT_STRNCAT", nb_err);
	return (nb_err);
}


int		test_strncat_(char *s1, const char *s2, size_t n)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	dest_1[100];
	char	dest_2[100];
	char	*src_1;

	nb_err = 0;

	memset(dest_1, 'a', 100);
	memset(dest_2, 'a', 100);
	strcpy(dest_1, s1);
	strcpy(dest_2, s1);
	src_1 = strdup(s2);
	str_len = 100;
	printf("->(\"%s\", \"%s\", %zu);\n", dest_1, src_1, n);
	strncat(dest_1, src_1, n);
	ft_strncat(dest_2, src_1, n);
	printf(" [...strncat]\t%s\n", dest_1);
	printf(" [ft_strncat]\t%s\n", dest_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}



int		test_strdup(void)
{
	int		nb_err;

	nb_err = 0;
	test_display_title("FT_STRDUP");
	
	nb_err = (nb_err + test_strdup_("TEST STRING 1 BLABLA"));
	nb_err = (nb_err + test_strdup_("Ceci est un test lalal"));
	nb_err = (nb_err + test_strdup_(""));

	test_display_result("FT_STRDUP", nb_err);
	return (nb_err);
}


int		test_strdup_(const char *s1)
{
	int		nb_err;
	int		compare;
	int		str_len;
	char	*dest_1;
	char	*dest_2;


	nb_err = 0;

	dest_1 = strdup(s1);	
	dest_2 = ft_strdup(s1);	
	str_len = strlen(dest_1);
	printf("->(\"%s\");\n", s1);
	printf(" [...strdup]\t%s\n", dest_1);
	printf(" [ft_strdup]\t%s\n", dest_2);
	compare = memcmp(dest_1, dest_2, str_len);
	if (compare == 0)
		printf("%s memcmp = %d \n", OK, compare);
	else
	{
		printf("%s memcmp = %d\n", FAIL, compare);	
		nb_err = 1;
	}
	return (nb_err);
}

