/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:22:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/02/04 15:22:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			all_flags_valid(int argc, char **argv)
{
	int		idx;
	char	*arg;

	idx = 1;
	while (idx < argc)
	{
		arg = argv[idx++];
		if (arg[0] != '-' || !char_in_str(arg[1], FRACTOL_FLAGS) ||
				arg[2] != '\0')
			return (0);
	}
	return (1);
}

void		print_usage(void)
{
	ft_printf("usage: ./fractol <fractol flag 1> <fractol flag 2> ...\n"
"flags:\n"
"\t-m mandelbrot\n"
"\t-j julia\n"
"\t-b burning ship\n"
"\t-t tricorn\n"
"\t-p phoenix\n"
"\t-q mandelquad\n");
}

void		start_render(char *arg)
{
	t_data *data;

	data = init_world(arg);
	render_screen(data);
	mlx_loop(data->mlx);
}

void		draw_fractals(int argc, char **argv)
{
	int		arg_idx;
	pid_t	pid;

	arg_idx = 2;
	while (arg_idx < argc)
	{
		pid = fork();
		if (pid == 0)
			start_render(argv[arg_idx]);
		arg_idx++;
	}
	start_render(argv[1]);
}

int			main(int argc, char **argv)
{
	if (argc < 2 || !all_flags_valid(argc, argv))
	{
		print_usage();
		exit(0);
	}
	draw_fractals(argc, argv);
	return (0);
}
