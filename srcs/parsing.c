/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:00:07 by sipatry           #+#    #+#             */
/*   Updated: 2019/03/18 14:30:16 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		new_string(char *str, int *i)
{
	int		k;
	int		l;
	char	*new;
	int		nb;
	int		j;

	j = *i;
	k = 0;
	l = j;
	while (str[l] != ' ' && str[l] != '\n' && str[l])
		l++;
	if (!(new = (char *)malloc(sizeof(char) * ((l - j) + 1))))
		return (0);
	while (j < l)
	{
		new[k] = str[j];
		k++;
		j++;
	}
	*i = j;
	new[k] = '\0';
	nb = ft_atoi(new);
	free(new);
	return (nb);
}

int		create_map(char *str, t_base *base)
{
	int	i;

	i = 0;
	base->xx = 0;
	base->yy = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
		{
			base->map[base->xx][base->yy] = new_string(str, &i);
			base->yy += 1;
		}
		while ((str[i] == ' ') && str[i])
			i++;
		if (str[i] == '\n')
		{
			if (base->yy != base->width)
				return (0);
			base->yy = 0;
			base->xx += 1;
			i++;
		}
	}
	base->map[base->xx][base->yy] = 0;
	return (1);
}

int		fill_base(char *str, t_base *base)
{
	int	i;

	i = 0;
	base->height = calcul_height(str);
	base->width = calcul_width(str);
	if (!(base->map = (int **)malloc(sizeof(int *) * (base->height + 1))))
		return (0);
	while (i <= base->height)
	{
		if (!(base->map[i] = (int *)malloc(sizeof(int) * (base->width))))
			return (0);
		i++;
	}
	if (!create_map(str, base))
		return (0);
	return (1);
}

int		parsing(int fd, t_base *base)
{
	int		ret;
	char	*tmp;
	char	buff[4097];
	char	*str;

	ret = 0;
	if (fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	str = ft_strnew(1);
	while ((ret = read(fd, buff, 4096)))
	{
		buff[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
		free(tmp);
	}
	if (!fill_base(str, base))
	{
		free(str);
		return (0);
	}
	free(str);
	str = NULL;
	return (1);
}
