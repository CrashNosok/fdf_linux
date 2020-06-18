#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (s && f)
	{
		i = 0;
		len = ft_strlen((char*)s);
		ptr = (char*)malloc(len * sizeof(*ptr) + 1);
		if (!ptr)
			return (NULL);
		while (s[i])
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
