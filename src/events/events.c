/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 04:49:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/09 04:49:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int		mouse_down(int button, int x, int y, void *param)
{
	if (button == LEFT_CLICK)
		mouse_action(MOUSE_DOWN, x, y, param);
	else if (button == SCROLL_UP || button == SCROLL_DOWN)
		mouse_scroll(button, x, y, param);
	return (0);
}

int		mouse_up(int button, int x, int y, void *param)
{
	if (button == LEFT_CLICK)
		mouse_action(MOUSE_UP, x, y, param);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_data *data;

	data = param;
	if (data->draw_func == julia)
		if (x > 0 && x < WIN_W && y > 0 && y < WIN_H)
			mouse_action(3, x, y, param);
	return (0);
}

int		key_event(int key, void *param)
{
	t_data *data;

	data = param;
	if (key == ESC_KEY)
		clear_and_exit(data);
	else if (key == LEFT_ARROW_KEY || key == RIGHT_ARROW_KEY
			|| key == UP_ARROW_KEY || key == DOWN_ARROW_KEY)
		shift_screen(key, data);
	else if (key == PLUS_KEY || key == MINUS_KEY)
		change_iterations(key, data);
	else if (key == MANDELBROT_KEY || key == JULIA_KEY || key == TRICORN_KEY
			|| key == BURNING_SHIP_KEY || key == PHOENIX_KEY
			|| key == MANDELSQUAD_KEY)
		change_fractol(key, data);
	else if (key == COLOR_SET1 || key == COLOR_SET2 || key == COLOR_SET3)
		change_colorset(key, data);
	else if (key == PSYCHO_KEY)
		data->psycho = (data->psycho + 1) % 2;
	return (0);
}
