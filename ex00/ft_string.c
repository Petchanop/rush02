/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjerddee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 23:57:50 by pjerddee          #+#    #+#             */
/*   Updated: 2021/12/12 05:23:50 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

int		ft_strlen(char *num);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	ft_strlen(char *num)
{
	int	str_len;

	str_len = 0;
	while (num[str_len] != 0)
		str_len++;
	return (str_len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != 0 || *(s2 + i) != 0)
	{
		if (*(s1 + i) > *(s2 + i))
			return (1);
		else if (*(s1 + i) < *(s2 + i))
			return (-1);
		else
			i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
//	write(1, "\n", 1);
	while (str[i] != '\0')
	{
		if (*(to_find) == *(str + i))
		{
			j = 0;
			while (to_find[j] != 0)
			{
				if (to_find[j] != str[i + j])
					break ;
				else
					j++;
			}
			if (to_find[j] == 0 && str[i + j] == ':')
				return (str + i);
		}
		i++;
	}
	return ("n");
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = 0;
	while (dest[dest_len] != 0)
		dest_len++;
	while (src[i] != 0)
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dest_length;

	i = 0;
	dest_length = 0;
	while (dest[dest_length] != 0)
		dest_length++;
	while (i < nb && src[i] != 0)
	{
		*(dest + dest_length + i) = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}
