#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char*)destination;
	while (i < n)
	{
		*(ptr + i) = (unsigned char)c;
		i++;
	}
	return (destination);
}
