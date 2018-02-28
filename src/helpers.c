/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:02:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 19:02:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		clear_and_exit(t_data *data)
{
	free(data->threads_pool->threads_pool);
	free(data->threads_pool);
	free(data->threads_data);
	free(data->img_data);
	free(data);
	exit(0);
}

void		update_step(t_data *data)
{
	double real_step;
	double imag_step;

	real_step = (data->right_corner.real - data->left_corner.real)
				/ WIN_W;
	imag_step = (data->right_corner.imag - data->left_corner.imag)
				/ WIN_H;
	set_complex(&data->step, real_step, imag_step);
}
