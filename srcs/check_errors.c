/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:16:28 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/07 10:48:18 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_format(char *arg)
{
	while (*arg)
	{
		if (*arg == '.')
			return (ft_strcmp((const char*)&(*arg), ".fdf") == 0 ? 1 : 0);
		arg++;
	}
	return (0);
}

int		check_min_size(t_base *base)
{
	if (base->height < 2 || base->width < 2)
		return (0);
	return (1);
}

int		check_parsing(int ret)
{
	if (ret == 0)
	{
		ft_putstr("Please check input in file\n");
		return (0);
	}
	else if (ret == -1)
	{
		ft_putstr("The file can't be read, please check again!\n");
		return (0);
	}
	return (1);
}

int		check_global(int ret, t_base *base)
{
	if (check_parsing(ret) == 0)
		return (0);
	if (check_min_size(base) == 0)
	{
		ft_putstr("File must be a minimum size of 2*2\n");
		return (0);
	}
	return (1);
}
