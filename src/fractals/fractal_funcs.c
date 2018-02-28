/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:00:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 19:00:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			psycho_func(void *param)
{
	static int	p = 0;
	t_data		*data;

	data = param;
	if (data->psycho)
	{
		if (p > 100)
		{
			data->palette[0].frequence += 0.05;
			data->palette[1].phase += 0.05;
			data->palette[2].delta += 1;
			data->palette[2].frequence += 0.002;
		}
		else
		{
			data->palette[0].frequence += 0.001;
			data->palette[0].phase += 0.05;
			data->palette[1].delta += 1;
			data->palette[1].frequence += 0.01;
		}
		p = (p + 1) % 200;
		render_screen(data);
	}
	return (0);
}

void		draw_point(t_data *data, int x, int y)
{
	t_complex	start_num;
	unsigned	escape_iterations;

	start_num.real = data->left_corner.real + x * data->step.real;
	start_num.imag = data->left_corner.imag + y * data->step.imag;
	escape_iterations = data->draw_func(data, &start_num);
	if (escape_iterations != data->iterations)
		PUT_PIXEL(data->img_data->img, x, y,
				data->img_data->s,
				get_color(data, escape_iterations, start_num));
}

void		draw_loop(t_threads_data *threads_data)
{
	t_data			*data;
	int				row_idx;
	int				col_idx;

	row_idx = threads_data->start;
	data = threads_data->data;
	while (row_idx < threads_data->end)
	{
		col_idx = 0;
		while (col_idx < WIN_W)
			draw_point(data, col_idx++, row_idx);
		row_idx++;
	}
}
