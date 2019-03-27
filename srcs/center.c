/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:26:45 by lcordeno          #+#    #+#             */
/*   Updated: 2019/02/07 10:46:01 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		trace_c_x(t_base *base, t_mlx mlx)
{
	int x1;
	int y1;
	int x2;

	x1 = -1;
	y1 = base->ywin / 2;
	x2 = base->xwin;
	if (base->c == 1)
	{
		while (++x1 < x2)
			base->str[(x1) + ((y1) * base->xwin)] = 0xFFFFFF;
	}
	return (0);
}

int		trace_c_y(t_base *base, t_mlx mlx)
{
	int x1;
	int y1;
	int y2;
	int i;

	x1 = base->xwin / 2;
	y1 = -1;
	y2 = base->ywin;
	if (base->c == 1)
	{
		while (++y1 < y2)
			base->str[(x1) + ((y1) * base->xwin)] = 0xFFFFFF;
	}
	return (0);
}

void	center(t_base *base, t_place *resize)
{
	if (base->sw == 0)
	{
		base->center_x = ((base->xwin / 2) - ((resize->x1 + resize->x3) / 2)
		+ base->mvx);
		base->center_y = ((base->ywin / 2) - ((resize->y2 + resize->y4) / 2)
		+ base->mvy);
	}
	else
	{
		base->center_x = ((base->xwin / 2) - ((resize->x1 + resize->x3) / 2)
		+ base->mvx);
		base->center_y = ((base->ywin / 2) - ((resize->y4 + resize->y1) / 2)
		+ base->mvy);
	}
}
