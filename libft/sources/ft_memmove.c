#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned char*)src;
	if (dest_ptr == src_ptr)
		return (dest);
	else if (src_ptr < dest_ptr)
	{
		src_ptr = (unsigned char*)src + num - 1;
		dest_ptr = dest + num - 1;
		while (num--)
			*dest_ptr-- = *src_ptr--;
	}
	else
	{
		while (num--)
			*dest_ptr++ = *src_ptr++;
	}
	return (dest);
}
