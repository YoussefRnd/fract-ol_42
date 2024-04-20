/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:43:38 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/19 22:41:37 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol_bonus.h"

int	calculate_fractal(t_fractal *fractal, t_complex z, t_complex c)
{
	int	i;

	i = 0;
	while (i < fractal->max_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real + z.im * z.im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	julia(t_fractal *fractal, t_complex *coord)
{
	t_complex	z;
	t_complex	c;

	z.real = (fractal->zoom * scale(coord->real, fractal->x_min, fractal->x_max,
				WIDTH)) + fractal->shift_x;
	z.im = (fractal->zoom * scale(coord->im, fractal->y_max, fractal->y_min,
				HEIGHT)) + fractal->shift_y;
	c.real = fractal->julia.real;
	c.im = fractal->julia.im;
	return (calculate_fractal(fractal, z, c));
}

int	mandelbrot(t_fractal *fractal, t_complex *coord)
{
	t_complex	z;
	t_complex	c;

	z.real = 0;
	z.im = 0;
	c.real = (fractal->zoom * scale(coord->real, fractal->x_min, fractal->x_max,
				WIDTH)) + fractal->shift_x;
	c.im = (fractal->zoom * scale(coord->im, fractal->y_max, fractal->y_min,
				HEIGHT)) + fractal->shift_y;
	return (calculate_fractal(fractal, z, c));
}
