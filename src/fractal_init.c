/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:08:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/05 04:22:48 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	handle_error(void)
{
	ft_putstr_fd("Error: Malloc failed\n", 2);
	exit(EXIT_FAILURE);
}

void	mlx_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		handle_error();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->win_ptr)
	{
		// mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		handle_error();
	}
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iter = 100;
}

void	fractal_init(t_fractal *fractal)
{
	mlx_init(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		// mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		handle_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_size,
			&fractal->img.endian);
	data_init(fractal);
}
