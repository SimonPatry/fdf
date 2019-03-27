/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 10:42:28 by sipatry           #+#    #+#             */
/*   Updated: 2019/02/07 16:19:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_env(t_base *base)
{
	base->xwin = 2400;
	base->ywin = 1300;
	base->z = 1;
	base->sw = 0;
	base->c = 0;
	base->mvx = 0;
	base->mvy = 0;
	base->zm = 1;
}

int		main(int ac, char **av)
{
	int		fd;
	t_base	base;
	int		ret;

	ret = 1;
	if (ac != 2 || check_format(av[1]) != 1)
	{
		ft_putstr("Please check file entered (just one file with .fdf ext)\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	set_env(&base);
	ret = parsing(fd, &base);
	if (check_global(ret, &base) == 0)
		return (0);
	display_hud();
	trace_map(&base);
	close(fd);
	return (0);
}
