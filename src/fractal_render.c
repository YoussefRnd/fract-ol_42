/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:45:23 by yboumlak          #+#    #+#             */
/*   Updated: 2024/04/14 17:29:08 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	int			i;

	z.real = (fractal->zoom * scale(x, -2, 2, WIDTH)) + fractal->shift_x;
	z.im = (fractal->zoom * scale(y, 2, -2, HEIGHT)) + fractal->shift_y;
	i = mandelbrot_julia(fractal, &z);
	if (i == fractal->max_iter)
		mlx_put_pixel(fractal->img, x, y, BLUE);
	else
		mlx_put_pixel(fractal->img, x, y, scale(i, BLACK, WHITE,
				fractal->max_iter));
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
