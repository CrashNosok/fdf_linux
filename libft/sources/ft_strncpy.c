#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (!src[i])
			break ;
		dest[i] = src[i];
		i++;
	}
	while (i < num)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
