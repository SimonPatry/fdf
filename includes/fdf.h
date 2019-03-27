/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:06:05 by sipatry           #+#    #+#             */
/*   Updated: 2019/02/07 18:38:43 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef	struct		s_base
{
	int				**map;
	int				width;
	int				height;
	int				xwin;
	int				ywin;
	int				center_x;
	int				center_y;
	int				z;
	int				x;
	int				y;
	int				tx;
	int				ty;
	void			*img_ptr;
	unsigned int	*str;
	int				sw;
	int				c;
	int				mvx;
	int				mvy;
	int				zm;
	int				xx;
	int				yy;

}					t_base;

typedef struct		s_margin
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				size;
}					t_margin;

typedef struct		s_trace
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
}					t_trace;

typedef struct		s_place
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				x3;
	int				y3;
	int				x4;
	int				y4;
	int				dx;
	int				dy;
}					t_place;

typedef struct		s_pos
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_pos;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				bits_per_pixels;
	int				size_line;
	int				edian;
}					t_mlx;

int					check_format(char *arg);
int					check_input(int **map);
void				trace_line(t_base base, t_trace *lines, t_mlx mlx);
void				trace_iso(t_pos *p, t_base base);
void				trace_para(t_pos *p, t_base base);
int					parsing(int fd, t_base *base);
int					trace_map(t_base *base);
void				replace_first_point(t_base base, t_margin *margins,
					t_place *resize);
void				replace_first_point_para(t_base base, t_margin *margins,
					t_place *resize);
void				center(t_base *base, t_place *resize);
int					trace_c_x(t_base *base, t_mlx mlx);
int					trace_c_y(t_base *base, t_mlx mlx);
void				move(int key, t_base *base);
void				zoom(int key, t_base *base);
int					key_hook(int key, t_base *base);
int					close_w(void *param);
int					key_press(int key, t_base *base);
void				change_z(int key, t_base *base);
int					color(t_base base, int y, int x);
int					check_global(int ret, t_base *base);
void				display_hud(void);
void				trace_selector(t_pos *p, t_base base);
int					calcul_height(char	*str);
int					calcul_width(char *str);
int					create_map(char *str, t_base *base);
int					new_string(char	*str, int *i);

#endif
