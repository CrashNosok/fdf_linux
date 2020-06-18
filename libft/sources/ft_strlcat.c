#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t num)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dest[len] && len < num)
		len++;
	i = len;
	while (src[len - i] && len + 1 < num)
	{
		dest[len] = src[len - i];
		len++;
	}
	if (i < num)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}
