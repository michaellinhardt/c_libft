#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_islower(char c);
int		ft_isupper(char c);

#endif
