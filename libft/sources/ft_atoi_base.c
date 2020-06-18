#include "libft.h"

static int		check_digit(char ch, int base)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (ch == str1[i] || ch == str2[i])
			return (1);
		i++;
	}
	return (0);
}

static int		rem_digit(char ch)
{
	if (ch >= 'a' && ch <= 'f')
		return (ch - 87);
	else if (ch >= 'A' && ch <= 'F')
		return (ch - 55);
	else
		return (ch - '0');
}

int				ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		sign;
	int		nu;

	nu = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] != '\0' && check_digit(str[i], str_base))
	{
		nu = nu * str_base + (rem_digit(str[i]));
		i++;
	}
	return (nu * sign);
}
