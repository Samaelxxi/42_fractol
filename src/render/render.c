/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:55:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 18:55:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void		render_screen(t_data *data)
{
	clear_screen(data);
	run_draw_func_using_threads(data);
	wait_threads_execution(data->threads_pool);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void		clear_screen(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_memset(data->img_data->img, 0, WIN_W * WIN_H * 4);
}

void		wait_threads_execution(t_threads_pool *threads_pool)
{
	unsigned idx;

	idx = 0;
	while (idx < threads_pool->threads_num)
		pthread_join(threads_pool->threads_pool[idx++], NULL);
}

void		run_draw_func_using_threads(t_data *data)
{
	unsigned idx;

	idx = 0;
	while (idx < data->threads_pool->threads_num)
	{
		pthread_create(&(data->threads_pool->threads_pool[idx]), NULL,
						thread_wrap, data->threads_data + idx);
		idx++;
	}
	draw_loop(data->threads_data + idx);
}

void		*thread_wrap(void *vdata)
{
	t_threads_data	*threads_data;

	threads_data = (t_threads_data*)vdata;
	draw_loop(threads_data);
	pthread_exit(NULL);
}
