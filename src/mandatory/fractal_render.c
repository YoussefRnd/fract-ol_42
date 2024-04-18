/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:45:23 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/18 11:20:00 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	which_fractal_set(t_fractal *fractal, t_complex *coord)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
		return (julia(fractal, coord));
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		return (mandelbrot(fractal, coord));
	return (0);
}

void	fractal_render(t_fractal *fractal)
{
	t_complex	coord;
	int			i;

	i = 0;
	coord.im = 0;
	while (coord.im < HEIGHT)
	{
		coord.real = 0;
		while (coord.real < WIDTH)
		{
			i = which_fractal_set(fractal, &coord);
			if (i == fractal->max_iter)
				mlx_put_pixel(fractal->img, coord.real, coord.im, get_rgba(0, 0,
						0, 255));
			else
				mlx_put_pixel(fractal->img, coord.real, coord.im,
					bernstein_color(fractal, i));
			coord.real++;
		}
		coord.im++;
	}
	mlx_image_to_window(fractal->mlx_ptr, fractal->img, 0, 0);
}
