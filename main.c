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
int		test_strlen(void);
int		test_strlen_(char *str);

int		main(void)
{
	test_run();
	return (0);
}

int		test_run(void)
{	
	int		nb_err;
	int		nb_err_total;
	char	*color;

	// TEST STRLEN
	nb_err_total = 0; nb_err = 0;
	printf("%s----[ft_strlen]--VS--[strlen]----%s\n", YELLOW, WHITE);
	nb_err = (nb_err + test_strlen());
	color = (nb_err == 0) ? GREEN : RED ;
	printf("%s[ft_strlen] - %i erreur(s)%s\n\n", color, nb_err, WHITE);

	// PUTCHAR & PUTCHAR_FD
	nb_err_total = (nb_err_total + nb_err); nb_err = 0;	
	printf("%s------[ft_putchar]------%s\n123 \t4\n", YELLOW, WHITE);
	ft_putchar('1');ft_putchar('2');ft_putchar('3');ft_putchar(' ');ft_putchar('\t');ft_putchar('4');ft_putchar('\n');
	printf("%s[ft_putchar] - ?? erreur(s) (verif manuel)%s\n\n", BLUE, WHITE);
	printf("%s------[ft_putchar_fd]------%s\n", YELLOW, WHITE);
	ft_putchar_fd('F', 1);ft_putchar_fd('D', 1);ft_putchar_fd('=', 1);ft_putchar_fd('2', 1);ft_putchar_fd('\n', 1);
	ft_putchar_fd('F', 2);ft_putchar_fd('D', 2);ft_putchar_fd('=', 2);ft_putchar_fd('2', 2);ft_putchar_fd('\n', 2);
	ft_putchar_fd('F', 3);ft_putchar_fd('D', 3);ft_putchar_fd('=', 3);ft_putchar_fd('3', 3);ft_putchar_fd('\n', 3);
	printf("%s[ft_putchar_fd] - ?? erreur(s) (verif manuel)%s\n\n", BLUE, WHITE);

	// PUTSTR & PUTSTR_FD
	printf("%s------[ft_putstr]------%s\n", YELLOW, WHITE);
	ft_putstr("Ceci est une chaine de test\n\n");
	printf("%s------[ft_putstr_fd]------%s\n", YELLOW, WHITE);
	ft_putstr_fd("Cette chaine est sur le FD 1\n", 1);
	ft_putstr_fd("Cette chaine est sur le FD 2\n", 2);
	ft_putstr_fd("Cette chaine est sur le FD 3\n", 3);
	printf("%s[ft_putstr] - ?? erreur(s) (verif manuel)%s\n\n", BLUE, WHITE);

	// PUTNBR & PUTNBR FD
	printf("%s------[ft_putnbr]------%s\n", YELLOW, WHITE);
	ft_putnbr(-1); write(1, "\t-1\n", 4);
	ft_putnbr(0); write(1, "\t0\n", 3);
	ft_putnbr(1); write(1, "\t1\n", 3);
	ft_putnbr(-47895); write(1, "\t-47895\n", 8);
	printf("%s[ft_putnbr] - ?? erreur(s) (verif manuel)%s\n\n", BLUE, WHITE);
	printf("%s------[ft_putnbr_fd]------%s\n", YELLOW, WHITE);
	ft_putnbr_fd(-1, 1); write(1, "\t-1\tFD=1\n", 9);
	ft_putnbr_fd(0, 1); write(1, "\t0\tFD=1\n", 8);
	ft_putnbr_fd(1, 1); write(1, "\t1\tFD=1\n", 8);
	ft_putnbr_fd(-47895, 1); write(1, "\t-47895\tFD=1\n", 13);
	ft_putnbr_fd(47895, 1); write(1, "\t47895\tFD=1\n", 12);
	ft_putnbr_fd(47895, 2); write(2, "\t47895\tFD=2\n", 12);
	ft_putnbr_fd(47895, 3); write(3, "\t47895\tFD=3\n", 12);
	printf("%s[ft_putnbr_fd] - ?? erreur(s) (verif manuel)%s\n\n", BLUE, WHITE);

	// TOUPPER
	nb_err_total = (nb_err_total + nb_err); nb_err = 0;
	printf("%s------[ft_toupper]------%s\n", YELLOW, WHITE);
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
	color = (nb_err == 0) ? GREEN : RED ;
	printf("%s[ft_toupper] - %i erreur(s)%s\n\n", color, nb_err, WHITE);
	// TOLOWER
	nb_err_total = (nb_err_total + nb_err); nb_err = 0;
	printf("%s------[ft_tolower]------%s\n", YELLOW, WHITE);
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
	color = (nb_err == 0) ? GREEN : RED ;
	printf("%s[ft_tolower] - %i erreur(s)%s\n\n", color, nb_err, WHITE);

	// RESULTAT FINAL
	nb_err_total = (nb_err_total + nb_err);
	printf("[TOTAL] - %i erreur(s)\n", nb_err_total);
	return(nb_err);
}

int		test_strlen(void)
{
	int		nb_err;

	nb_err = 0;
	nb_err = (nb_err + test_strlen_("@-?.\\lol		hi"));
	nb_err = (nb_err + test_strlen_("blabla"));
	nb_err = (nb_err + test_strlen_("	ojjohj 	jhi ojh	ihiz zeiflh ziefh z fzihfoizh	 zifhzifh zihzeif 	ioh zfih ze 	oih zihf z zoifh 	 onceih izhf zifdh 	 izohfoizh fzihf 	oih fi zifh zifh zoifh zidh 	ioh zoifh ziohf zoi zofhzoihfezoi h	ih oizhfoizhfoizh foizhfoh	 zoiuehf zoihf oizh 	oi zoifhzoifh ifh zfih zoifeh zoifh 	i hizfh oizefh i 	i zoiefh zohf ziohf zoih	ih zihf oizhf 	oihf ih"));
	nb_err = (nb_err + test_strlen_(" "));
	nb_err = (nb_err + test_strlen_(""));
	
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


