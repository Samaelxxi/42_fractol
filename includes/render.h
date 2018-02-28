/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:56:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 18:56:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "structs.h"
# include <mlx.h>
# include "libft.h"
# include "constants.h"
# include "fractol.h"

void		clear_screen(t_data *data);
void		wait_threads_execution(t_threads_pool *threads_pool);
void		run_draw_func_using_threads(t_data *data);
void		*thread_wrap(void *vdata);

#endif
