#include "./includes/ft_printf.h"

static char	*ft_plus_int(unsigned int n, int len)
{
	char	*s;

	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (s == NULL)
		return (NULL);
	else
	{
		s[len] = '\0';
		len--;
		while (len >= 0)
		{
			s[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (s);
	}
	return (NULL);
}

static int	ft_nbr_len(unsigned int n)
{
	int	d;

	d = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

char	*fttoa(unsigned int n)
{
	char	*s;
	int		len;

	if (n == 4294967295)
		return (ft_strdup("4294967295"));
	len = ft_nbr_len(n);
	return (s = ft_plus_int(n, len));
}
