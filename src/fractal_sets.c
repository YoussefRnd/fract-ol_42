/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:43:38 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/14 04:00:28 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mandelbrot_julia(t_fractal *fractal, t_complex *z)
{
	t_complex	c;
	int	i;

	if (fractal->is_julia)
	{
		c.real = fractal->julia.real;
		c.im = fractal->julia.im;
	}
	else
	{
		c.real = z->real;
		c.im = z->im;
	}
	i = 0;
	while (i < fractal->max_iter)
	{
		*z = sum_complex(square_complex(*z), c);
		if (z->real * z->real + z->im * z->im > fractal->escape_value)
			return (i);
		i++;
	}
	return (i);
}