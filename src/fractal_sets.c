/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:43:38 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/15 18:55:30 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	julia(t_fractal *fractal, t_complex *z, t_complex *c)
{
	int	i;

	i = 0;
	while (i < fractal->max_iter)
	{
		*z = sum_complex(square_complex(*z), *c);
		if ((z->real * z->real + z->im * z->im) > 4)
			break ;
		i++;
	}
	return (i);
}

int	mandelbrot(t_fractal *fractal, t_complex *z, t_complex *c)
{
	int i;
	
	z->real = c->real;
	z->im = c->im;
	i = 0;
	while (i < fractal->max_iter)
	{
		*z = sum_complex(square_complex(*z), *c);
		if ((z->real * z->real + z->im * z->im) > 4)
			break ;
		i++;
	}
	return (i);
}