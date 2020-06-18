#include "libft.h"

int	ft_isdigit(int ch)
{
	if (ch < 0 || ch > 255)
		return (0);
	else if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}
