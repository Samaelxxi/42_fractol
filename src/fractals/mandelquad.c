/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 16:06:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 16:06:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mandelquad(t_data *data)
{
	data->draw_func = mandelquad;
	set_complex(&data->left_corner, -1.7, -1.5);
	set_complex(&data->right_corner, 1.3, 1.5);
	update_step(data);
}

unsigned	mandelquad(t_data *data, t_complex *start_num)
{
	t_complex	num;
	t_complex	num_squared;
	double		tmp;
	unsigned	iteration;

	set_complex(&num, start_num->real, start_num->imag);
	iteration = 0;
	while (iteration < data->iterations)
	{
		set_complex(&num_squared, num.real * num.real, num.imag * num.imag);
		if (num_squared.real + num_squared.imag > 4)
		{
			set_complex(start_num, num.real, num.imag);
			return (iteration);
		}
		tmp = (pow(num.real, 4) - num_squared.imag * num_squared.real * 6
			+ pow(num.imag, 4)) + start_num->real;
		num.imag = (num_squared.real * num.real * num.imag * 3
			- 4 * num.real * num_squared.imag * num.imag) + start_num->imag;
		num.real = tmp;
		iteration++;
	}
	return (iteration);
}
