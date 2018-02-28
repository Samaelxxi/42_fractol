/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:09:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 17:09:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fractol.h"

int		key_event(int key, void *param);
int		mouse_scroll(int idk, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		mouse_down(int button, int x, int y, void *param);
int		mouse_up(int button, int x, int y, void *param);
int		mouse_action(int action, int x, int y, t_data *data);
void	shift_screen(int key, t_data *data);
void	change_iterations(int key, t_data *data);
void	change_fractol(int key, t_data *data);
void	change_colorset(int key, t_data *data);

# define PLUS_KEY 69
# define MINUS_KEY 78
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define UP_ARROW_KEY 126
# define DOWN_ARROW_KEY 125
# define ESC_KEY 53
# define COLOR_SET1 83
# define COLOR_SET2 84
# define COLOR_SET3 85
# define PSYCHO_KEY 35

# define MOUSE_DOWN 1
# define MOUSE_UP 2
# define MOUSE_MOVE 3
# define LEFT_CLICK 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define MANDELBROT_KEY 89
# define JULIA_KEY 91
# define BURNING_SHIP_KEY 92
# define TRICORN_KEY 86
# define PHOENIX_KEY 87
# define MANDELSQUAD_KEY 88

#endif
