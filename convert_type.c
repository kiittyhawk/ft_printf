#include "./includes/ft_printf.h"

int	print_char(va_list ap, int done)
{
	char	a;

	a = (char)va_arg(ap, int);
	return (done + write(1, &a, 1));
}

int	print_int(va_list ap, int done)
{
	char	*a;
	int		i;

	i = 0;
	a = ft_itoa(va_arg(ap, int));
	while (a[i])
		done += write(1, &a[i++], 1);
	return (done);
}

char	*from10in16(size_t num, char *str)
{
	int		i;
	char	chr;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(str);
	while (num && num != 4294967295)
	{
		i = num % 16;
		if (i >= 10 && i <= 15)
			chr = ((i % 10) + 'A');
		else
			chr = (i + '0');
		if (j < len)
		{
			str[j] = chr;
			j++;
		}
		num = num / 16;
	}
	str[j] = '\0';
	return (ft_strrev(str));
}

int	print_x16(va_list ap, int done, int flg)
{
	int		num;
	char	*str;
	int		i;

	str = ft_strdup("0000000000000000");
	num = va_arg(ap, unsigned int);
	if (!num)
	{
		write(1, "0", 1);
		return (1);
	}
	str = from10in16(num, str);
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) && !flg)
			str[i] = ft_tolower(str[i]);
		done += write(1, (&str[i]), 1);
		i++;
	}
	free(str);
	return (done);
}

int	print_pn(va_list ap, int done)
{
	size_t	addr;
	char	*str;
	int		i;
	char	*c;

	str = ft_strdup("0000000000000000");
	c = ft_strdup("0x");
	addr = (size_t)(va_arg(ap, void *));
	str = ft_strjoin(c, (from10in16(addr, str)));
	i = 0;
	if (addr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] = ft_tolower(str[i]);
		done += write(1, (&str[i]), 1);
		i++;
	}
	free(str);
	free(c);
	return (done);
}
