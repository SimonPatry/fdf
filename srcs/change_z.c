/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:21:59 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/14 18:27:45 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	inc_z(t_base *base)
{
	base->z += 1;
	trace_map(base);
}

void	dec_z(t_base *base)
{
	base->z -= 1;
	trace_map(base);
}

void	change_z(int key, t_base *base)
{
	if (key == 88)
		inc_z(base);
	if (key == 92)
		dec_z(base);
}
