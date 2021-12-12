/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 04:22:54 by pjerddee          #+#    #+#             */
/*   Updated: 2021/12/12 00:08:10 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
char	*ft_itoa(unsigned int num, char *str);
char	*ft_strrev(char *str, int str_len);
int		is_printable(char c);
int		is_space(char c);

char	*ft_itoa(unsigned int num, char *str)
{
	int				i;
	unsigned int	rem;

	i = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num != 0)
	{
		rem = num % 10;
		if (rem > 9)
			str[i++] = (rem - 10) + 'a';
		else
			str[i++] = rem + '0';
		num = num / 10;
	}
	str[i] = '\0';
	ft_strrev(str, i);
	return (str);
}

char	*ft_strrev(char *str, int str_len)
{
	int		i;
	char	temp;

	i = 0;
	while (i < str_len / 2)
	{
		temp = str[str_len - i - 1];
		str[str_len - i - 1] = str[i];
		str[i] = temp;
		i++;
	}
	return (str);
}

int	is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}
