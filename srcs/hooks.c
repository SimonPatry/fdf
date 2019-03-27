/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:36:04 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/14 18:28:01 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	proj_switch(t_base *base)
{
	if (base->sw == 0)
		base->sw = 1;
	else
		base->sw = 0;
	trace_map(base);
}

void	display_center(t_base *base)
{
	if (base->c == 0)
		base->c = 1;
	else
		base->c = 0;
	trace_map(base);
}

void	reset(t_base *base)
{
	base->mvx = 0;
	base->mvy = 0;
	base->c = 0;
	base->zm = 1;
	base->z = 1;
	trace_map(base);
}

int		key_hook(int key, t_base *base)
{
	if (key == 53)
		exit(1);
	if (key == 35)
		proj_switch(base);
	if (key == 8)
		display_center(base);
	if (key >= 123 && key <= 126)
		move(key, base);
	if (key == 15)
		reset(base);
	if (key == 78 || key == 69)
		zoom(key, base);
	if (key == 88 || key == 92)
		change_z(key, base);
	return (0);
}

int		close_w(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
