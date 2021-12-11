/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:39:02 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/11 03:58:29 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define BUFF_SIZE 4096;

void	ft_putstr(char *str);

int	read_files(char *file, char *buff, int buff_size);

int	main(int argc, char **argv)
{
	char	*buff;

	buff = malloc(BUFF_SIZE * sizeof(char));
	if (argc == 2)
	{
		if (read_files("numbers.dict", buff, BUFF_SIZE))
			convert(c, argv[1]);
		else
			ft_putstr("Error\n");
	}
	if (argc == 3)
	{
		if (read_files(argv[1], buff, BUFF_SIZE))
			convert(c, argv[2]);
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error Invalid Arguments : Input must be 1 or 2 argument");
	return (0);
}
