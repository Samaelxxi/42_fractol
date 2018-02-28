/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:09:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 17:09:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	shift_screen2(int key, t_data *data, t_complex diff)
{
	if (key == LEFT_ARROW_KEY)
	{
		data->left_corner.real -= diff.real / 10;
		data->right_corner.real -= diff.real / 10;
	}
	if (key == RIGHT_ARROW_KEY)
	{
		data->left_corner.real += diff.real / 10;
		data->right_corner.real += diff.real / 10;
	}
	if (key == DOWN_ARROW_KEY)
	{
		data->left_corner.imag += diff.imag / 10;
		data->right_corner.imag += diff.imag / 10;
	}
	if (key == UP_ARROW_KEY)
	{
		data->left_corner.imag -= diff.imag / 10;
		data->right_corner.imag -= diff.imag / 10;
	}
}

void	shift_screen(int key, t_data *data)
{
	t_complex diff;

	diff.real = (data->right_corner.real - data->left_corner.real);
	diff.imag = (data->right_corner.imag - data->left_corner.imag);
	shift_screen2(key, data, diff);
	render_screen(data);
}

void	change_iterations(int key, t_data *data)
{
	if (key == PLUS_KEY)
		data->iterations += 5;
	else if (key == MINUS_KEY && data->iterations - 5 >= 1)
		data->iterations -= 5;
	render_screen(data);
}

void	change_fractol(int key, t_data *data)
{
	if (key == MANDELBROT_KEY)
		init_mandelbrot(data);
	else if (key == JULIA_KEY)
		init_julia(data);
	else if (key == BURNING_SHIP_KEY)
		init_burning_ship(data);
	else if (key == TRICORN_KEY)
		init_tricorn(data);
	else if (key == PHOENIX_KEY)
		init_phoenix(data);
	else if (key == MANDELSQUAD_KEY)
		init_mandelquad(data);
	render_screen(data);
}

void	change_colorset(int key, t_data *data)
{
	if (key == COLOR_SET1)
		init_colorset1(data);
	else if (key == COLOR_SET2)
		init_colorset2(data);
	else if (key == COLOR_SET3)
		init_colorset3(data);
	render_screen(data);
}
