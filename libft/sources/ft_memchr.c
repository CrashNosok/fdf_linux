#include "libft.h"

void	*ft_memchr(const void *src, int val, size_t num)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char*)src;
	while (i < num)
	{
		if (ptr[i] == (unsigned char)val)
			return ((void*)src + i);
		i++;
	}
	return (NULL);
}
