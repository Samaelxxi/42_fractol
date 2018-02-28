/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:34:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 15:34:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

struct s_data;

typedef struct		s_threads_data
{
	struct s_data	*data;
	int				start;
	int				end;
}					t_threads_data;

typedef struct		s_threads_pool
{
	pthread_t		*threads_pool;
	unsigned		threads_num;
}					t_threads_pool;

typedef struct		s_img
{
	int				*img;
	int				s;
	int				bits_per_pixels;
	int				endian;
}					t_img;

typedef struct		s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct		s_color_attrs
{
	double			frequence;
	double			phase;
	int				center;
	int				delta;
}					t_color_attrs;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	t_img			*img_data;
	unsigned		iterations;
	t_complex		left_corner;
	t_complex		right_corner;
	t_complex		step;
	t_complex		julia_num;
	t_threads_pool	*threads_pool;
	t_threads_data	*threads_data;
	unsigned		(*draw_func)(struct s_data*, t_complex*);
	t_color_attrs	palette[3];
	int				psycho;
}					t_data;

#endif
