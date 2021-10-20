#include "./includes/ft_printf.h"

int	print_unsign(va_list ap, int done)
{
	unsigned int	i;
	char			*s;

	i = va_arg(ap, int);
	s = fttoa(i);
	i = 0;
	while (s[i])
		done += write(1, &s[i++], 1);
	return (done);
}

int	print_proc(int done)
{
	char	c;

	c = '%';
	done += write(1, &c, 1);
	return (done);
}

int	print_str(va_list ap, int done)
{
	char	*a;
	int		i;

	i = 0;
	a = va_arg(ap, char *);
	if (!a)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (a[i])
		done += write(1, &a[i++], 1);
	return (done);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	if (!s)
		return (NULL);
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
