/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:01:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/09 00:01:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_julia(t_data *data)
{
	data->draw_func = julia;
	set_complex(&data->left_corner, -1.5, -1.5);
	set_complex(&data->right_corner, 1.5, 1.5);
	set_complex(&data->julia_num, -0.4, 0.6);
	update_step(data);
}

unsigned	julia(t_data *data, t_complex *start_num)
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
		tmp = num_squared.real - num_squared.imag + data->julia_num.real;
		num.imag = num.real * num.imag * 2 + data->julia_num.imag;
		num.real = tmp;
		iteration++;
	}
	return (iteration);
}
