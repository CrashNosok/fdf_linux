#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char*)dest;
	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		ptr[i] = src[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
