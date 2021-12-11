/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:44:11 by pjerddee          #+#    #+#             */
/*   Updated: 2021/12/11 04:14:32 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int				chk_validity(char *str);
void			ft_putstr(char *str);
char			*ft_strstr(char *str, char *to_find);
unsigned int	ft_atoi(char *str);

int	chk_validity(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != 0)
	{
		if (*(to_find) == *(str + i))
		{
			j = 0;
			while (to_find[j] != 0)
			{
				if (to_find[j] != str[i +j])
					break ;
				else
					j++;
			}
			if (to_find[j] == 0)
				return (str + i);
		}
		i++;
	}
	return (NULL);
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
