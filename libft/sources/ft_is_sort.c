int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int k;
	int j;
	int count;

	i = 0;
	k = 0;
	j = 0;
	count = 0;
	if (length == 0 || length == 1)
		return (1);
	while (count < length - 1)
	{
		if (f(tab[count], tab[count + 1]) < 0)
			i++;
		else if (f(tab[count], tab[count + 1]) > 0)
			j++;
		else
			k++;
		count++;
	}
	if (i + k == length - 1 || j + k == length - 1)
		return (1);
	else
		return (0);
}
