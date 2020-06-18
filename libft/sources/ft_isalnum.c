#include "libft.h"

int	ft_isalnum(int ch)
{
	if (ch < 0 || ch > 255)
		return (0);
	else if (((unsigned char)ch >= '0' && (unsigned char)ch <= '9') ||
			((unsigned char)ch >= 'A' && (unsigned char)ch <= 'Z') ||
			((unsigned char)ch >= 'a' && (unsigned char)ch <= 'z'))
		return (1);
	else
		return (0);
}
