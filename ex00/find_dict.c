/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:21:45 by pjerddee          #+#    #+#             */
/*   Updated: 2021/12/12 14:33:46 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "map_dict.h"
#include <stdlib.h>
#include "ft_string.h"
#include <stdio.h>

void	ft_putstr(char *str);
void	convert(char *dict, char *num);
char	*ft_itoa(unsigned int num, char *str);
void	tens_dealing(char *num, char *dict);
void	print_digit(char *dict, char *num);
void		ext_word(char *dict, char *to_find);
int		is_space(char c);
int		is_printable(char c);
int		is_num(char c);

void	ext_word(char *dict, char *to_find)
{
	char	*pword;
	char	word[100];
	int		i;

	pword = &word[0];
	pword = ft_strstr(dict, to_find);
	if (ft_strcmp(pword, "n"))
	{
		i = 0;
		while (*(pword + i) != ' ')
			i++;
		i++;
		while (*(pword + i) != '\n')
		{
			word[i] = *(pword + i);
			write(1, &word[i], 1);
			i++;
		}
		write(1, " ", 1);
	}
	else
		ft_putstr("Dict error\n");
}

void	convert(char *dict, char *num)
{
	t_dict	*map;
	int		str_len;
	int		i;
	int		j;

	map = malloc(12 * sizeof(dict));
	map_dict(map);
	str_len = ft_strlen(num);
	i = 0;
	while (str_len > 0)
	{
		if (!ft_strcmp(num, "0"))
		{
			ext_word(dict, "0");
			break ;
		}
		if (str_len == 1 && *(num + i) != '0')
			print_digit(dict, num + i);
		else if (str_len == 2 && *(num + i) != '0')
		{
			tens_dealing(num + i, dict);
			if (num[i] == '1' || (num[i] > '1' && num[i + 1] == '0'))
				break ;
		}
		else if ((str_len - 4) % 3 == 0)
		{
			if (*(num + i) != '0')
				print_digit(dict, num + i);
			j = 0;
			if (*(num + i - 1) != '0' || *(num + i - 2) != '0')
			{
				while (j < 12)
				{	
					if (str_len == map[j].digit)
					{
						ext_word(dict, map[j].ref);
						break ;
					}
					j++;
				}
			}
		}
		else if ((str_len - 4) % 3 == 1 && *(num + i) != '0')
		{
			tens_dealing(num + i, dict);
			if (num[i] == '1')
				num[i + 1] = '0';
		}
		else if ((str_len == 3 || (str_len - 4) % 3 == 2) && *(num + i) != '0')
		{
			print_digit(dict, num + i);
			ext_word(dict, "100");
		}
		str_len--;
		i++;
	}
}

void	tens_dealing(char *num, char *dict)
{
	char	buff[3];

	buff[0] = *num;
	buff[2] = '\0';
	if (*num > '1')
		buff[1] = '0';
	else
		buff[1] = *(num + 1);
	ext_word(dict, buff);
}

void	print_digit(char *dict, char *num)
{
	char	buff[2];

	buff[0] = *num;
	buff[1] = '\0';
	ext_word(dict, buff);
}
