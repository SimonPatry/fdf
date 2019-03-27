/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:08:51 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/14 18:31:50 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	replace_first_point(t_base base, t_margin *margins, t_place *resize)
{
	resize->x = 0;
	resize->y = 0;
	resize->x1 = resize->x;
	resize->y1 = resize->y;
	resize->x2 = ((resize->x + ((base.width - 1) * margins->size))
	- resize->y) * cos(0.523599);
	resize->y2 = ((resize->x + ((base.width - 1) * margins->size))
	+ resize->y) * sin(0.523599);
	resize->x3 = (((resize->x + (((base.width - 1) *
	margins->size))) - (resize->y + ((base.height - 1)
	* margins->size))) * cos(0.523599));
	resize->y3 = (((resize->x + (((base.width - 1) *
	margins->size))) + (resize->y + ((base.height - 1)
	* margins->size))) * sin(0.523599));
	resize->x4 = ((resize->x - (((base.height - 1) *
	margins->size) + resize->y)) * cos(0.523599));
	resize->y4 = ((resize->x + (((base.height - 1) *
	margins->size) + resize->y)) * sin(0.523599));
	resize->dx = resize->x2 - resize->x4;
	resize->dy = resize->y3 - resize->y1;
}

void	replace_first_point_para(t_base base, t_margin *margins,
		t_place *resize)
{
	resize->x = 0;
	resize->y = 0;
	resize->x1 = resize->x;
	resize->y1 = resize->y;
	resize->x2 = ((resize->x + ((base.width - 1) * margins->size))
	- resize->y);
	resize->y2 = resize->y1;
	resize->x3 = ((resize->x + (((base.width - 1) *
	margins->size))) - (resize->y + ((base.height - 1)
	* margins->size)));
	resize->y3 = (resize->y + ((base.height - 1) * margins->size));
	resize->x4 = (resize->x - (((base.height - 1) * margins->size)
	+ resize->y));
	resize->y4 = resize->y3;
	resize->dx = resize->x2 - resize->x4;
	resize->dy = (resize->y3);
}

void	trace_para(t_pos *p, t_base base)
{
	int prev_x1;
	int prev_y1;
	int prev_x2;
	int prev_y2;

	prev_x1 = p->x1;
	prev_y1 = p->y1;
	p->x1 = (prev_x1 - prev_y1);
	p->y1 = -(base.z * base.map[base.y][base.x]) + prev_y1;
	prev_x2 = p->x2;
	prev_y2 = p->y2;
	p->x2 = (prev_x2 - prev_y2);
	p->y2 = -(base.z * base.map[base.ty][base.tx]) + prev_y2;
}

void	trace_iso(t_pos *p, t_base base)
{
	int prev_x1;
	int prev_y1;
	int prev_x2;
	int prev_y2;

	prev_x1 = p->x1;
	prev_y1 = p->y1;
	p->x1 = (prev_x1 - prev_y1) * cos(0.523599);
	p->y1 = -(base.z * base.map[base.y][base.x] / 4)
		+ (prev_x1 + prev_y1) * sin(0.523599);
	prev_x2 = p->x2;
	prev_y2 = p->y2;
	p->x2 = (prev_x2 - prev_y2) * cos(0.523599);
	p->y2 = -(base.z * base.map[base.ty][base.tx] / 4)
		+ (prev_x2 + prev_y2) * sin(0.523599);
}

void	trace_selector(t_pos *p, t_base base)
{
	if (base.sw == 0)
		trace_iso(p, base);
	else
		trace_para(p, base);
}
