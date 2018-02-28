/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:48:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 15:48:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_POOL_H
# define THREAD_POOL_H

# include <pthread.h>
# include "libft.h"
# include "constants.h"
# include "structs.h"

t_threads_pool *init_threads_pool(void);
t_threads_data *init_threads_data(t_data *data);

#endif
