#include <stdio.h>
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
int		test_strlen(void);
int		test_strlen_(char *str);
int		test_putchar_putstr_putnbr(void);
int		test_toupper_tolower(void);
int		test_memset(void);
int		test_memset_(void *s, int c, size_t n);
int		test_bzero(void);
int		test_bzero_(void *s, size_t n);
int		test_memcpy(void);
int		test_memcpy_(void *dest, const void *src, size_t n);
int		test_memccpy(void);
int		test_memccpy_(void *dest, const void *src, int c, size_t n);
void	test_pressenter();


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
	nb_err = test_strlen();
	nb_err_total = (nb_err_total + nb_err);
	nb_err = 0;
	// TOUPPER & TOLOWER
	nb_err_total = (nb_err_total + test_toupper_tolower());


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

int		test_toupper_tolower(void)
{
	int		nb_err;
	int		nb_err_total;
	char	*color;

	nb_err = 0;
	nb_err_total = 0;

	// TOUPPER
	test_display_title("FT_TOUPPER");
	color = ( ('A' - ft_toupper('A')) == 0) ? OK : FAIL ;
	nb_err = ( ('A' - ft_toupper('A')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ A ]\t [ %c ]\n", color, ft_toupper('A'));
	color = ( ('Z' - ft_toupper('z')) == 0) ? OK : FAIL ;
	nb_err = ( ('Z' - ft_toupper('z')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ z ]\t [ %c ]\n", color, ft_toupper('z'));
	color = ( ('K' - ft_toupper('k')) == 0) ? OK : FAIL ;
	nb_err = ( ('K' - ft_toupper('k')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ k ]\t [ %c ]\n", color, ft_toupper('k'));
	color = ( ('-' - ft_toupper('-')) == 0) ? OK : FAIL ;
	nb_err = ( ('-' - ft_toupper('-')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ - ]\t [ %c ]\n", color, ft_toupper('-'));
	test_display_result("FT_TOUPPER", nb_err);

	// TOLOWER
	nb_err_total = nb_err; nb_err = 0;
	test_display_title("FT_TOLOWER");
	color = ( ('a' - ft_tolower('a')) == 0) ? OK : FAIL ;
	nb_err = ( ('a' - ft_tolower('a')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ a ]\t [ %c ]\n", color, ft_tolower('a'));
	color = ( ('z' - ft_tolower('Z')) == 0) ? OK : FAIL ;
	nb_err = ( ('z' - ft_tolower('Z')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ Z ]\t [ %c ]\n", color, ft_tolower('Z'));
	color = ( ('k' - ft_tolower('K')) == 0) ? OK : FAIL ;
	nb_err = ( ('k' - ft_tolower('K')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ K ]\t [ %c ]\n", color, ft_tolower('K'));
	color = ( ('-' - ft_tolower('-')) == 0) ? OK : FAIL ;
	nb_err = ( ('-' - ft_tolower('-')) == 0) ? nb_err : (nb_err + 1) ;
	printf("%s[ - ]\t [ %c ]\n", color, ft_tolower('-'));
	test_display_result("FT_TOLOWER", nb_err);
	nb_err_total = (nb_err_total + nb_err);

	return (nb_err_total);
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
