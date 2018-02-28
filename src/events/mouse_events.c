/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:55:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/05 10:55:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "float.h"

void	update_bounds(t_data *data, t_complex *left_corner_shift,
					t_complex *right_corner_shift, int direction)
{
	data->left_corner.real += left_corner_shift->real * direction;
	data->right_corner.real -= right_corner_shift->real * direction;
	data->left_corner.imag += left_corner_shift->imag * direction;
	data->right_corner.imag -= right_corner_shift->imag * direction;
}

void	zoom(t_data *data, int x, int y, int dir)
{
	t_complex left_corner_shift;
	t_complex right_corner_shift;

	left_corner_shift.real = (data->right_corner.real
							- data->left_corner.real) / 10;
	right_corner_shift.real = left_corner_shift.real;
	left_corner_shift.imag = (data->right_corner.imag
							- data->left_corner.imag) / 10;
	right_corner_shift.imag = left_corner_shift.imag;
	left_corner_shift.real *= (1 - ((WIN_W - x) / (float)WIN_W));
	right_corner_shift.real *= ((WIN_W - x) / (float)WIN_W);
	left_corner_shift.imag *= (1 - ((WIN_H - y) / (float)WIN_H));
	right_corner_shift.imag *= ((WIN_H - y) / (float)WIN_H);
	update_bounds(data, &left_corner_shift, &right_corner_shift, dir);
	update_step(data);
	render_screen(data);
}

int		mouse_scroll(int button, int x, int y, void *param)
{
	t_data *data;

	data = param;
	if (button == SCROLL_UP)
		zoom(data, x, y, ZOOM_IN);
	else if (button == SCROLL_DOWN)
		zoom(data, x, y, ZOOM_OUT);
	return (0);
}

int		mouse_action(int action, int x, int y, t_data *data)
{
	static int		mouse_down = 0;
	static t_point	prev_mouse;

	if (action == MOUSE_DOWN)
	{
		mouse_down = 1;
		prev_mouse.x = x;
		prev_mouse.y = y;
	}
	else if (action == MOUSE_UP)
		mouse_down = 0;
	else if (action == MOUSE_MOVE)
	{
		if (mouse_down && data->draw_func == julia)
		{
			set_complex(&(data->julia_num),
						-0.5 + (x / (float)WIN_W) * 1,
						0.5 + (y / (float)WIN_W) * 1);
			render_screen(data);
		}
	}
	return (0);
}
