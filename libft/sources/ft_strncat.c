#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = dest;
	i = ft_strlen(dest);
	j = 0;
	while (src[j] && j < n)
	{
		ptr[i] = src[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
