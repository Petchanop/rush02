/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:44:11 by pjerddee          #+#    #+#             */
/*   Updated: 2021/12/12 14:40:42 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				is_num(char c);
int				chk_validity(char *str);
void			ft_putstr(char *str);
unsigned int	ft_atoi(char *str);

int	chk_validity(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0')
	{
		ft_putstr("Input Error : Input must not begin with '0'");
		return (0);
	}
	while (str[i])
	{
		if (!is_num(str[i]))
		{
			ft_putstr("Input Error : Your Input must be number");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

unsigned int	ft_atoi(char *str)
{
	unsigned int	val;
	int				i;

	val = 0;
	i = 0;
	while (str[i])
	{
		val = (val * 10) + (str[i] - '0');
		i++;
	}
	return (val);
}

int	is_num(char c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}
