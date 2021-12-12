#include <stdio.h>
#include <stdlib.h>

int	ft_len(char *c)
{
	int	len;

	len = 0;
	while (c[len])
		len++;
	return (len);
}

int	ft_pow(int power)
{
	if (power > 1)
		return (10 * ft_pow(--power));
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (10);
	else
		return (0);
}

unsigned int	*topow(char *c, int len)
{
	unsigned int	*arr;
	int				i;

	arr = malloc(len * sizeof(unsigned int));
	i = 0;
	while (c[i])
	{
		if (len >= 4)
			arr[i++] = 1 * ft_pow(--len % 3);
		else
			arr[i++] = 1 * ft_pow(--len);
	}
	arr[i] = '\0';
	return (arr);
}

unsigned int	*todict(char *c, int len)
{
	unsigned int	*arr;
	int				i;

	arr = malloc(len * sizeof(unsigned int));
	i = 0;
	while (c[i])
	{
		arr[i] = (c[i] - '0');
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

/*int	main(int argc, char **argv)
{
	int				len;
	unsigned int	*arr;
	unsigned int	*powr;

	if (argc == 2)
	{
		len = ft_len(argv[1]);
		arr = todict(argv[1], len);
		powr = topow(argv[1], len);
		while (*arr)
		{
			printf("%d ", *arr);
			arr++;
		}
		printf("\n");
		while (*powr)
		{
			printf("%d ", *powr);
			powr++;
		}
		printf("\n");
	}
}*/
