/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:56:37 by npiya-is          #+#    #+#             */
/*   Updated: 2021/12/12 02:49:44 by pjerddee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DICT_H
# define MAP_DICT_H

typedef struct s_dict
{
	int		digit;
	char	*ref;
}		t_dict;

void	map_dict(t_dict *map);

#endif
