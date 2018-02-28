/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:34:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 15:34:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define PUT_PIXEL(img, x, y, s, color) (img)[(x) + (y) * (s) / 4] = (color)

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include "structs.h"
# include <mlx.h>
# include "constants.h"
# include "complex.h"
# include "thread_pool.h"
# include "libft.h"
# include <math.h>
# include "events.h"

void		update_step(t_data *data);
void		render_screen(t_data *data);
t_data		*init_world(char *arg);
void		print_usage(void);
void		draw_loop(t_threads_data *threads_data);

void		init_mandelbrot(t_data *data);
unsigned	mandelbrot(t_data *data, t_complex *start_num);

void		init_julia(t_data *data);
unsigned	julia(t_data *data, t_complex *start_num);

void		init_burning_ship(t_data *data);
unsigned	burning_ship(t_data *data, t_complex *start_num);

void		init_tricorn(t_data *data);
unsigned	tricorn(t_data *data, t_complex *start_num);

void		init_phoenix(t_data *data);
unsigned	phoenix(t_data *data, t_complex *start_num);

void		init_mandelquad(t_data *data);
unsigned	mandelquad(t_data *data, t_complex *start_num);

void		clear_and_exit(t_data *data);
int			get_color(t_data *data, unsigned iterations, t_complex num);
int			psycho_func(void *param);

void		init_colorset1(t_data *data);
void		init_colorset2(t_data *data);
void		init_colorset3(t_data *data);

#endif
