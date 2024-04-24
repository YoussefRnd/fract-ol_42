/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:08:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/24 16:58:58 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	handle_error(void)
{
	ft_putstr_fd("Error: Malloc failed\n", 2);
	exit(EXIT_FAILURE);
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init(WIDTH, HEIGHT, fractal->name, false);
	if (!fractal->mlx_ptr)
		handle_error();
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4.0;
	fractal->max_iter = 42;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_ptr, &key_handler, fractal);
	mlx_close_hook(fractal->mlx_ptr, &close_window, fractal);
	mlx_scroll_hook(fractal->mlx_ptr, &scroll_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	init_mlx(fractal);
	fractal->img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_terminate(fractal->mlx_ptr);
		handle_error();
	}
	data_init(fractal);
	events_init(fractal);
}
