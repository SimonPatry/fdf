/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:49:02 by sipatry           #+#    #+#             */
/*   Updated: 2019/02/07 16:19:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	calcul_height(char *str)
{
	int	i;
	int	height;

	height = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			height++;
	}
	if (str[i - 1] != '\n' && str[i] == '\0')
		height++;
	return (height);
}

int	calcul_width(char *str)
{
	int i;
	int width;

	width = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != ' ')
		{
			width++;
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (width);
}
