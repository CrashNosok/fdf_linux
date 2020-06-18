#include "libft.h"

char*ft_strdup(const char *src)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
