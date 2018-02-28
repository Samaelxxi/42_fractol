/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:48:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 15:48:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_pool.h"

t_threads_pool	*init_threads_pool(void)
{
	t_threads_pool *pool;

	pool = malloc(sizeof(t_threads_pool));
	pool->threads_pool = malloc(sizeof(t_threads_pool) * OTHER_THREAD_NUM);
	pool->threads_num = OTHER_THREAD_NUM;
	return (pool);
}

t_threads_data	*init_threads_data(t_data *data)
{
	t_threads_data	*threads_data;
	int				idx;

	threads_data = malloc(sizeof(t_threads_data) * ALL_THREADS_NUM);
	idx = 0;
	while (idx < ALL_THREADS_NUM)
	{
		(threads_data[idx]).start = WIN_H / ALL_THREADS_NUM * idx;
		(threads_data[idx]).end = WIN_H / ALL_THREADS_NUM * (idx + 1);
		(threads_data[idx]).data = data;
		idx++;
	}
	(threads_data[idx - 1]).end = WIN_H;
	return (threads_data);
}
