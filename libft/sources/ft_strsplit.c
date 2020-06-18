#include "libft.h"

static char		*ft_cut(const char *str, char c)
{
	size_t	len;
	size_t	j;
	char	*new_str;

	len = 0;
	j = 0;
	while (str[len] != c && str[len])
		len++;
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	while (str[j] != c && str[j])
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static int		ft_miss_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static size_t	ft_arrlen(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i += ft_miss_word(s + i, c) - 1;
		}
		i++;
	}
	return (count);
}

static void		ft_rmarr(char **arr, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
		free(arr[i]);
	free(arr);
	arr = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	word;
	char	**arr;

	if (!s)
		return (NULL);
	i = 0;
	word = 0;
	if (!(arr = (char**)ft_memalloc(sizeof(char**) * (ft_arrlen(s, c) + 1))))
		return (NULL);
	while (i < ft_arrlen(s, c))
	{
		while (s[word] == c && s[word])
			word++;
		if (!(arr[i] = ft_cut(s + word, c)))
		{
			ft_rmarr(arr, i);
			i = ft_arrlen(s, c);
		}
		word += ft_miss_word(s + word, c);
		i++;
	}
	if (i == ft_arrlen(s, c))
		arr[i] = NULL;
	return (arr);
}
