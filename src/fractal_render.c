/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:45:23 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/15 18:35:22 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	return ((red << 16) | (green << 8) | blue);
}

int	which_fractal_set(t_fractal *fractal, t_complex *z, t_complex *c)
{
	if (ft_strncmp(fractal->name, "julia", 5) == 0)
		return (julia(fractal, z, &fractal->julia));
	else if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		return (mandelbrot(fractal, z, c));
	return (0);
}

void	draw_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	int			i;

	z.real = (fractal->zoom * scale(x, -2, 2, WIDTH)) + fractal->shift_x;
	z.im = (fractal->zoom * scale(y, 2, -2, HEIGHT)) + fractal->shift_y;
	i = which_fractal_set(fractal, &z, &z);
	if (i == fractal->max_iter)
		mlx_put_pixel(fractal->img, x, y, BLUE);
	else
		mlx_put_pixel(fractal->img, x, y, bernstein_color(fractal, i));
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(fractal->mlx_ptr, fractal->img, 0, 0);
}
