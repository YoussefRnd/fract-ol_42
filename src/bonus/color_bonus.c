/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:01:02 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/23 16:33:47 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol_bonus.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	bernstein_color(t_fractal *fractal, int iterations)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	long double		ni;

	ni = (long double)iterations / (long double)fractal->max_iter;
	red = 9.0 * (1.0 - ni) * pow(ni, 3.0) * 255.0;
	green = 15.0 * pow((1.0 - ni), 2.0) * pow(ni, 2.0) * 255.0;
	blue = 8.5 * pow((1.0 - ni), 3.0) * ni * 255.0;
	return (get_rgba(red, green, blue, 255));
}
