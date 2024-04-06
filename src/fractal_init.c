/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:08:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/06 03:56:02 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	fractal->escape_value = 4;
	fractal->max_iter = 42;
}

void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->win_ptr, &key_press_handler, NULL);
}

void	fractal_init(t_fractal *fractal)
{
	init_mlx(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_delete_image(fractal->mlx_ptr, fractal->img.img_ptr);
		// free(fractal->mlx_ptr);
		handle_error();
	}
	data_init(fractal);
}
