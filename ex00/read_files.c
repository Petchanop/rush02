/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:59:46 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/12 17:18:39 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include"ft_utility.h"

int		is_num(char c);
int		is_colon(char c);
int		is_printable(char c);
int		check_input(char *buff);

void	formatt_input(char *buff, char *pf);

int	read_files(char *file, char *buff, char *pf, int buff_size)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error : Cannot open file!!\n");
		ft_putstr("Make sure your dict file in this folder and 2nd input must be number\n");
		return (-1);
	}
	read(fd, buff, buff_size);
	if (!check_input(buff))
		return (-1);
	formatt_input(buff, pf);
	return (1);
}

void	formatt_input(char *buff, char *pf)
{
	int	i;

	*pf = *buff;
	i = 0;
	while (*buff)
	{
		while (is_num(*buff))
			pf[i++] = *(buff++);
		while (*buff == ':')
			pf[i++] = *(buff++);
		while (is_printable(*buff))
		{
			if (*buff != ' '
				|| (*buff == ' ' && *(buff - 1) != ' '))
				pf[i++] = *buff;
			buff++;
		}
		pf[i++] = '\n';
		buff++;
	}
	pf[i] = '\0';
}

int	check_input(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ':')
			i = 1;
		if ((!is_num(*str) && *str != ' ') && i == 0 )
		{	
			ft_putstr("Invalid Files : Wrong Dict format\n");
			ft_putstr("Your format must be : ");
			ft_putstr("[a number][0 to n spaces]:[0 to n spaces][any printable characters]\n"); 
			return (0);
		}
		if (*str == '\n')
			i = 0;
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*buff;
	char	*pf;

	buff = malloc(4096 * sizeof(char));
	pf = malloc(4096 * sizeof(char));
	if (read_files("numbers.dict", buff, pf, 4096) != -1)
		printf("%s\n",pf);
	return (0);
}*/
