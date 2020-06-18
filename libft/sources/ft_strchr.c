#include "libft.h"

char	*ft_strchr(const char *src, int symbol)
{
	size_t	i;

	i = 0;
	if (symbol < 0 || symbol > 255)
		return (NULL);
	while (src[i])
	{
		if (src[i] == (unsigned char)symbol)
			return ((char*)(src + i));
		i++;
	}
	if (symbol == '\0' && src[i] == symbol)
		return ((char*)(src + i));
	return (NULL);
}
