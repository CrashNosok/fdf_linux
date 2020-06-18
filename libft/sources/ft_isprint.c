#include "libft.h"

int	ft_isprint(int ch)
{
	if (ch >= ' ' && ch <= '~')
		return (1);
	return (0);
}
