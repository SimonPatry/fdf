/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:59:04 by lcordeno          #+#    #+#             */
/*   Updated: 2019/03/14 18:28:16 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	display_hud(void)
{
	ft_putstr("****************************\n");
	ft_putstr("*       Hello friend!      *\n");
	ft_putstr("*       ------------       *\n");
	ft_putstr("*                          *\n");
	ft_putstr("*     --KEY BINDINGS--     *\n");
	ft_putstr("*                          *\n");
	ft_putstr("*  c = display center      *\n");
	ft_putstr("*  p = switch projection   *\n");
	ft_putstr("*  r = reset               *\n");
	ft_putstr("*  esc = quit              *\n");
	ft_putstr("*                          *\n");
	ft_putstr("*          -Zoom-          *\n");
	ft_putstr("*                          *\n");
	ft_putstr("*  + = zoom in             *\n");
	ft_putstr("*  - = zoom out            *\n");
	ft_putstr("*                          *\n");
	ft_putstr("*          -Move-          *\n*                          *\n");
	ft_putstr("*  Use arrows <-^->        *\n");
	ft_putstr("*                          *\n");
	ft_putstr("*         -Height-         *\n*                          *\n");
	ft_putstr("*  6 = increase            *\n");
	ft_putstr("*  9 = decrease            *\n");
	ft_putstr("*                          *\n");
	ft_putstr("****************************\n");
	ft_putstr("\nDesigned by sipatry and lcordeno @ 42 Paris\n");
}
