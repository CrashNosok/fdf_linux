#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return ;
	i = 0;
	ptr = s;
	while (s[i])
		ptr[i++] = '\0';
}
