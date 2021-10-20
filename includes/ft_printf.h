#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		counter(const char *s, va_list ap);
int		check_type(const char *s, int i, va_list ap);
int		print_str(va_list ap, int done);
char	*ft_strncat(char *dest, char *src, int nb);
char	*ft_strrev(char *str);
char	*fttoa(unsigned int n);
int		print_char(va_list ap, int done);
int		print_int(va_list ap, int done);
char	*from10in16(size_t num, char *str);
int		print_x16(va_list ap, int done, int flg);
int		print_pn(va_list ap, int done);
int		print_unsign(va_list ap, int done);
int		print_proc(int done);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
int		ft_tolower(int c);
char	*ft_strnew(size_t size);

#endif