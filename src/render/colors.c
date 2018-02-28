/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:49:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/05 14:49:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_colorset2(t_data *data)
{
	t_color_attrs *color;

	color = &(data->palette[0]);
	color->center = 150;
	color->delta = 10;
	color->frequence = 0.2;
	color->phase = 0.01;
	color = &(data->palette[1]);
	color->center = 110;
	color->delta = 20;
	color->frequence = 0.02;
	color->phase = 0;
	color = &(data->palette[2]);
	color->center = 150;
	color->delta = 10;
	color->frequence = 0.05;
	color->phase = 0.05;
}

void		init_colorset1(t_data *data)
{
	t_color_attrs *color;

	color = &(data->palette[0]);
	color->center = 255;
	color->delta = 55;
	color->frequence = 0;
	color->phase = 0;
	color = &(data->palette[1]);
	color->center = 200;
	color->delta = 1;
	color->frequence = 0.09;
	color->phase = 0;
	color = &(data->palette[2]);
	color->center = 100;
	color->delta = 10;
	color->frequence = 0.05;
	color->phase = 0.05;
}

void		init_colorset3(t_data *data)
{
	t_color_attrs *color;

	color = &(data->palette[0]);
	color->center = 778;
	color->delta = 55;
	color->frequence = 0.1;
	color->phase = 0.1;
	color = &(data->palette[1]);
	color->center = 489;
	color->delta = 1;
	color->frequence = 0.1;
	color->phase = 0.035208;
	color = &(data->palette[2]);
	color->center = 249;
	color->delta = 5;
	color->frequence = 0.09;
	color->phase = 0.038143;
}

int			get_color(t_data *data, unsigned iterations, t_complex num)
{
	double	r;
	double	m;
	int		res;

	r = complex_magnitude(num);
	m = iterations + 1 - (log(log(r)) / log(2.0));
	res = 0;
	res += (unsigned char)(sin(data->palette[0].frequence * m +
							data->palette[0].phase)
						* data->palette[0].center + data->palette[0].delta);
	res += ((unsigned char)(sin(data->palette[1].frequence * m +
							data->palette[1].phase)
				* data->palette[1].center + data->palette[1].delta)) << 8;
	res += ((unsigned char)(sin(data->palette[2].frequence * m +
							data->palette[2].phase)
				* data->palette[2].center + data->palette[2].delta)) << 16;
	return (res);
}
