/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:00:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 19:00:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "fractol");
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->img_data = malloc(sizeof(t_img));
	data->img_data->img = (int*)mlx_get_data_addr(data->img,
						&(data->img_data->bits_per_pixels),
						&(data->img_data->s), &(data->img_data->endian));
}

void		init_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 5, key_event, data);
	mlx_hook(data->win, 4, 0, mouse_scroll, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_hook(data->win, 4, 0, mouse_down, data);
	mlx_hook(data->win, 5, 0, mouse_up, data);
	mlx_loop_hook(data->mlx, psycho_func, data);
}

void		init_threads(t_data *data)
{
	data->threads_pool = init_threads_pool();
	data->threads_data = init_threads_data(data);
}

void		init_fractol(t_data *data, char *arg)
{
	if (ft_strequ("-m", arg))
		init_mandelbrot(data);
	else if (ft_strequ("-t", arg))
		init_tricorn(data);
	else if (ft_strequ("-j", arg))
		init_julia(data);
	else if (ft_strequ("-b", arg))
		init_burning_ship(data);
	else if (ft_strequ("-p", arg))
		init_phoenix(data);
	else if (ft_strequ("-q", arg))
		init_mandelquad(data);
}

t_data		*init_world(char *arg)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	init_mlx(data);
	init_threads(data);
	init_fractol(data, arg);
	init_hooks(data);
	init_colorset1(data);
	data->iterations = INIT_ITERATIONS;
	data->psycho = 0;
	return (data);
}
