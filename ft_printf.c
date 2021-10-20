#include "./includes/ft_printf.h"

int	check_type(const char *s, int i, va_list ap)
{
	int	done;

	done = 0;
	i++;
	if (s[i] == 'c')
		done += print_char(ap, done);
	else if (s[i] == 'd' || s[i] == 'i')
		done += print_int(ap, done);
	else if (s[i] == 's')
		done += print_str(ap, done);
	else if (s[i] == 'x')
		done += print_x16(ap, done, 0);
	else if (s[i] == 'p')
		done += print_pn(ap, done);
	else if (s[i] == 'X')
		done += print_x16(ap, done, 1);
	else if (s[i] == 'u')
		done += print_unsign(ap, done);
	else if (s[i] == '%')
		done += print_proc(done);
	else
		return (-1);
	return (done);
}

int	counter(const char *s, va_list ap)
{
	int		i;
	int		done;
	int		a;

	i = -1;
	done = 0;
	while (s[++i])
	{
		if (s[i] != '%')
			done = done + write(1, &s[i], 1);
		else if ((s[i] == '%' || s[i] == (char)92) && s[i + 1])
		{
			a = check_type(s, i, ap);
			if (a == -1)
				i--;
			done = done + a;
			i++;
		}
	}
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		done;

	if (!format)
		return (-1);
	va_start(ap, format);
	done = counter(format, ap);
	va_end(ap);
	return (done);
}
