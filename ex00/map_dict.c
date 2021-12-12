/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:14:35 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/12 15:38:52 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include "map_dict.h"
#include "ft_string.h"

void	map_dict(t_dict *map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i <= 36)
	{
		if (i % 3 == 0 && i != 0)
		{
			map[j].digit = i + 1;
			map[j].ref = malloc((37) * sizeof(char));
			ft_strcpy(map[j].ref, "1");
			k = i / 3;
			while (k--)
				ft_strncat(map[j].ref, "000", 4);
			j++;
		}
		i++;
	}
}	
/*
int	main(void)
{
	t_dict	*map;

	map = malloc(12 * sizeof(t_dict));
	map_dict(map);
	for (int i = 0 ; i < 12; i++)
	{
		printf("%d : %s\n",map[i].digit, map[i].ref);
	}
	
	printf("Some thing\n");
	return (0);
}*/
