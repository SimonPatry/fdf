/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:58:09 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/13 16:39:25 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	resize_fdf(t_base *base, t_margin *margins, t_place *resize)
{
	while (resize->dx > base->xwin || resize->dy > base->ywin)
	{
		margins->size = (margins->size * 99) / 100;
		if (base->sw == 0)
			replace_first_point(*base, margins, resize);
		else
			replace_first_point_para(*base, margins, resize);
	}
}

void	line_size(t_base *base, t_margin *margins, t_place *resize)
{
	margins->y = base->ywin / (base->height + 2);
	margins->x = base->xwin / (base->width + 2);
	if (margins->x < margins->y)
	{
		margins->size = margins->x * base->zm;
		margins->y = (base->ywin - ((base->height - 1) * margins->size)) / 2;
	}
	else
	{
		margins->size = margins->y * base->zm;
		margins->x = (base->xwin - ((base->width - 1) * margins->size)) / 2;
	}
	if (base->sw == 0)
		replace_first_point(*base, margins, resize);
	else
		replace_first_point_para(*base, margins, resize);
	if (base->zm <= 1)
		resize_fdf(base, margins, resize);
	margins->x = (base->xwin - resize->dx) / 2;
	margins->y = (base->ywin - resize->dy) / 2;
	margins->x1 = margins->x + (resize->x1 - resize->x4);
	margins->y1 = margins->y;
}

void	trace_x(t_base base, t_margin margins, t_mlx mlx)
{
	t_trace	lines;

	base.y = 0;
	lines.y1 = 0;
	while (base.y < base.height)
	{
		lines.x1 = 0;
		base.x = 0;
		lines.y2 = lines.y1;
		while (base.x < base.width - 1)
		{
			lines.x2 = lines.x1 + margins.size;
			base.tx = base.x + 1;
			base.ty = base.y;
			trace_line(base, &lines, mlx);
			lines.x1 += margins.size;
			base.x += 1;
		}
		lines.y1 += margins.size;
		base.y += 1;
	}
}

void	trace_y(t_base base, t_margin margins, t_mlx mlx)
{
	t_trace		lines;

	base.x = 0;
	lines.x1 = 0;
	while (base.x < base.width)
	{
		lines.y1 = 0;
		base.y = 0;
		lines.x2 = lines.x1;
		while (base.y < base.height - 1)
		{
			lines.y2 = lines.y1 + margins.size;
			base.tx = base.x;
			base.ty = base.y + 1;
			trace_line(base, &lines, mlx);
			lines.y1 += margins.size;
			base.y += 1;
		}
		lines.x1 += margins.size;
		base.x += 1;
	}
}

int		trace_map(t_base *base)
{
	t_margin	margins;
	t_place		resize;
	t_mlx		mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, base->xwin, base->ywin, "FdF");
	line_size(base, &margins, &resize);
	center(base, &resize);
	base->img_ptr = mlx_new_image(mlx.mlx_ptr, base->xwin, base->ywin);
	base->str = (unsigned int*)mlx_get_data_addr(base->img_ptr,
	&(mlx.bits_per_pixels), &(mlx.size_line), &(mlx.edian));
	trace_x(*base, margins, mlx);
	trace_y(*base, margins, mlx);
	trace_c_x(base, mlx);
	trace_c_y(base, mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, base->img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 17, 0, close_w, (void *)0);
	mlx_key_hook(mlx.win_ptr, key_hook, base);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
