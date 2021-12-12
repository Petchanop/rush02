/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:39:02 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/12 15:09:28 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include"map_dict.h"
#define BUFF_SIZE 4096

unsigned int	ft_atoi(char *str);
int			convert(char *dict, char *to_find);
void			ft_putstr(char *str);
int				ext_word(char *dict, unsigned int to_find);
int				read_files(char *file, char *buff, char *pf, int buff_size);
int				chk_validity(char * str);

int	main(int argc, char **argv)
{
	char	*buff;
	char	*pf;

	buff = malloc(BUFF_SIZE * sizeof(char));
	pf = malloc(BUFF_SIZE * sizeof(char));
	if (argc == 2)
	{
		if (read_files("numbers.dict", buff, pf, BUFF_SIZE) != -1 && chk_validity(argv[1]))
			return  (convert(pf, argv[1]));
	}
	else if (argc == 3)
	{
		if (read_files(argv[1], buff, pf, BUFF_SIZE) != -1 && chk_validity(argv[2]))
			return (convert(pf, argv[2]));
	}
	else
		ft_putstr("Error Invalid Arguments : Input must be 1 or 2 argument");
	return (0);
}
