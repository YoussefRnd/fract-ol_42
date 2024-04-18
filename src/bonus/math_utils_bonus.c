/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:17:06 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/18 12:57:00 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol_bonus.h"

double	scale(double value, double new_min, double new_max, double old_max)
{
	return (value * (new_max - new_min) / old_max + new_min);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.im = a.im + b.im;
	return (result);
}

t_complex	square_complex(t_complex a)
{
	t_complex	result;

	result.real = a.real * a.real - a.im * a.im;
	result.im = 2 * a.real * a.im;
	return (result);
}
