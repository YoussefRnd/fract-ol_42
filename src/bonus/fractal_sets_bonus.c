/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:43:38 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/21 20:48:53 by yboumlak         ###   ########.fr       */
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
		if ((z.real * z.real + z.im * z.im) > fractal->escape_value)
			break ;
		i++;
	}
	return (i);
}

int	julia(t_fractal *fractal, t_complex *coord)
{
	t_complex	z;
	t_complex	c;

	z.real = scale(coord->real, fractal->x_min, fractal->x_max, WIDTH)
		+ fractal->shift_x;
	z.im = scale(coord->im, fractal->y_min, fractal->y_max, HEIGHT)
		+ fractal->shift_y;
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
	c.real = scale(coord->real, fractal->x_min, fractal->x_max, WIDTH)
		+ fractal->shift_x;
	c.im = scale(coord->im, fractal->y_min, fractal->y_max, HEIGHT)
		+ fractal->shift_y;
	return (calculate_fractal(fractal, z, c));
}

int	burning_ship(t_fractal *fractal, t_complex *coord)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.real = 0;
	z.im = 0;
	c.real = scale(coord->real, fractal->x_min, fractal->x_max, WIDTH)
		+ fractal->shift_x;
	c.im = scale(coord->im, fractal->y_min, fractal->y_max, HEIGHT)
		+ fractal->shift_y;
	while (i < fractal->max_iter)
	{
		z.real = fabs(z.real);
		z.im = fabs(z.im);
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real + z.im * z.im) > fractal->escape_value)
			break ;
		i++;
	}
	return (i);
}
