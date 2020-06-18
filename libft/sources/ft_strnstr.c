#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	int			i;
	int			j;
	int			size;

	i = 0;
	size = ft_strlen(str1) - ft_strlen(str2);
	if (size < 0)
		return (NULL);
	while (i < (size + 1))
	{
		j = 0;
		while ((str1[i] == str2[j]) && str2[j] && (size_t)i < len)
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return ((char*)(str1 + i - ft_strlen(str2)));
		i -= j - 1;
	}
	return (NULL);
}
