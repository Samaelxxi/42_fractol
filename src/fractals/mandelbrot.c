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

void		init_mandelbrot(t_data *data)
{
	data->draw_func = mandelbrot;
	set_complex(&data->left_corner, -2, -1.5);
	set_complex(&data->right_corner, 1, 1.5);
	update_step(data);
}

int			cardioid_test(t_complex *num)
{
	double q;

	q = (num->real - 0.25) * (num->real - 0.25) + (num->imag * num->imag);
	return ((q * (q + (num->real - 0.25))) <
										(0.25 * num->imag * num->imag));
}

int			bulb_test(t_complex *num)
{
	return ((pow(num->real + 1, 2) + pow(num->imag, 2)) < 0.0625);
}

unsigned	mandelbrot(t_data *data, t_complex *start_num)
{
	t_complex	num;
	t_complex	num_squared;
	double		tmp;
	unsigned	iteration;

	set_complex(&num, start_num->real, start_num->imag);
	if (cardioid_test(start_num) || bulb_test(start_num))
		return (data->iterations);
	iteration = 0;
	while (iteration < data->iterations)
	{
		set_complex(&num_squared, num.real * num.real, num.imag * num.imag);
		if (num_squared.real + num_squared.imag > 4)
		{
			set_complex(start_num, num.real, num.imag);
			return (iteration);
		}
		tmp = num_squared.real - num_squared.imag + start_num->real;
		num.imag = num.real * num.imag * 2 + start_num->imag;
		num.real = tmp;
		iteration++;
	}
	return (iteration);
}
