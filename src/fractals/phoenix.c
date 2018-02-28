/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:47:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/10 14:47:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_phoenix(t_data *data)
{
	data->draw_func = phoenix;
	set_complex(&data->left_corner, -1.5, -1.5);
	set_complex(&data->right_corner, 1.5, 1.5);
	update_step(data);
}

unsigned	phoenix(t_data *data, t_complex *start_num)
{
	t_complex	num;
	t_complex	num_squared;
	t_complex	num_prev;
	t_complex	num_next;
	unsigned	iteration;

	set_complex(&num_prev, 0, 0);
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
		num_next.real = num_squared.real - num_squared.imag + 0.56667 +
				(-0.5 * num_prev.real);
		num_next.imag = num.real * num.imag * 2 + (-0.5 * num_prev.imag);
		set_complex(&num_prev, num.real, num.imag);
		set_complex(&num, num_next.real, num_next.imag);
		iteration++;
	}
	return (iteration);
}
